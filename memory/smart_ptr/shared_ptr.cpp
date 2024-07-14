//
// Created by Fu_zh on 2023/2/3.
//

#include <iostream>
#include <memory>
#include <string>


using namespace std;

class Student {
    string name;
    int age;
public:
    Student(string name, int age){
        this->name = name;
        this->age = age;
    }
    void print(){
        cout << "student name: " << name << endl;
        cout << "student age: " << age << endl;
    }
    void update(string name, int age){
        this->name = name;
        this->age = age;
    }
};

int main(){

    //使用make_shared、
    //实线安全地分配和使用动态内存
    shared_ptr<string> p_s = make_shared<string>("Hello,world! in heap");

    cout << "p_s:" << p_s << endl;

    cout << "*p_s:" << *p_s << endl;

    shared_ptr<string> ptr(p_s);  //shared_ptr 可以指向string 默认空指针（指向NULL）

    //更改ptr中的数据（内容）
    *ptr = "Hello,world! in heap is changed";

    cout << "ptr:" << ptr << endl;

    cout << "*ptr:" << *ptr << endl;

    //p_s内容也跟着改变
    //因为ptr与p_s指向的地址相同
    //取同一地址的内容也相同
    cout << "p_s:" << p_s << endl;

    cout << "*p_s:" << *p_s << endl;


    //复习类的访问方式
    //变量.函数名(); or 指针->函数名();   调用类方法
    //变量.成员变量; or 指针->成员变量;    访问成员变量
    Student s1("fu", 21);

    s1.print();

    //<T>
    //T可以是用户定义的类
    //简单创建 智能指针
    //则使用 auto
    //注意：auto代指的是自动指针
    auto auto_p_st = make_shared<Student>("zheng", 21);

    auto_p_st->print();

    auto_p_st->update("zheng", 22);

    //shared_ptr
    shared_ptr<Student> shared_p_st(auto_p_st);

    shared_p_st->print();


    return 0;
}