//
// Created by Fu_zh on 2023/1/6.
//

#include <fstream>
#include <iostream>
using namespace std;

int main ()
{

    char data[100];

    // 以写模式打开文件
    ofstream outfile;
    outfile.open("afile.txt");

    cout << "正在写入文件" << endl;
    cout << "请输入你的名字: ";
    cin.getline(data, 100);

    // 将用户输入写入文件
    outfile << data << endl;

    cout << "请输入你的年龄: ";
    cin >> data;
    cin.ignore();

    // 将用户的年龄写入文件
    outfile << data << endl;

    // 关闭已打开的文件
    outfile.close();

    // 以读模式打开文件
    ifstream infile;
    infile.open("afile.txt");

    cout << "正在从文件读取" << endl;
    infile >> data;

    // 将数据输出到屏幕
    cout << data << endl;

    // 再次从文件读取数据并显示
    infile >> data;
    cout << data << endl;

    // 关闭已打开的文件
    infile.close();

    return 0;
}