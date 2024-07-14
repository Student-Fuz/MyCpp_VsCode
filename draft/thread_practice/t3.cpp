#include <iostream>
#include "windows.h"  
using namespace std;
DWORD WINAPI FunProc1(LPVOID lpParameter);
DWORD WINAPI FunProc2(LPVOID lpParameter);
int number = 1;
HANDLE hSemaphore;  //�����ź������

int main()
{
    HANDLE hThread1;
    HANDLE hThread2;
    hSemaphore = CreateSemaphore(
        NULL,//ָ����ȫ���ԣ�һ�㴫��NULL
        1,   //ָ���ź�������ĳ�ʼֵ����ֵ������ڵ���0
        100, //ָ�����ź��������ֵ����ֵ�������0��
        NULL//�����ź��������֡�
    );      //��ǰ1����Դ���������100��ͬʱ����   
    hThread1 = CreateThread(
        NULL, //ΪNULL���ʾ���صľ�����ܱ��ӽ��̼̳�
        0,   //���ó�ʼջ�Ĵ�С�����ֽ�Ϊ��λ�����Ϊ0����ôĬ�Ͻ�ʹ������øú������߳���ͬ��ջ�ռ��С��
        FunProc1, //ָ���̺߳�����ָ��
        NULL, //���̺߳������ݵĲ�������һ��ָ��ṹ��ָ�룬���贫�ݲ���ʱ��ΪNULL��
        0, //�����̴߳����ı�־��0����ʾ��������������
        NULL //�������̵߳�id����ָ���߳�id��ָ�룬���Ϊ�գ��߳�id��������
    ); //�����ɹ��������߳̾�������򷵻�NULL
    hThread2 = CreateThread(NULL, 0, FunProc2, NULL, 0, NULL);//��������������
    if (hThread1 != NULL)CloseHandle(hThread1);
    if (hThread2 != NULL)CloseHandle(hThread2);
    Sleep(20000);             // �����߳�˯��1��     
    if (hSemaphore != NULL)CloseHandle(hSemaphore);

    return 0;
}
DWORD WINAPI FunProc1(LPVOID lpParameter)
{
    long count;
    while (number<25)
    {
        WaitForSingleObject(hSemaphore, INFINITE);//hSemaphore����״̬ʱ��������ź���    
        Sleep(1);
        cout << "FunProc 1:" << number << "count is " << count << endl;
        ++number;
        ReleaseSemaphore(
            hSemaphore,//�ź������
            1,      //��ǰ��Դ�����ϼ�"1"
            &count //���ص�ǰ��Դ������ԭʼֵ
        );
    }
    return 0;
}
DWORD WINAPI FunProc2(LPVOID lpParameter)
{
    long count;
    while (number < 25)
    {
        WaitForSingleObject(hSemaphore, INFINITE);//hSemaphore����״̬ʱ��������ź���     
        Sleep(1);
        cout << "FunProc 2:" << number << "count is " << count << endl;
        ++number;
        ReleaseSemaphore(
            hSemaphore,//�ź������
            1,      //��ǰ��Դ�����ϼ�"1"
            &count //���ص�ǰ��Դ������ԭʼֵ
        );
    }
    
    return 0;
}
