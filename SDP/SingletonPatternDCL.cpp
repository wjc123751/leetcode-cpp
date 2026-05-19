#include <iostream>
#include <mutex>
using namespace std;

// DCL就是线程安全的懒汉式

class Singleton
{
private:
    Singleton() = default;
    static Singleton* instance;
    static mutex mtx;

public:
    static Singleton* getInstance()
    {
        // 第一层判空：避免频繁加锁
        if (!instance)
        {
            lock_guard<mutex> lock(mtx);
            // 第二层判空：防止多线程重复创建
            if (!instance)
            {
                instance = new Singleton();
            }
        }
        return instance;
    }

    void show()
    {
        cout << "懒汉单例 DCL" << endl;
    }
};

Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main()
{
    Singleton::getInstance()->show();
    return 0;
}