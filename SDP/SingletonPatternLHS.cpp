#include <iostream>
using namespace std;

// 懒汉式第一次调用才初始化，延迟加载（instance只是空指针，调用getInstance才会实例化）
// 需要处理线程安全（new 不是原子操作 多线程同时走到判断空这里，会一起进去创建对象）

class Singleton
{
public:
    static Singleton* getInstance()
    {
        // 用到才创建，懒加载
        if (instance == nullptr)
        {
            instance = new Singleton();
        }
        return instance;
    }

    void show()
    {
        cout << "懒汉单例" << endl;
    }

private:
    Singleton() {}
    static Singleton* instance;

};

// 初始化为空指针
Singleton* Singleton::instance = nullptr;

int main()
{
    Singleton::getInstance()->show();
    return 0;
}