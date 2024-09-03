#include <iostream>
#include <windows.h>
using namespace std;

int main(int argc, char* argv[])
{
    STARTUPINFO si_1 = { sizeof(si_1) };
    PROCESS_INFORMATION pi_1;

    si_1.dwFlags = STARTF_USESHOWWINDOW;
    si_1.wShowWindow = TRUE;
    char szCommandLine[]="cmd";
    BOOL flag_1 = ::CreateProcess (
            NULL,                   //��ִ�г�����
            szCommandLine,           //�������ַ���������ΪNULL
            NULL,                 //�½��̶���İ�ȫ����
            NULL,                 //�½��̶�Ӧ���̰߳�ȫ����
            FALSE,                  //ָ�������̵Ķ������ܷ��ӽ��̼̳�
            CREATE_NEW_CONSOLE,    // Ϊ�½��̴���һ���µĿ���̨����
            NULL,                   //ָ���½���ʹ�õĻ�����NULL��ʾͬ�����̵Ļ���
            NULL,               //ָ���ӽ��̵�ǰ·����NULL��ʾͬ��������ͬ
            &si_1,                     //ָ���½��������������ʾ
            &pi_1);              //��Ϊ����ֵʹ�ã���һ��ָ��
    int nError = GetLastError();
    if(flag_1)
    {
        cout<<"����1�Ľ���ID�ţ�"<<pi_1.dwProcessId<<endl;
        cout<<"����1�����߳�ID�ţ�"<<pi_1.dwThreadId<<endl;
        ::CloseHandle (pi_1.hThread);
        ::CloseHandle (pi_1.hProcess);
    }
    else
    {
        cout<<"��������1ʧ��:"<<nError<<endl;
    }

    STARTUPINFO si_2 = { sizeof(si_2) };
    PROCESS_INFORMATION pi_2;

    si_2.dwFlags = STARTF_USESHOWWINDOW;
    si_2.wShowWindow = TRUE;
    BOOL flag_2 = ::CreateProcess (
            NULL,                   //��ִ�г�����
            szCommandLine,           //�������ַ���������ΪNULL
            NULL,                 //�½��̶���İ�ȫ����
            NULL,                 //�½��̶�Ӧ���̰߳�ȫ����
            FALSE,                  //ָ�������̵Ķ������ܷ��ӽ��̼̳�
            CREATE_NEW_CONSOLE,    //ָ���������̵ĸ��ӱ�ǣ���ָ���½��̵�����
            NULL,                   //ָ���½���ʹ�õĻ�����NULL��ʾͬ�����̵Ļ���
            NULL,               //ָ���ӽ��̵�ǰ·����NULL��ʾͬ��������ͬ
            &si_2,                     //ָ���½��������������ʾ
            &pi_2);              //��Ϊ����ֵʹ�ã���һ��ָ��
    nError = GetLastError();

    if(flag_2)
    {
        cout<<"����2�Ľ���ID�ţ�"<<pi_2.dwProcessId<<endl;
        cout<<"����2�����߳�ID�ţ�"<<pi_2.dwThreadId<<endl;
        ::CloseHandle (pi_2.hThread);
        ::CloseHandle (pi_2.hProcess);
    }
    else
    {
        cout<<"��������2ʧ��:"<<nError<<endl;
    }
    return 0;
}
