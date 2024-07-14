#include<iostream>
using namespace std;

class A{
public:
    A(){ cout << "调用A的默认构造函数" << endl; }
    virtual ~A(){ cout << "调用A的析构函数" << endl; }
    virtual void func(){
        cout << "func() in A" << endl;
    }
};

class B: public A{
public:
    B(){ cout << "调用B的默认构造函数" << endl; }
    ~B(){ cout << "调用B的析构函数" << endl; }
    virtual void func(){
        cout << "func() in B" << endl;
    }
};

void test01(){
	//实验一
	cout << "A对象a::" << endl;
	A *a = new A();
	delete a;
	cout << endl << endl;
	cout << "B对象b::" << endl;
	B *b = new B();
	delete b;
}

void test02(){
    //实验二
    cout << "A *a1 = new B();" << endl;
    A *a1 = new B();
    cout << "delete a1;" << endl;
    delete a1;
}

void test03(){
    // 实验三 向上转型
    // 子类指针——————>父类指针
    // 安全---直接转换
    // 子类指针可以转换为父类指针
    B *b = new B();
    A *a = (A*)b;
    cout << "a->func()" << endl;
    a->func();
}

void test04(){
    // 实验四
    // 父类指针——————>子类指针
    // 不安全---建议使用dynamic_cast
    // 父类指针可以转换为子类指针
    A *a = new A();
    //可通过下列方式进行转换
    B *b = (B*)a;
    cout << "b->func()" << endl;
    b->func();
}


int main()
{
    test03();
    test04();
    return 0;
}
