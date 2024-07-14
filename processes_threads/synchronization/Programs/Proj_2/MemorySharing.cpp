#include<iostream>
#include <windows.h>

using namespace std;

int main(){
    STARTUPINFO si_w = { sizeof(si_w) };
    PROCESS_INFORMATION pi_w;

    si_w.dwFlags = STARTF_USESHOWWINDOW;
    si_w.wShowWindow = TRUE;
    BOOL flag_w = ::CreateProcess (
            "./Wprocess.exe",                   //��ִ�г����� (.exe)
            NULL,           //�������ַ���������ΪNULL
            NULL,                 //�½��̶���İ�ȫ����
            NULL,                 //�½��̶�Ӧ���̰߳�ȫ����
            FALSE,                  //ָ�������̵Ķ������ܷ��ӽ��̼̳�
            CREATE_NEW_CONSOLE,    // Ϊ�½��̴���һ���µĿ���̨����
            NULL,                   //ָ���½���ʹ�õĻ�����NULL��ʾͬ�����̵Ļ���
            NULL,               //ָ���ӽ��̵�ǰ·����NULL��ʾͬ��������ͬ
            &si_w,                     //ָ���½��������������ʾ
            &pi_w);              //��Ϊ����ֵʹ�ã���һ��ָ��

    STARTUPINFO si_r = { sizeof(si_r) };
    PROCESS_INFORMATION pi_r;

    si_r.dwFlags = STARTF_USESHOWWINDOW;
    si_r.wShowWindow = TRUE;
    BOOL flag_r = ::CreateProcess (
            "./Rprocess.exe",                   //��ִ�г����� (.exe)
            NULL,           //�������ַ���������ΪNULL
            NULL,                 //�½��̶���İ�ȫ����
            NULL,                 //�½��̶�Ӧ���̰߳�ȫ����
            FALSE,                  //ָ�������̵Ķ������ܷ��ӽ��̼̳�
            CREATE_NEW_CONSOLE,    //ָ���������̵ĸ��ӱ�ǣ���ָ���½��̵�����
            NULL,                   //ָ���½���ʹ�õĻ�����NULL��ʾͬ�����̵Ļ���
            NULL,               //ָ���ӽ��̵�ǰ·����NULL��ʾͬ��������ͬ
            &si_r,                     //ָ���½��������������ʾ
            &pi_r);              //��Ϊ����ֵʹ�ã���һ��ָ��

    return 0;
}
