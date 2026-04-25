#ifndef SINGLETON_H
#define SINGLETON_H
#include <global.h>

// 把该单例类当作基类

template <typename T>
class Singleton{
protected:
    Singleton() = default;
    Singleton(const Singleton<T>&) = delete;     // 把拷贝构造删除
    Singleton& operator = (const Singleton<T>& st) = delete;  // 把拷贝赋值删除
    static std::shared_ptr<T> _instance;
public:
    static std::shared_ptr<T> GetInstance(){
        // 单例模板，只会调用一次初始化？？
        static std::once_flag s_flag;
        std::call_once(s_flag, [&](){
            _instance = std::shared_ptr<T>(new T); // 思考：为什么用new初始化，而不是make_shared？？
        });

        return _instance;
    }

    void PrintAddress(){
        std::cout << _instance.get() << std::endl;
    }

    ~Singleton(){
        std::cout << "this is singleton destruct" << std::endl;
    }
};

template <typename T>
std::shared_ptr<T> Singleton<T>::_instance = nullptr;

#endif // SINGLETON_H
