#include<iostream>
#include<windows.h>
#include <tchar.h>

using namespace std;

#define BUF_SIZE 256
#define SharedName TEXT("Global\\MyFileMappingObject")
TCHAR szMsg[]=TEXT("Hi, I'm Frist process!");

int main(){

    //1.���������ڴ��ļ�
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
    //2.��д�����ڴ�
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

    cout << "Send Message:" << szMsg << endl;

    CopyMemory((PVOID)pBuf, szMsg, sizeof(szMsg));

    system("pause");//�رվ����Ӧ���˳������ڴ�ʧЧ

    //3.�رչ����ڴ�
    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);

    return 0;
}
