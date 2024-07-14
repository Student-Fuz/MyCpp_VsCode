#include<iostream>
#include <windows.h>

using namespace std;

int main(){
    STARTUPINFO si_w = { sizeof(si_w) };
    PROCESS_INFORMATION pi_w;

    si_w.dwFlags = STARTF_USESHOWWINDOW;
    si_w.wShowWindow = TRUE;
    BOOL flag_w = ::CreateProcess (
            "./Wprocess.exe",                   //可执行程序名 (.exe)
            NULL,           //命令行字符串，可以为NULL
            NULL,                 //新进程对象的安全属性
            NULL,                 //新进程对应的线程安全属性
            FALSE,                  //指定父进程的对象句柄能否被子进程继承
            CREATE_NEW_CONSOLE,    // 为新进程创建一个新的控制台窗口
            NULL,                   //指定新进程使用的环境，NULL表示同父进程的环境
            NULL,               //指定子进程当前路径，NULL表示同父进程相同
            &si_w,                     //指定新进程主窗口如何显示
            &pi_w);              //作为返回值使用，是一个指针

    STARTUPINFO si_r = { sizeof(si_r) };
    PROCESS_INFORMATION pi_r;

    si_r.dwFlags = STARTF_USESHOWWINDOW;
    si_r.wShowWindow = TRUE;
    BOOL flag_r = ::CreateProcess (
            "./Rprocess.exe",                   //可执行程序名 (.exe)
            NULL,           //命令行字符串，可以为NULL
            NULL,                 //新进程对象的安全属性
            NULL,                 //新进程对应的线程安全属性
            FALSE,                  //指定父进程的对象句柄能否被子进程继承
            CREATE_NEW_CONSOLE,    //指定创建进程的附加标记，即指定新进程的特性
            NULL,                   //指定新进程使用的环境，NULL表示同父进程的环境
            NULL,               //指定子进程当前路径，NULL表示同父进程相同
            &si_r,                     //指定新进程主窗口如何显示
            &pi_r);              //作为返回值使用，是一个指针

    return 0;
}
