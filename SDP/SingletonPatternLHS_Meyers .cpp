#include <iostream>
using namespace std;

class Singleton
{
private:
    Singleton() {}
public:
    static Singleton& getInstance()
    {
        // 局部static：第一次调用才初始化，线程安全
        static Singleton ins;
        return ins;
    }

    void show()
    {
        cout << "懒汉单例 Meyers" << endl;
    }
};

int main()
{
    Singleton::getInstance().show();
    return 0;
}