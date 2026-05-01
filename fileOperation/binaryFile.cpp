#include <iostream>
#include <fstream>
using namespace std;
void binaryFile()
{
    fstream fs;
    // 二进制，写，读，打开方式
    fs.open("test.txt", ios::out | ios::binary | ios::in);
    if (!fs.is_open())
    {
        cout << "open error\n";
        return;
    }
    // 二进制写
    char s[] = "二进制文本进来喽\n";
    fs.write((const char *)s, sizeof(s));
    // 读
    char buf[1024] = {0};
    // 重置文件指针（之前写入已经移动到了末尾，直接读会什么都读不到
    fs.seekg(0, ios::beg);//ios::beg为文件开头
    fs.read(buf, sizeof(buf));
    cout << buf << endl;
    fs.close();
}
int main()
{
    binaryFile();
    return 0;
}