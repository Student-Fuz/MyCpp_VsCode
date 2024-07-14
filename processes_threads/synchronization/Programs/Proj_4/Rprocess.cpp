#include <iostream>
#include <windows.h>

#define BUF_SIZE 20*5
#define STEP_SIZE 20

#define SharedName TEXT("Global\\MyFileMappingObject")

using namespace std;

int main()
{
    //ʹ��OpenSemaphore��ȡ�ź������
    HANDLE hSemaphore = OpenSemaphore(
            SEMAPHORE_MODIFY_STATE,
            TRUE,
            TEXT("Global\\WriteReadDone")
    );


    Sleep(1000);

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

    //������Ϣ
    //�Ż�
    int n = 0;
    while(n < 10){

        Sleep(1);
        //��ӡpBuf�������ն�
        cout << "Message Received NO:" << n << "." << ":" << pBuf <<endl;
        //�ͷ��ź�������Wprocess���̽���д����
        ReleaseSemaphore(
                hSemaphore,//�ź������
                1,      //��ǰ��Դ�����ϼ�"1"
                NULL //���ص�ǰ��Դ������ԭʼֵ
        );
        n++;
    }


    system("pause");

    //3.�رչ����ڴ�

    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);

    return 0;
}
