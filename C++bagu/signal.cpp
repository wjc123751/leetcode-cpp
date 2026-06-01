#include <stdio.h>
#include <signal.h>
#include <windows.h>

// 信号处理函数
void handler(int sig) {
    printf("收到信号：%d\n", sig);
    if (sig == SIGINT) {
        printf("这是 Ctrl+C 信号！\n");
    }
}

// Windows控制台事件处理
BOOL WINAPI ConsoleHandler(DWORD fdwCtrlType) {
    switch (fdwCtrlType) {
        case CTRL_C_EVENT:
            printf("收到 Ctrl+C 事件 (CTRL_C_EVENT)\n");
            return TRUE;
        case CTRL_CLOSE_EVENT:
            printf("收到窗口关闭事件 (CTRL_CLOSE_EVENT)\n");
            return TRUE;
        case CTRL_BREAK_EVENT:
            printf("收到 Ctrl+Break 事件 (CTRL_BREAK_EVENT)\n");
            return TRUE;
        default:
            return FALSE;
    }
}

int main() {
    // 设置控制台代码页为UTF-8以正确显示中文
    SetConsoleOutputCP(65001);

    printf("Windows信号/事件处理演示\n");
    printf("按 Ctrl+C 测试，或关闭窗口退出\n\n");
    
    // 方法1：使用 signal() 函数（C标准库）
    signal(SIGINT, handler);
    
    // 方法2：使用 Windows SetConsoleCtrlHandler()（推荐）
    SetConsoleCtrlHandler(ConsoleHandler, TRUE);
    
    printf("程序运行中...\n");
    
    while (1) {
        Sleep(1000);  // Windows的Sleep是毫秒
    }
    return 0;
}