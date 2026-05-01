#include <iostream>
#include <fstream>
using namespace std;
void writeIn()
{
    // 写入
    ofstream ofs;
    ofs.open("test.txt", ios::out);
    // 写入的主要方式：和cout标准输出的使用方法一样
    // 1
    ofs << "张三，男" << endl;
    // 2
    char name[] = "zhangsan";
    ofs << name << endl; // 会整个读入
    ofs.close();
}
int main()
{
    writeIn();
    return 0;
}