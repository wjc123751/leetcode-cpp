#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MinStack
{
private:
    stack<int> stk;
    stack<int> minstk;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        stk.push(val);
        if (minstk.empty())
        {
            minstk.push(val);
        }
        else
        {
            minstk.push(min(minstk.top(), val));
        }
    }

    void pop()
    {
        stk.pop();
        minstk.pop();
    }

    int top()
    {
        return stk.top();
    }

    int getMin()
    {
        return minstk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;

    return 0;
}