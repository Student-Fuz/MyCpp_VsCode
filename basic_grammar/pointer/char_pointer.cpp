//
// Created by Fu_zh on 2023/4/8.
//

#include<iostream>

using namespace std;


int main(){

    char s[] = "helloworld!";
    printf("%0x08\r\n", s);
    cout << s << endl;
    cout << *s << endl;
    cout << &s << endl;
    cout << sizeof(s) << endl;

    char* ps = "helloworld!";
    printf("%0x08\r\n", ps);
    cout << ps << endl;
    cout << *ps << endl;
    cout << &ps << endl;
    cout << sizeof(ps) << endl;

    char* ps_1 = "helloworld!";
    printf("%0x08\r\n", ps_1);

    return 0;
}