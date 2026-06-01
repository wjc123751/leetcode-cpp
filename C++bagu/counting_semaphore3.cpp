#include <iostream>
#include <thread>
#include <windows.h>  // Windows 信号量
using namespace std;

// 信号量句柄（初始=1，就是互斥锁）
HANDLE g_sem;
int num = 0;

void add() {
    for (int i = 0; i < 100000; i++) {
        // ==================
        // P 操作：申请信号量（等价 lock）
        // ==================
        WaitForSingleObject(g_sem, INFINITE);

        // 临界区（同一时间只有一个线程能进）
        num++;

        // ==================
        // V 操作：释放信号量（等价 unlock）
        // ==================
        ReleaseSemaphore(g_sem, 1, NULL);
    }
}

int main() {
    // 创建信号量：初始值 1，最大值 1 → 互斥锁
    g_sem = CreateSemaphore(NULL, 1, 1, NULL);

    thread t1(add);
    thread t2(add);

    t1.join();
    t2.join();

    cout << "最终结果：" << num << endl;
    CloseHandle(g_sem);
    return 0;
}