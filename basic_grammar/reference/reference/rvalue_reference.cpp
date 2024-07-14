//
// Created by Fu_zh on 2023/2/22.
//

#include<iostream>

using namespace std;


int main(){
    int i = 20;

    // non_const reference can only refer to lvalue
    int &r = i;

    // const reference can refer to rvalue

    const int &pi = 3.14152;

    // right value reference is used to save
    // object that will be destroyed after being referred

    int a;

    // compilation failure
    // --a is lvalue
    //int &&rr = --a;

    // a-- is rvalue
    int &&rr = a--;

    cout << "&r:" << r << endl;

    cout << "&rr:" << rr << endl;

    i++;

    a++;

    cout << "&r:" << r << endl;

    cout << "&rr:" << rr << endl;

    rr = 6;

    return 0;
}