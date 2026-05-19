#include <iostream>
#include <vector>
using namespace std;

// 定义对象间一对多依赖关系(1 个主题对象，容器存多个观察者对象)，当一个对象状态改变时（主题自身数据发生变更，就是状态改变）
// 所有依赖它的对象都会收到通知（遍历全部依赖它的观察者，全员收到通知），自动更新（观察者提前写好update更新逻辑，被调用时自动执行更新）

// 抽象观察者
class Observer
{
public:
    virtual void update() = 0;
    virtual ~Observer(){}
};

// 抽象主题（被观察者）
class Subject
{
protected:
    vector<Observer*> obsList; // 存放所有观察者
public:
    // 添加观察者
    void attach(Observer* o)
    {
        obsList.push_back(o);
    }
    // 移除观察者
    void detach(Observer* o)
    {
        for (auto it = obsList.begin(); it != obsList.end();)
        {
            if (*it == o)
                it = obsList.erase(it);
            else
                it++;
        }
    }
    // 群发通知：通知所有观察者更新
    void notify()
    {
        for (auto o : obsList)
        {
            o->update();
        }
    }
};

// 具体主题
class ConcreteSubject : public Subject
{
private:
    int state;
public:
    void setState(int s)
    {
        state = s;
        // 状态改变 主动发通知
        notify();
    }
    int getState()
    {
        return state;
    }
};

// 具体观察者A
class ConcreteObserverA : public Observer
{
private:
    ConcreteSubject* sub;
public:
    ConcreteObserverA(ConcreteSubject* s) : sub(s){}
    void update() override
    {
        cout << "观察者A收到状态：" << sub->getState() << endl;
    }
};

// 具体观察者B
class ConcreteObserverB : public Observer
{
private:
    ConcreteSubject* sub;
public:
    ConcreteObserverB(ConcreteSubject* s) : sub(s){}
    void update() override
    {
        cout << "观察者B收到状态：" << sub->getState() << endl;
    }
};

// 测试
int main()
{
    ConcreteSubject sub;

    ConcreteObserverA obA(&sub);
    ConcreteObserverB obB(&sub);

    // 注册观察者
    sub.attach(&obA);
    sub.attach(&obB);

    // 修改主题状态，自动推送通知
    sub.setState(100);
    sub.setState(200);

    return 0;
}