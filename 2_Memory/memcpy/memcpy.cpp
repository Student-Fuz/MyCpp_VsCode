//
// Created by Fu_zh on 2023/3/29.
//

#include <iostream>
#include <chrono>

using namespace std;

const int SIZE = 100000;

int main()
{
    auto start_time = chrono::steady_clock::now();  // 获取开始时间

    // 循环赋值
    int a[SIZE];
    int b[SIZE];
    for (int i = 0; i < SIZE; i++) {
        b[i] = a[i];
    }

    auto end_time = chrono::steady_clock::now();    // 获取结束时间
    auto elapsed_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time); // 计算运行时间

    cout << "Loop assign Elapsed time: " << elapsed_time.count() << " ns" << endl;   // 输出运行时间

    // memcpy 赋值
    start_time = chrono::steady_clock::now();  // 获取开始时间
    // Maxcount is the copied bytes
    memcpy(a, b, sizeof(a));
    end_time = chrono::steady_clock::now();    // 获取结束时间

    elapsed_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time); // 计算运行时间
    cout << "memcpy assign Elapsed time: " << elapsed_time.count() << " ns" << endl;   // 输出运行时间

    return 0;
}
