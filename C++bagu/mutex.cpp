#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int num = 0;
mutex mtx; // 互斥量

void add() {
    for (int i = 0; i < 100000; i++) {
        mtx.lock();   // 上锁
        num++;        // 同一时间只有一个线程能执行
        mtx.unlock(); // 解锁
    }
}

int main() {
    thread t1(add);
    thread t2(add);

    t1.join();
    t2.join();

    cout << num << endl; // 结果一定是 200000
    return 0;
}