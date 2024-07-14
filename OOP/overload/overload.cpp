//
// Created by Fu_zh on 2022/8/21.
//

#include<iostream>
using namespace std;

//函数重载的注意事项
//1、引用作为重载的条件

void func(int &a)   // int &a = 10; 不合法
{
    cout << "func(int &a)调用" << endl;
}

void func(const int &a) //const int &a = 10; 合法
{
    cout << "func(const int &a)调用" << endl;
}


//2、 函数重载碰到默认参数

void func2(int a , int b = 10)
{
    cout << "func2(int a , int b = 10)调用" << endl;
}

void func2(int a)
{
    cout << "func2(int a)调用" << endl;
}
int main(){
    int a = 10;
    func(a);
    //输出"func(int &a)调用"

    func(10);
    //输出"func(const int &a)调用"


    //不合法、语义含有二义性
    //func2(10);

    return 0;
}

