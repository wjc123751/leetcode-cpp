#include <iostream>
using namespace std;

// 定义一系列策略，封装成类策略A策略B，可互相替换setStrategy，让算法独立于使用它的客户（客户只负责选择用哪个算法、调用执行）

// 1. 抽象策略类（统一算法接口）
class Strategy
{
public:
    virtual void doOperation() = 0;
    virtual ~Strategy() {}
};

// 2. 具体策略A
class StrategyAdd : public Strategy
{
public:
    void doOperation() override
    {
        cout << "执行加法策略" << endl;
    }
};

// 3. 具体策略B
class StrategySub : public Strategy
{
public:
    void doOperation() override
    {
        cout << "执行减法策略" << endl;
    }
};

// 4. 环境类（调用策略）
class Context
{
private:
    Strategy* strategy;
public:
    // 动态注入策略
    void setStrategy(Strategy* s)
    {
        strategy = s;
    }
    // 统一调用
    void execute()
    {
        strategy->doOperation();
    }
};

// 测试
int main()
{
    Context ctx;

    // 切换不同策略
    ctx.setStrategy(new StrategyAdd());
    ctx.execute();

    ctx.setStrategy(new StrategySub());
    ctx.execute();

    return 0;
}