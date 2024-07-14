// CPP_多继承
#include <iostream>

class Base1 {
public:
    void foo() {
        std::cout << "Base1::foo()" << std::endl;
    }
};

class Base2 {
public:
    void foo() {
        std::cout << "Base2::foo()" << std::endl;
    }
};

class Derived : public Base1, public Base2 {
public:
    void bar() {
        std::cout << "Derived::bar()" << std::endl;
    }
    // 多个基类中存在同名的成员或函数
    // 派生类需要使用作用域解析运算符（::）来指定具体从哪个基类继承的成员或函数
    void callBase1foo() {
        Base1::foo();
    }

    void callBase2foo() {
        Base2::foo();
    }
};

int main() {
    Derived d;
    // d.foo();  // 运行失败 error: request for member 'foo' is ambiguous(不明确的)
    d.callBase1foo();   // 输出：Base1::foo()
    d.callBase2foo();   // 输出：Base2::foo()
    d.bar();  // 输出：Derived::bar()

    return 0;
}