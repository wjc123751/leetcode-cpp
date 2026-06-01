#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    // 设置控制台代码页为UTF-8以正确显示中文
    SetConsoleOutputCP(65001);
    
    HANDLE hMailslot = CreateMailslot(
        "\\\\.\\mailslot\\MyQueue",
        0,
        MAILSLOT_WAIT_FOREVER,
        NULL
    );

    if (hMailslot == INVALID_HANDLE_VALUE)
    {
        cout << "创建邮槽失败，错误码：" << GetLastError() << endl;
        cout << "\n按任意键退出...";
        cin.get();
        return -1;
    }

    cout << "邮槽服务器已启动，等待消息..." << endl;
    cout << "(按 Ctrl+C 或关闭窗口停止)" << endl << endl;

    char buffer[1024];
    DWORD bytesRead;
    BOOL ret;

    while (true)
    {
        ret = ReadFile(hMailslot, buffer, sizeof(buffer), &bytesRead, NULL);
        if (ret && bytesRead > 0)
        {
            buffer[bytesRead] = '\0';
            cout << "收到消息：" << buffer << endl;
        }
        else
        {
            cout << "读取失败，错误码：" << GetLastError() << endl;
            break;
        }
    }

    CloseHandle(hMailslot);
    
    cout << "\n按任意键退出...";
    cin.get();
    return 0;
}