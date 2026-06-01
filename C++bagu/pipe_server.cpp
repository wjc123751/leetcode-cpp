#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int main()
{
    SetConsoleOutputCP(65001);
    
    cout << "命名管道服务器启动中..." << endl;
    
    // 创建命名管道
    HANDLE hPipe = CreateNamedPipe(
        "\\\\.\\pipe\\MyNamedPipe",
        PIPE_ACCESS_DUPLEX,
        PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
        1,
        1024,
        1024,
        0,
        NULL
    );
    
    if (hPipe == INVALID_HANDLE_VALUE)
    {
        cout << "创建管道失败，错误码：" << GetLastError() << endl;
        cout << "\n按任意键退出...";
        cin.get();
        return 1;
    }
    
    cout << "管道创建成功！等待客户端连接..." << endl << endl;
    
    // 等待客户端连接
    BOOL connected = ConnectNamedPipe(hPipe, NULL) ?
        TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);
    
    if (!connected)
    {
        cout << "连接客户端失败，错误码：" << GetLastError() << endl;
        CloseHandle(hPipe);
        cout << "\n按任意键退出...";
        cin.get();
        return 1;
    }
    
    cout << "客户端已连接！" << endl << endl;
    
    char buffer[1024];
    DWORD bytesRead, bytesWritten;
    BOOL success;
    
    while (true)
    {
        // 读取客户端消息
        success = ReadFile(
            hPipe,
            buffer,
            sizeof(buffer) - 1,
            &bytesRead,
            NULL
        );
        
        if (!success || bytesRead == 0)
        {
            if (GetLastError() == ERROR_BROKEN_PIPE)
            {
                cout << "客户端已断开连接" << endl;
            }
            else
            {
                cout << "读取失败，错误码：" << GetLastError() << endl;
            }
            break;
        }
        
        buffer[bytesRead] = '\0';
        cout << "收到消息: " << buffer << endl;
        
        // 回复消息
        string reply = "服务器收到: ";
        reply += buffer;
        
        success = WriteFile(
            hPipe,
            reply.c_str(),
            reply.size(),
            &bytesWritten,
            NULL
        );
        
        if (!success)
        {
            cout << "发送失败，错误码：" << GetLastError() << endl;
            break;
        }
        cout << "回复已发送" << endl << endl;
    }
    
    FlushFileBuffers(hPipe);
    DisconnectNamedPipe(hPipe);
    CloseHandle(hPipe);
    
    cout << "\n按任意键退出...";
    cin.get();
    return 0;
}