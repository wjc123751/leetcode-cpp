#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
using namespace std;

queue<int> q;
mutex mtx;
condition_variable cv;
bool done = false; // 标记生产是否完成

// 生产者
void producer() {
    for (int i = 1; i <= 5; i++) {
        unique_lock<mutex> lock(mtx);
        q.push(i);
        cout << "生产：" << i << endl;
        cv.notify_one(); // 唤醒消费者
    }
    // 生产完成，标记一下
    {
        unique_lock<mutex> lock(mtx);
        done = true;
    }
    cv.notify_one(); // 再唤醒一次，让消费者知道结束了
}

// 消费者（改成循环消费）
void consumer() {
    while (true) {
        unique_lock<mutex> lock(mtx);
        // 条件：队列不为空 OR 生产已结束（即使队列为空也退出）
        cv.wait(lock, [] { return !q.empty() || done; });

        // 如果队列为空且生产已结束，退出循环
        if (q.empty() && done) {
            break;
        }

        // 消费数据
        cout << "消费：" << q.front() << endl;
        q.pop();
    }
}

int main() {
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();
    return 0;
}
