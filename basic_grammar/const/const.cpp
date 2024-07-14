//
// Created by Fu_zh on 2023/1/9.
//

#include<iostream>
#include<string>

using namespace std;

// 关键---看const在*的左侧还是右侧
// const在

int main(){

    //*****************************************************************************************
    // const int *a   <==>   int const *a
    // 两者等价
    // const位于星号*的左侧，则const就是用来修饰指针所指向的变量/对象，即指针指向为值不可以通过该指针修改
    //*****************************************************************************************
    int value_0 = 60;
    int value_1 = 100;

    const int *a = &value_0;

    const int *b = &value_0;

    cout << "a: " << a << endl;
    cout << "*a: " << *a << endl;

    cout << "b: " << b << endl;
    cout << "*b: " << *b << endl;

    a = b = &value_1;

    cout << "a: " << a << endl;
    cout << "*a: " << *a << endl;

    cout << "b: " << b << endl;
    cout << "*b: " << *b << endl;

    // 注意：被指向的对象只是不能通过指针修改，并非完全不能被修改
    value_1 = 150;

    cout << "a: " << a << endl;
    cout << "*a: " << *a << endl;

    cout << "b: " << b << endl;
    cout << "*b: " << *b << endl;

    //*************************************************************************
    // int *const c
    // const位于星号的右侧，const就是修饰指针本身，即指针本身不可变
    //*************************************************************************

    int *const c = &value_0;

    //以下语句报错，expression must be a modifiable lvalue(左值必须可变)
    //c = &value_1;

    cout << "c: " << c << endl;
    cout << "*c: " << *c << endl;

    // 被指向的对象可使用该指针进行修改
    *c = 61;

    cout << "c: " << c << endl;
    cout << "*c: " << *c << endl;
    

    //*************************************************************************
    // const int *const c
    // *左侧、右侧均有const
    // 1) 指针本身不可变; 2) 指针指向的变量/对象不可通过该指针修改
    //*************************************************************************

    const int *const d = &value_0;

    // 以下语句报错，expression must be a modifiable lvalue(左值必须可变)
    // *d = 62;

    // 以下语句报错，expression must be a modifiable lvalue(左值必须可变)
    // d = &value_1;

    cout << "d: " << d << endl;
    cout << "*d: " << *d << endl;

    // 注意：被指向的对象只是不能通过指针修改，并非完全不能被修改
    value_0 = 62;

    cout << "d: " << d << endl;
    cout << "*d: " << *d << endl;

    return 0;
}

