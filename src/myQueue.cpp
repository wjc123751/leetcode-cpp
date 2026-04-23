#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 栈本身后进先出，把输入栈的所有元素整体倒序、全部倒入输出栈，顺序就变成了先进先出

// class MyQueue
// {
// private:
//     stack<int> inStk;

// public:
//     MyQueue()
//     {
//     }

//     void push(int x)
//     {
//         inStk.push(x);
//     }

//     int pop()
//     {
//         stack<int> tmpStk = inStk;
//         stack<int> outStk;
//         while(!tmpStk.empty()){
//             int x = tmpStk.top();
//             tmpStk.pop();
//             outStk.push(x);
//         }
//         int ret = outStk.top();
//         outStk.pop();
//         while(!outStk.empty()){
//             int x = outStk.top();
//             outStk.pop();
//             tmpStk.push(x);
//         }
//         inStk = tmpStk;
        
//         return ret;
//     }

//     int peek()
//     {
//         stack<int> tmpStk = inStk;
//         stack<int> outStk;
//         while(!tmpStk.empty()){
//             int x = tmpStk.top();
//             tmpStk.pop();
//             outStk.push(x);
//         }
//         int ret = outStk.top();
//         return ret;
//     }

//     bool empty()
//     {
//         return inStk.empty();
//     }
// };

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

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyQueue myQueue;
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    myQueue.push(3); // queue is: [1, 2] (leftmost is front of the queue)
    myQueue.push(4); // queue is: [1, 2] (leftmost is front of the queue)
    myQueue.pop();   // return 1, queue is [2]
    myQueue.push(5); // queue is: [1, 2] (leftmost is front of the queue)
    myQueue.pop();   // return 1, queue is [2]
    myQueue.pop();   // return 1, queue is [2]
    myQueue.pop();   // return 1, queue is [2]
    myQueue.pop();   // return 1, queue is [2]

    return 0;
}
