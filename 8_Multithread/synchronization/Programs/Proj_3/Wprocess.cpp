#include<iostream>
#include<windows.h>
#include <tchar.h>

using namespace std;

#define BUF_SIZE 256
#define SharedName TEXT("Global\\MyFileMappingObject")
TCHAR szMsg[]=TEXT("Message sent NO:0.");

int main(){

    //使用OpenSemaphore获取信号量句柄
    HANDLE hSemaphore = OpenSemaphore(
            SYNCHRONIZE,
            TRUE,
            TEXT("Global\\WriteReadDone")
    );

    //1.创建共享内存文件
    HANDLE hMapFile = CreateFileMapping(
            INVALID_HANDLE_VALUE,    // use paging file
            NULL,                    // default security
            PAGE_READWRITE,          // read/write access
            0,                       // maximum object size (high-order DWORD)
            BUF_SIZE,                // maximum object size (low-order DWORD)
            SharedName);                 // name of mapping object

    if (hMapFile == NULL)
    {
        printf(TEXT("Could not open file mapping object (%d).\n"),
                 GetLastError());
        system("pause");
        return 1;
    }
    LPTSTR pBuf = (LPTSTR)MapViewOfFile(
            hMapFile,            // handle to map object
            FILE_MAP_ALL_ACCESS, // read/write permission
            0,
            0,
            BUF_SIZE);

    if (pBuf == NULL)
    {
        printf(TEXT("Could not map view of file (%d).\n"),
                 GetLastError());
        system("pause");

        CloseHandle(hMapFile);

        return 1;
    }

    //2.发送信息
    int n = 0;
    long count = 0;
    while(n < 10) {
        WaitForSingleObject(hSemaphore, INFINITE);//hSemaphore空闲状态时，申请该信号量
        CopyMemory((PVOID)pBuf, szMsg, sizeof(szMsg));
        cout << "Send Message NO:" << n << ":    " << szMsg << "." <<endl;
        n++;
        sprintf(szMsg,"Message sent NO:%d.",n);
        Sleep(1);
    }

    system("pause");

    //3.关闭共享内存
    CloseHandle(hSemaphore);
    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);

    return 0;
}
