#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MyQueue
{
private:
    stack<int> inStk;   // 入队
    stack<int> outStk;  // 出队（只用这一个栈存倒好的数据）

    // 封装：out 空了才把 in 倒过去
    void move() {
        if (outStk.empty()) {
            while (!inStk.empty()) {
                outStk.push(inStk.top());
                inStk.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inStk.push(x);
    }

    int pop() {
        move();
        int x = outStk.top();
        outStk.pop();
        return x;
    }

    int peek() {
        move();
        return outStk.top();
    }

    bool empty() {
        return inStk.empty() && outStk.empty();
    }
};
