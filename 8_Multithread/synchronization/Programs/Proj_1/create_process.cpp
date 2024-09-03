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
            NULL,                   //可执行程序名
            szCommandLine,           //命令行字符串，可以为NULL
            NULL,                 //新进程对象的安全属性
            NULL,                 //新进程对应的线程安全属性
            FALSE,                  //指定父进程的对象句柄能否被子进程继承
            CREATE_NEW_CONSOLE,    // 为新进程创建一个新的控制台窗口
            NULL,                   //指定新进程使用的环境，NULL表示同父进程的环境
            NULL,               //指定子进程当前路径，NULL表示同父进程相同
            &si_1,                     //指定新进程主窗口如何显示
            &pi_1);              //作为返回值使用，是一个指针
    int nError = GetLastError();
    if(flag_1)
    {
        cout<<"进程1的进程ID号："<<pi_1.dwProcessId<<endl;
        cout<<"进程1的主线程ID号："<<pi_1.dwThreadId<<endl;
        ::CloseHandle (pi_1.hThread);
        ::CloseHandle (pi_1.hProcess);
    }
    else
    {
        cout<<"创建进程1失败:"<<nError<<endl;
    }

    STARTUPINFO si_2 = { sizeof(si_2) };
    PROCESS_INFORMATION pi_2;

    si_2.dwFlags = STARTF_USESHOWWINDOW;
    si_2.wShowWindow = TRUE;
    BOOL flag_2 = ::CreateProcess (
            NULL,                   //可执行程序名
            szCommandLine,           //命令行字符串，可以为NULL
            NULL,                 //新进程对象的安全属性
            NULL,                 //新进程对应的线程安全属性
            FALSE,                  //指定父进程的对象句柄能否被子进程继承
            CREATE_NEW_CONSOLE,    //指定创建进程的附加标记，即指定新进程的特性
            NULL,                   //指定新进程使用的环境，NULL表示同父进程的环境
            NULL,               //指定子进程当前路径，NULL表示同父进程相同
            &si_2,                     //指定新进程主窗口如何显示
            &pi_2);              //作为返回值使用，是一个指针
    nError = GetLastError();

    if(flag_2)
    {
        cout<<"进程2的进程ID号："<<pi_2.dwProcessId<<endl;
        cout<<"进程2的主线程ID号："<<pi_2.dwThreadId<<endl;
        ::CloseHandle (pi_2.hThread);
        ::CloseHandle (pi_2.hProcess);
    }
    else
    {
        cout<<"创建进程2失败:"<<nError<<endl;
    }
    return 0;
}
