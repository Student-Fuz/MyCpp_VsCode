#include <iostream>
#include <windows.h>

#define BUF_SIZE 256
#define SharedName TEXT("Global\\MyFileMappingObject")

using namespace std;

int main()
{
    //使用OpenSemaphore获取信号量句柄
    HANDLE hSemaphore = OpenSemaphore(
            SEMAPHORE_MODIFY_STATE,
            TRUE,
            TEXT("Global\\WriteReadDone")
    );


    Sleep(1000);


    //1.打开共享内存文件
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
    //2.读写共享内存
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

    //接收信息
    //优化——————如何使用这个pBuf话柄，在终端输出其内容，取代MessageBox
    int n = 0;
    long count = 0;
    while(n < 10){
        cout << "Message Received NO:" << n << ":   " << pBuf <<  "." <<endl;
        //释放信号量，让Wprocess进程进行写操作
        ReleaseSemaphore(
                hSemaphore,//信号量句柄
                1,      //当前资源计数上加"1"
                &count //返回当前资源计数的原始值
        );
        Sleep(200);
//        cout << "count is " << count << endl;
        n++;
    }

    system("pause");

    //3.关闭共享内存
    CloseHandle(hSemaphore);
    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);

    return 0;
}
