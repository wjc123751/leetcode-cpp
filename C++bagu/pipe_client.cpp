#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int main()
{
    SetConsoleOutputCP(65001);
    
    cout << "命名管道客户端启动中..." << endl;
    
    // 等待管道可用
    while (!WaitNamedPipe("\\\\.\\pipe\\MyNamedPipe", 20000))
    {
        cout << "等待服务器..." << endl;
        if (GetLastError() != ERROR_SEM_TIMEOUT)
        {
            cout << "等待失败，错误码：" << GetLastError() << endl;
            cout << "\n按任意键退出...";
            cin.get();
            return 1;
        }
    }
    
    // 连接到命名管道
    HANDLE hPipe = CreateFile(
        "\\\\.\\pipe\\MyNamedPipe",
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        0,
        NULL
    );
    
    if (hPipe == INVALID_HANDLE_VALUE)
    {
        cout << "连接管道失败，错误码：" << GetLastError() << endl;
        cout << "\n按任意键退出...";
        cin.get();
        return 1;
    }
    
    // 设置管道为消息模式
    DWORD mode = PIPE_READMODE_MESSAGE;
    if (!SetNamedPipeHandleState(hPipe, &mode, NULL, NULL))
    {
        cout << "设置管道模式失败，错误码：" << GetLastError() << endl;
        CloseHandle(hPipe);
        cout << "\n按任意键退出...";
        cin.get();
        return 1;
    }
    
    cout << "连接成功！" << endl << endl;
    
    char buffer[1024];
    DWORD bytesRead, bytesWritten;
    BOOL success;
    string input;
    
    while (true)
    {
        cout << "请输入消息 (输入 'exit' 退出): ";
        getline(cin, input);
        
        if (input == "exit")
        {
            break;
        }
        
        if (input.empty())
        {
            continue;
        }
        
        // 发送消息
        success = WriteFile(
            hPipe,
            input.c_str(),
            input.size(),
            &bytesWritten,
            NULL
        );
        
        if (!success)
        {
            cout << "发送失败，错误码：" << GetLastError() << endl;
            break;
        }
        cout << "消息已发送" << endl;
        
        // 读取服务器回复
        success = ReadFile(
            hPipe,
            buffer,
            sizeof(buffer) - 1,
            &bytesRead,
            NULL
        );
        
        if (!success)
        {
            cout << "读取失败，错误码：" << GetLastError() << endl;
            break;
        }
        
        buffer[bytesRead] = '\0';
        cout << "收到回复: " << buffer << endl << endl;
    }
    
    CloseHandle(hPipe);
    
    cout << "\n按任意键退出...";
    cin.get();
    return 0;
}