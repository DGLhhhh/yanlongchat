#pragma once
#include "const.h"

class HttpConnection : public std::enable_shared_from_this<HttpConnection>
{
	friend class LogicSystem;
public:
	// HttpConnection(tcp::socket socket);
	HttpConnection(boost::asio::io_context& ioc);
	void Start();
	tcp::socket& GetSocket()
	{
		return _socket;
	}

private:
	void CheckDeadline();   // 定时器判断请求是否超时
	void WriteResponse();   // 回应客户端
	void HandleReq();       // 处理请求
	void PreParseGetParam(); // 处理url输入字符
	tcp::socket  _socket;
	// The buffer for performing reads.
	beast::flat_buffer  _buffer{ 8192 };   // 接收数据

	// The request message.
	http::request<http::dynamic_body> _request;  // 接收请求

	// The response message.
	http::response<http::dynamic_body> _response;  // 回复请求

	// The timer for putting a deadline on connection processing.
	net::steady_timer deadline_{
		_socket.get_executor(), std::chrono::seconds(60)
	};

	// 处理url，_get_url是输入url字符，_get_params存解析后的参数对
	std::string _get_url;
	std::unordered_map<std::string, std::string> _get_params;
};

