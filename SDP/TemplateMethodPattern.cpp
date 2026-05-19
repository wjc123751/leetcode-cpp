#include <iostream>
using namespace std;

// 定义算法骨架，把步骤延迟到子类实现，固定流程，可变步骤子类重写

// 抽象父类：定义模板骨架
class AbstractClass
{
public:
    // 模板方法：固定整体执行流程（骨架不可重写）
    void templateMethod()
    {
        step1();
        step2();
        step3();
    }
    virtual ~AbstractClass(){}
    
protected:
    // 固定步骤
    virtual void step1()
    {
        cout << "执行固定步骤1" << endl;
    }
    // 抽象步骤：交给子类实现
    virtual void step2() = 0;
    // 可变步骤
    virtual void step3()
    {
        cout << "执行默认步骤3" << endl;
    }
};

// 具体子类A
class ConcreteA : public AbstractClass
{
protected:
    void step2() override
    {
        cout << "子类A实现自定义步骤2" << endl;
    }
};

// 具体子类B
class ConcreteB : public AbstractClass
{
protected:
    void step2() override
    {
        cout << "子类B实现自定义步骤2" << endl;
    }
    // 也可重写普通虚函数改流程
    void step3() override
    {
        cout << "子类B重写步骤3" << endl;
    }
};

// 测试
int main()
{
    AbstractClass* a = new ConcreteA();
    a->templateMethod();
    cout << "---------" << endl;
    AbstractClass* b = new ConcreteB();
    b->templateMethod();

    delete a;
    delete b;
    return 0;
}