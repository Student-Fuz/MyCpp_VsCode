//
// Created by Fu_zh on 2022/9/24.
//

#include <iostream>

using namespace std;

class Animal_1{
public:
    virtual void speak(){
        cout << "动物在说话" << endl;
    }

    virtual ~Animal_1(){

    }
};

class Animal_2{
public:
    void speak(){
        cout << "动物在说话" << endl;
    }
};

//虚函数   virtual void func(){}
//纯虚函数  virtual void func() = 0
//含有纯虚函数的类称为抽象函数

class Animal{
public:
    //speak函数就是虚函数
    //虚函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了

    virtual void speak(){
        cout << "动物在说话" << endl;
    }

    virtual void walk() = 0;

    virtual ~Animal(){

    }
};

class Cat : public Animal{
public:
    void speak(){
        cout << "小猫在说话" << endl;
    }

    void walk() override {
        cout << "小猫在走路" << endl;
    }
};

class Dog : public Animal{
public:
    void speak(){
        cout << "小狗在说话" << endl;
    }
    void walk() override {
        cout << "小狗在走路" << endl;
    }
};

void DoSpeak(Animal & animal){
    animal.speak();
}

void DoWalk(Animal & animal){
    animal.walk();
}

//多态满足条件
//1、有继承关系
//2、子类重写父类中的虚函数
//多态使用条件
//父类指针或引用 指向子类对象
// **注意：**即根据对象类型决定函数调用，不根据指针/引用

void test01(){
    Cat cat;
    DoSpeak(cat);

    Dog dog;
    DoSpeak(dog);
}

void test02(){
    Cat cat;
    DoWalk(cat);

    Dog dog;
    DoWalk(dog);
}

void test03(){
    cout << "sizeof Animal = " << sizeof(Animal_1) <<  "byte" <<endl;
    cout << "sizeof Animal = " << sizeof(Animal_2) << "byte" << endl;
}

int main(){
    test01();

    test02();

    //*********************************************
    //Animal中仅含虚函数
    //virtual void speak(){}时
    //Animal类的大小是8
    //*********************************************
    //Animal中仅含函数时
    //void speak(){}时
    //Animal类的大小是1
    //*********************************************
    //原因：含有虚函数的类中有虚表用于存放虚函数。
    //*********************************************

    test03();

    return 0 ;
}