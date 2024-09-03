//
// Created by Fu_zh on 2023/1/4.
//
#include <windows.h>
#include <iostream>
#include "TicketsSale.h"

using namespace std;

extern HANDLE g_hMutex;

//HANDLE g_hMutex;

//��Ʊ����
DWORD WINAPI SaleTicket(LPVOID lpParameter)
{

    THD_DATA* pThreadData = (THD_DATA*)lpParameter;
    TICKET* pSaleData = pThreadData->pTicket;
    while(pSaleData->nCount > 0)
    {
        //������һ����������
        WaitForSingleObject(g_hMutex, INFINITE);
        if (pSaleData->nCount > 0)
        {
            cout << pThreadData->strThreadName << "���۵�" << pSaleData->nCount -- << "��Ʊ,";
            if (pSaleData->nCount >= 0) {
                cout << "��Ʊ�ɹ�!ʣ��" << pSaleData->nCount << "��Ʊ." << endl;
            } else {
                cout << "��Ʊʧ�ܣ���Ʊ�����ꡣ" << endl;
            }
        }
        Sleep(10);
        //�ͷŻ�������
        ReleaseMutex(g_hMutex);
    }

    return 0L;
}


