//
// Created by Fu_zh on 2022/9/4.
//
#include<iostream>
#include<string>

using namespace std;

template<class NameType, class AgeType = int>
class Person{
public:
    Person(NameType name, AgeType age){
        m_Name = name;
        m_Age = age;
        cout << "人物姓名为：" << m_Name << endl;
        cout << "人物年龄为：" << m_Age << endl;
    }
    NameType m_Name;
    AgeType m_Age;
};

int main(){

    // 指定姓名、年龄类型
    Person<string,double> p1("孙悟空",999.95);
    Person<string,int> p2("孙悟空",1000);
    return 0;
}
