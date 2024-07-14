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

    // sstream库
    // 通过stringstream 进行单词切分
    stringstream sstr_1;
    sstr_1 << str;
    while (sstr_1 >> temp)
        cout << temp << endl;

    cout << typeid(sstr_1).name() << endl;

    //strstream库
    //通过 sstream 进行单词切分
    strstream sstr_2;
    sstr_2 << str;
    while (sstr_2 >> temp)
        cout << temp << endl;

    cout << typeid(sstr_2).name() << endl;

    //重复使用sstream类型时
    //清除上次内容
    sstr_1.clear();

    //sstream库 or strstream库
    //对整型数、小数进行切分
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

