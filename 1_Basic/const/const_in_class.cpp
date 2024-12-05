#include<iostream>

using namespace std;

// 类的声明
class Person{

    int age = 18;
    const string name = "Fu";

public:
    Person();
    
    Person(string enterName);

    // 报错常量不可修改
    // void modify(string enterName){
    //     name = enterName;
    // }

    void print();
};

// 关键——————>即常量可在构造函数时修改（这也是推荐用法）
Person::Person(string enterName) : name(enterName){
    cout << "age: " << age << endl;
    cout << "name: " << name << endl;
};

Person::Person(){
    cout << "age: " << age << endl;
    cout << "name: " << name << endl;
};

void Person::print(){
    cout << "name: " << name << endl;
};


int main(){

    cout << "*********p_0.print***********" << endl;
    Person p_0;

    p_0.print();

    cout << "*********p_1.print***********" << endl;  

    string myName = "Zheng"; 

    Person p_1(myName);

    p_1.print();

    return 0;
}
