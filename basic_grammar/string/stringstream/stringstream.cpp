//
// Created by Fu_zh on 2023/1/5.
//

#include <iostream>
#include <string>

#include <strstream>

#include <sstream>

using namespace std;

int main(){

    string str = "I am very happy!";
    string temp;

    // sstream��
    // ͨ��stringstream ���е����з�
    stringstream sstr_1;
    sstr_1 << str;
    while (sstr_1 >> temp)
        cout << temp << endl;

    cout << typeid(sstr_1).name() << endl;

    //strstream��
    //ͨ�� sstream ���е����з�
    strstream sstr_2;
    sstr_2 << str;
    while (sstr_2 >> temp)
        cout << temp << endl;

    cout << typeid(sstr_2).name() << endl;

    //�ظ�ʹ��sstream����ʱ
    //����ϴ�����
    sstr_1.clear();

    //sstream�� or strstream��
    //����������С�������з�
    string figure_string = "134 25.77";
    int a = 0;
    double b = 0;
    sstr_1 << figure_string;
    sstr_1 >> a;
    cout << "a: " << a << endl;
    sstr_1 >> b;
    cout << "b: " << b << endl;

    return 0;
}

