#pragma once
#include <grpcpp/grpcpp.h>
#include "message.grpc.pb.h"
#include "const.h"
#include "Singleton.h"
using grpc::Channel;
using grpc::Status;
using grpc::ClientContext;  // 上下文

using message::GetVarifyReq;
using message::GetVarifyRsp;
using message::VarifyService;

class RPConPool
{
public:
	RPConPool(size_t poolsize, std::string host, std::string port)
	: poolSize_(poolsize), host_(host), port_(port), b_stop_(false){
		for (size_t i = 0; i < poolSize_; ++i)
		{
			std::shared_ptr<Channel> channel = grpc::CreateChannel(host_ + ":" + port_, grpc::InsecureChannelCredentials());
			// 【提问】为什么这里push能把VarifyService::NewStub(channel)加进去？？？
			connections_.push(VarifyService::NewStub(channel));
		}
	}
	~RPConPool()
	{
		// 先加锁
		std::lock_guard<std::mutex> lock(mutex_);
		Close(); // 原子变量b_stop_设为true
		// 然后把所有连接关闭
		while (!connections_.empty())
		{
			connections_.pop();
		}
	}

	void Close()
	{
		b_stop_ = true;
		cond_.notify_all();
	}

	std::unique_ptr<VarifyService::Stub> getConnection()
	{
		std::unique_lock<std::mutex> lock(mutex_);   // 这里不能用std::lock_guard，不然wait报错
		cond_.wait(lock, [this] {
			if (b_stop_) {
				return true;
			}
			return !connections_.empty();
			});

		if (b_stop_) {
			return nullptr;
		}
		auto context =  std::move(connections_.front());
		connections_.pop();
		return context;
	}

	void returnConnection(std::unique_ptr< VarifyService::Stub> context)
	{
		std::lock_guard<std::mutex> lock(mutex_);
		if (b_stop_) {
			return;
		}

		connections_.push(std::move(context));
		cond_.notify_one();
	}
private:
	std::atomic<bool> b_stop_;
	size_t poolSize_;
	std::string host_;
	std::string port_;
	// 这里的队列后期自己去写其他的，优化？？？ 比如头尾加锁，效率高？？？
	std::queue<std::unique_ptr<VarifyService::Stub>> connections_;
	std::condition_variable cond_;
	std::mutex mutex_;
};

class VerifyGrpcClient :public Singleton<VerifyGrpcClient>
{
	friend class Singleton<VerifyGrpcClient>;
public:

	GetVarifyRsp GetVarifyCode(std::string email) {
		ClientContext context;
		GetVarifyRsp reply;
		GetVarifyReq request;
		request.set_email(email);
		auto stub = pool_->getConnection();
		Status status = stub->GetVarifyCode(&context, request, &reply);

		if (status.ok()) {
			pool_->returnConnection(std::move(stub));
			return reply;
		}
		else {
			pool_->returnConnection(std::move(stub));
			reply.set_error(ErrorCodes::RPCFailed);
			return reply;
		}
	}

private:
	//VerifyGrpcClient() {
	//	/*std::shared_ptr<Channel> channel = grpc::CreateChannel("127.0.0.1:50051", grpc::InsecureChannelCredentials());
	//	stub_ = VarifyService::NewStub(channel);*/
	//}
	// std::unique_ptr<VarifyService::Stub> stub_;  // 相当于信使。

	VerifyGrpcClient();

	std::unique_ptr<RPConPool> pool_;
};
