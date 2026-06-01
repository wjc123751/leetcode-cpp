#include <Windows.h>
#include <iostream>
#include <cstring>

#define SHARE_MEM_NAME L"MyShareMem001"
#define MEM_SIZE 1024
#define MUTEX_NAME L"MyMemMutex001"

int main()
{
    // ========= 解决中文乱码 =========
    system("chcp 65001");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    // ==============================

    HANDLE hMutex = CreateMutexW(NULL, FALSE, MUTEX_NAME);
    HANDLE hShareMem = CreateFileMappingW(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, MEM_SIZE, SHARE_MEM_NAME);
    char* pBuf = (char*)MapViewOfFile(hShareMem, FILE_MAP_ALL_ACCESS, 0, 0, MEM_SIZE);

    const char* sendData = "你好，Windows共享内存！";
    WaitForSingleObject(hMutex, INFINITE);
    strcpy_s(pBuf, MEM_SIZE, sendData);
    std::cout << "写入数据：" << sendData << std::endl;
    ReleaseMutex(hMutex);

    std::cout << "=== 共享内存已就绪，现在可以打开 Read.exe ===" << std::endl;

    while (1) { Sleep(1000); }

    return 0;
}