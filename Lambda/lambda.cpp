#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    double b = 1.0;
    // 定义Lambda表达
    // auto f_val = [=]{a++; return a;};    // 编译不通过
    // auto f = [a]{a++; return a;};        // 编译不通过；捕获默认值传递
    auto f_val = [a]()mutable{a++; return a;};

    // 运行Lambda表达式并输出Lambda表达式返回值
    cout << "Lambda表达式a:" << f_val() << endl;

    // 输出作用域内a的值
    cout << "作用域内的a:" << a << endl;

    // 定义Lambda表达式 f_ref
    auto f_ref = [&]{a++; return a;};       // Lambda表达式按引用捕获并修改a

    // 运行Lambda表达式并输出Lambda表达式返回值
    cout << "按照引用传递的Lambda表达式a:" << f_ref() << endl;

    // 输出作用域内a的值
    cout << "作用域内的a:" << a << endl;

    return 0;
}
