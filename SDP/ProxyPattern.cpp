#include <iostream>
using namespace std;

// 为其他对象RealSubject提供一种代理，以控制对这个对象的访问（代理可以访问，客户端不能访问）

// 抽象主题接口
class Subject
{
public:
    virtual void request() = 0;
    virtual ~Subject(){}
};

// 真实实体对象
class RealSubject : public Subject
{
public:
    void request() override
    {
        cout << "真实对象执行业务操作" << endl;
    }
};

// 代理类
class Proxy : public Subject
{
private:
    RealSubject* real; // 持有真实对象
public:
    Proxy()
    {
        real = new RealSubject();
    }
    // 预处理
    void before()
    {
        cout << "代理：权限校验、日志记录" << endl;
    }
    // 后置处理
    void after()
    {
        cout << "代理：收尾处理" << endl;
    }

    void request() override
    {
        before();        // 代理前置增强
        real->request(); // 调用真实对象
        after();         // 代理后置增强
    }
};

// 客户端调用
int main()
{
    Subject* sub = new Proxy();
    sub->request();
    delete sub;
    return 0;
}