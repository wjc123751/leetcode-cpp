#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <windows.h> // Windows 系统信号量（不用C++20，不用自定义）
using namespace std;

// Windows 信号量句柄
HANDLE g_sem;
// 保护打印，防止输出乱序
mutex cout_mtx;

void task(int id)
{
    // ======================
    // P 操作：申请信号量
    // ======================
    WaitForSingleObject(g_sem, INFINITE);

    {
        lock_guard<mutex> lock(cout_mtx);
        cout << "线程 " << id << " 开始执行（占用名额）\n";
    }

    this_thread::sleep_for(chrono::seconds(2)); // 模拟任务

    {
        lock_guard<mutex> lock(cout_mtx);
        cout << "线程 " << id << " 执行完毕（释放名额）\n";
    }

    // ======================
    // V 操作：释放信号量
    // ======================
    ReleaseSemaphore(g_sem, 1, NULL);
}

int main()
{
    // ==============================
    // 创建信号量：初始=2，最大=2
    // 作用：最多允许 2 个线程同时运行
    // ==============================
    g_sem = CreateSemaphore(
        NULL,
        2, // 初始值 2
        2, // 最大值 2
        NULL);

    thread t1(task, 1);
    thread t2(task, 2);
    thread t3(task, 3);

    t1.join();
    t2.join();
    t3.join();

    CloseHandle(g_sem);
    return 0;
}