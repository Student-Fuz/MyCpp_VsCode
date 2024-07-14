#include<iostream>
#include<windows.h>
#include <tchar.h>

using namespace std;

#define BUF_SIZE 20*5
#define STEP_SIZE 20
#define SharedName TEXT("Global\\MyFileMappingObject")
TCHAR szMsg[]=TEXT("Message Sent NO:(0)."); //������Ϣ
char Buf[STEP_SIZE]; //�ļ�����buff ��С��STEP_SIZE

int main(){

    //ʹ��OpenSemaphore��ȡ�ź������
    HANDLE hSemaphore = OpenSemaphore(
            SYNCHRONIZE,
            TRUE,
            TEXT("Global\\WriteReadDone")
    );


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
    //���ڴ�ӳ���ļ�����Ϊ5����СΪ20��ҳ��
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

    //2.���������ļ�file.txt,д��n��20DWORD
    HANDLE hFile = CreateFile(_T("file.txt"),
                        GENERIC_READ | GENERIC_WRITE,
                        0,
                        NULL,
                        OPEN_ALWAYS,//û���򴴽�
                        FILE_ATTRIBUTE_NORMAL,
                        NULL
    );
    if (hFile == INVALID_HANDLE_VALUE)
    {
        printf("CreateFile ʧ��:%d \n", GetLastError());
        return 0;
    }
    //д��10��20DWORD����
    DWORD dwWrittenSize = 0;//��д�����ݴ�С
    for(int i = 0; i < 10; i++){
        sprintf(Buf,"Message in file (%d)\n",i);
        //���쳣����
        //BOOL bRet =WriteFile(hFile,Buf,strlen(Buf),&dwWrittenSize,NULL);
        BOOL bRet =WriteFile(hFile,Buf,STEP_SIZE,&dwWrittenSize,NULL);
        //cout << Buf << endl;
        if(bRet){
            //printf("Written success!\n");
        }
        // ��д�ļ�������������ǿ��д����̡�
        //FlushFileBuffers(hFile);
    }
    FlushFileBuffers(hFile);

    //��file.txt�ļ��е��߼�ҳ����д���ڴ�ӳ���ļ��е�ҳ��
    //FIFO����ҳ���û�

    LONG lDistance = 0;
    DWORD dwPtr = SetFilePointer(hFile, lDistance, NULL, FILE_BEGIN);
    if (dwPtr == INVALID_SET_FILE_POINTER){
        DWORD dwError = GetLastError() ;
        printf("Wrong!\n");
    }
    int n = 0;
    DWORD dwReadSize = 0;
    while(n < 10) {
        //hSemaphore����״̬ʱ��������ź���
        WaitForSingleObject(hSemaphore, INFINITE);

        //ReadFile(hFile,Buf,strlen(Buf),&dwReadSize,NULL);

        ReadFile(hFile,&(pBuf[STEP_SIZE*(n%5)]),STEP_SIZE,&dwReadSize,NULL);
        cout << "Write Physical Page:(" << n << ")" << "." <<endl;


        //��file.txt�е����ݷ�����pBuf��
//        ReadFile(hFile,pBuf,STEP_SIZE,&dwReadSize,NULL);
//        cout << "Message READ from file.txt NO:" << n << ":" << pBuf << "." <<endl;
        ++n;

        Sleep(1);
    }

    system("pause");

    //3.�رչ����ڴ�
    UnmapViewOfFile(pBuf);
    CloseHandle(hFile);
    CloseHandle(hMapFile);

    return 0;
}
