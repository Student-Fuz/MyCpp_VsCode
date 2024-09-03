//
// Created by Fu_zh on 2023/1/4.
//

#ifndef CPP_TICKETSSALE_H
#define CPP_TICKETSSALE_H

#endif //CPP_TICKETSSALE_H

#include <windows.h>
#include <iostream>
#include <strstream>
#include <string>

using namespace std;

#define NAME_LINE   40

//�����̺߳�����������Ľṹ��
typedef struct __TICKET
{
    int nCount;
    char strTicketName[NAME_LINE];
    //�ṹ���ʼ��
    __TICKET() : nCount(0)
    {
        memset(strTicketName, 0, NAME_LINE * sizeof(char));
    }
}TICKET;

typedef struct __THD_DATA
{
    TICKET* pTicket;
    char strThreadName[NAME_LINE];
    //�ṹ���ʼ��
    __THD_DATA() : pTicket(NULL)
    {
        memset(strThreadName, 0, NAME_LINE * sizeof(char));
    }
}THD_DATA;


//������������ת�����ַ���
template<class T>
string convertToString(const T val)
{
    string s;
    std::strstream ss;
    ss << val;
    ss >> s;
    return s;
}

//��Ʊ����
DWORD WINAPI SaleTicket(LPVOID lpParameter);
