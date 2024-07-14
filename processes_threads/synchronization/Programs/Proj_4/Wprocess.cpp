#include<iostream>
#include<windows.h>
#include <tchar.h>

using namespace std;

#define BUF_SIZE 20*5
#define STEP_SIZE 20
#define SharedName TEXT("Global\\MyFileMappingObject")
TCHAR szMsg[]=TEXT("Message Sent NO:(0)."); //发送信息
char Buf[STEP_SIZE]; //文件内容buff 大小：STEP_SIZE

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
    //将内存映射文件划分为5个大小为20的页框
    LPTSTR pBuf;
    pBuf = (LPTSTR)MapViewOfFile(
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

    //2.建立磁盘文件file.txt,写入n个20DWORD
    HANDLE hFile = CreateFile(_T("file.txt"),
                        GENERIC_READ | GENERIC_WRITE,
                        0,
                        NULL,
                        OPEN_ALWAYS,//没有则创建
                        FILE_ATTRIBUTE_NORMAL,
                        NULL
    );
    if (hFile == INVALID_HANDLE_VALUE)
    {
        printf("CreateFile 失败:%d \n", GetLastError());
        return 0;
    }
    //写入10个20DWORD内容
    DWORD dwWrittenSize = 0;//已写入数据大小
    for(int i = 0; i < 10; i++){
        sprintf(Buf,"Message in file (%d)\n",i);
        //做异常处理
        //BOOL bRet =WriteFile(hFile,Buf,strlen(Buf),&dwWrittenSize,NULL);
        BOOL bRet =WriteFile(hFile,Buf,STEP_SIZE,&dwWrittenSize,NULL);
        //cout << Buf << endl;
        if(bRet){
            //printf("Written success!\n");
        }
        // 把写文件缓冲区的数据强制写入磁盘。
        //FlushFileBuffers(hFile);
    }
    FlushFileBuffers(hFile);

    //将file.txt文件中的逻辑页依此写入内存映射文件中的页框
    //FIFO策略页面置换

    LONG lDistance = 0;
    DWORD dwPtr = SetFilePointer(hFile, lDistance, NULL, FILE_BEGIN);
    if (dwPtr == INVALID_SET_FILE_POINTER){
        DWORD dwError = GetLastError() ;
        printf("Wrong!\n");
    }
    int n = 0;
    DWORD dwReadSize = 0;
    while(n < 10) {
        //hSemaphore空闲状态时，申请该信号量
        WaitForSingleObject(hSemaphore, INFINITE);

        //ReadFile(hFile,Buf,strlen(Buf),&dwReadSize,NULL);

        ReadFile(hFile,&(pBuf[STEP_SIZE*(n%5)]),STEP_SIZE,&dwReadSize,NULL);
        cout << "Write Physical Page:(" << n << ")" << "." <<endl;


        //将file.txt中的内容放置至pBuf中
//        ReadFile(hFile,pBuf,STEP_SIZE,&dwReadSize,NULL);
//        cout << "Message READ from file.txt NO:" << n << ":" << pBuf << "." <<endl;
        ++n;

        Sleep(1);
    }

    system("pause");

    //3.关闭共享内存
    UnmapViewOfFile(pBuf);
    CloseHandle(hFile);
    CloseHandle(hMapFile);

    return 0;
}
