#include <iostream>

using namespace std;

class MyClass {
public:
    int value;
    MyClass(int v) : value(v) {}
    void setValue(int v) { value = v; }
    void printValue() const { cout << "Value: " << value << endl; }

};

int main() {
    MyClass obj(10);
    MyClass obj2(30);
    
    // 对象内容不可变
    const MyClass* ptr = &obj;  // const 修饰对象的内容
    
    ptr->printValue();  // 输出: Value: 10
    
    // ptr->setValue(20);  // 错误：无法修改对象内容，因为指向的对象是 const 的

    ptr = &obj2;  // 可以改变指针指向另一个对象
    ptr->printValue();  // 输出: Value: 30

    MyClass* const ptr_1 = &obj;  // const 修饰对象的内容

    ptr_1->setValue(20);
    ptr_1->printValue();

    // ptr_1 = &obj2;  // 错误：无法修改指向对象，因为指针是 const 的
    return 0;
}
