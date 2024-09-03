//
// Created by Fu_zh on 2023/2/10.
//

#include <iostream>
#include <vector>

using namespace std;

class student{
    string name;
    int age;
public:
    student(string name,int age){
        this->name = name;
        this->age = age;
    }
    void print(){
        cout << "name:" << name << endl;
        cout << "age:" << age << endl;
    }
    int get_age(){
        return age;
    }
};

int main(){

    // string iterator
    string s = "hello";

    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it <<endl;
    }

    cout << "Ordinary iterator:" <<endl;

    //��ͨ������
    for(string::iterator it = s.begin(); it != s.end(); it++){

        *it = 'h';
        cout << *it <<endl;

    }

    cout << "const iterator:" <<endl;

    // ����������
    for(string::const_iterator it = s.begin(); it != s.end(); it++){
        // �Ƿ�����
//        *it = 'e';
        cout << *it <<endl;
    }

    return 0;
}
