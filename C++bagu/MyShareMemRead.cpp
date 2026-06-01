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

    HANDLE hMutex = OpenMutexW(MUTEX_ALL_ACCESS, FALSE, MUTEX_NAME);
    HANDLE hShareMem = OpenFileMappingW(FILE_MAP_ALL_ACCESS, FALSE, SHARE_MEM_NAME);
    char* pBuf = (char*)MapViewOfFile(hShareMem, FILE_MAP_ALL_ACCESS, 0, 0, MEM_SIZE);

    WaitForSingleObject(hMutex, INFINITE);
    std::cout << "读取到数据：" << pBuf << std::endl;
    ReleaseMutex(hMutex);

    system("pause");
    return 0;
}