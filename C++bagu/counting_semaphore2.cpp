#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>  // Windows 信号量
using namespace std;

// 信号量：初始 = 0 → 代表一开始没有数据
HANDLE g_sem;

void producer() {
    cout << "生产者：开始生产数据...\n";
    this_thread::sleep_for(chrono::seconds(1)); // 模拟生产
    cout << "生产者：数据生产完成！\n";

    // V操作：信号量 +1 → 通知消费者数据准备好了
    ReleaseSemaphore(g_sem, 1, NULL);
}

void consumer() {
    cout << "消费者：等待数据中...\n";

    // P操作：信号量 -1 → 没数据就阻塞等待
    WaitForSingleObject(g_sem, INFINITE);

    cout << "消费者：收到数据，开始处理！\n";
}

int main() {
    // 创建信号量：初始值 0，最大值 1
    g_sem = CreateSemaphore(NULL, 0, 1, NULL);

    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();

    CloseHandle(g_sem);
    return 0;
}