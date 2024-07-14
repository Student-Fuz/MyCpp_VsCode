//
// Created by Fu_zh on 2023/1/4.
//

#include "TicketsSale.h"

using namespace std;

HANDLE g_hMutex;

//��Ʊϵͳ
void Test()
{
    //����һ��������
    g_hMutex = CreateMutex(NULL, FALSE, NULL);

    //��ʼ����Ʊ
    TICKET ticket;
    ticket.nCount = 100;
    strcpy(ticket.strTicketName, "����-->����");

    const int THREAD_NUMM = 8;
    THD_DATA threadSale[THREAD_NUMM];
    HANDLE hThread[THREAD_NUMM];
    for(int i = 0; i < THREAD_NUMM; ++ i)
    {

        threadSale[i].pTicket = &ticket;

        string strThreadName = convertToString(i);

        strThreadName = "����" + strThreadName;

        //c_str() �������Խ� const string* ���� ת��Ϊ cons char* ����
        strcpy(threadSale[i].strThreadName, strThreadName.c_str());

        //�����߳�
        hThread[i] = CreateThread(NULL, NULL, SaleTicket, &threadSale[i], 0, NULL);

        //������һ����������
        WaitForSingleObject(g_hMutex, INFINITE);
        cout << threadSale[i].strThreadName << "��ʼ���� " << threadSale[i].pTicket->strTicketName << " ��Ʊ..." << endl;
        //�ͷŻ�������
        ReleaseMutex(g_hMutex);

        //�ر��߳�
        CloseHandle(hThread[i]);
    }

    system("pause");
}

int main(){

    Test();

    return 0;
}
