#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    double b = 1.0;
    auto f = [&]{a++; return (5 * a + b);}; // Lambda表达式捕获并修改a
    cout << f() << endl;
    return 0;
}
