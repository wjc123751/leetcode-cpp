#include <iostream>
using namespace std;

// 饿汉式在类加载时直接初始化实例（静态成员变量），调用速度快（直接返回创建好的实例），天然线程安全（getInstance只返回，没有赋值修改操作）。

class Singleton
{
public:
    // 3. 对外获取实例接口
    static Singleton& getInstance()
    {
        return instance;
    }

    void test()
    {
        cout << "饿汉单例调用成功" << endl;
    }
    
private:
    // 1. 私有构造，禁止外部new
    Singleton() {}
    // 2. 静态全局唯一实例
    static Singleton instance;

};

// 类外初始化静态对象（程序启动直接创建）
Singleton Singleton::instance;

int main()
{
    Singleton::getInstance().test();
    return 0;
}