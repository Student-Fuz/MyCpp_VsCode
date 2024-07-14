//
// Created by Fu_zh on 2023/2/3.
//

#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    int num_a;
    char s_a[10] = "123正8\0";
    int i_a[10] ={10,100,1000};

    char* ptr_char;
    int* ptr_int;

    // 指针赋指针
    ptr_char = s_a;

    // C++ cout 对char*的重载
    // 让 cout << ptr_char << endl;
    // 输出的是该char*指向的char数组内容
    cout << "cout ptr_char: " << ptr_char << endl;

    // C++ cout 对char*的重载
    // 相较于C语言的printf差别不大
    // cout << ptr_int << endl;
    // 输出的是该int*(int 指针)指向对象int的地址
    ptr_int = i_a;
    cout << "cout ptr_int: " << ptr_int << endl;


//
//    //ISO C++11 does not allow conversion from string literal to 'char *'
//    ptr_char = "Hello, world";
//    cout << ptr_char << endl;


    //数组名s_a即是一个
    //指向数组首个元素的
    //char型指针

    cout << "s_a = "<< s_a << endl;
    printf("%x\n",s_a);
    cout << "&num_a = " << &num_a << endl;
    cout << "&s_a = " << &s_a << endl;
    cout << "*(&s_a) = " << *(&s_a) << endl;
    cout << "*s_a = " << *s_a << endl;

    //char类型指针与int类型指针在C++中的微小区别
    //char类型指针
    cout << endl;
    cout << "&(ptr_char) = " << &(ptr_char) << endl;
    cout << "ptr_char = " << ptr_char << endl;
    ptr_char++;
    cout << "&(ptr_char) = " << &(ptr_char) << endl;
    cout << "ptr_char = " << ptr_char << endl;

    //int类型指针
    cout << endl;
    cout << "&(ptr_int) = " << &(ptr_int) << endl;
    cout << "ptr_int = " << ptr_int << endl;
    ptr_int++;
    cout << "&(ptr_int) = " << &(ptr_int) << endl;
    cout << "ptr_int = " << ptr_int << endl;
    cout << endl;

    //访问数组元素
    //可以通过
    //1、一般的数组序号方式
    cout << s_a[0] << endl;

    //也可以通过
    //2、指针方式
    //访问数组元素
    cout << *(s_a+1) << endl;

    //注意
    //可以对s_a取地址，
    //但无法对(s_a+1)取地址

    cout << &s_a << endl;

    //编译报错
    //cout << &(s_a+1) << endl;

    /*
     * C++ NULL指针
     *如果没有确切的地址可以赋值，
     *为指针变量赋一个NULL是一个良好的编程习惯
     */

    int *ptr = NULL;

    cout << "ptr的值是：" << ptr << endl;

    return 0;
}


