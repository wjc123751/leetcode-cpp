#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    // 设置控制台代码页为UTF-8以正确显示中文
    SetConsoleOutputCP(65001);
    
    HANDLE hFile = CreateFile(
        "\\\\.\\mailslot\\MyQueue",
        GENERIC_WRITE,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        0,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE)
    {
        cout << "打开邮槽失败" << endl;
        cout << "\n按任意键退出...";
        cin.get();
        return -1;
    }

    char sendBuf[] = "Windows消息队列通信测试";
    DWORD writeLen;

    BOOL ret = WriteFile(hFile, sendBuf, sizeof(sendBuf), &writeLen, NULL);
    if (ret)
    {
        cout << "消息发送成功，发送字节数：" << writeLen << endl;
    }
    else
    {
        cout << "发送失败，错误码：" << GetLastError() << endl;
    }

    CloseHandle(hFile);
    
    cout << "\n按任意键退出...";
    cin.get();
    return 0;
}