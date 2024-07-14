#include <iostream>
#include <windows.h>

#define BUF_SIZE 256
#define SharedName TEXT("Global\\MyFileMappingObject")

using namespace std;

int main()
{

    Sleep(1000);

    /* ���߼��������쳣���� */
    //1.�򿪹����ڴ��ļ�
    HANDLE hMapFile = OpenFileMapping(
            FILE_MAP_ALL_ACCESS,   // read/write access
            FALSE,                 // do not inherit the name
            SharedName);           // name of mapping object

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


    //MessageBox(NULL, pBuf, TEXT("Process2"), MB_OK);
    cout << pBuf << endl;
    system("pause");

    //3.�رչ����ڴ�
    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);

    return 0;
}
