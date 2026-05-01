#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void readFile()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in);
    // 要判断是否打开成功
    if (ifs.is_open() == false)
    {
        cout << "文件打开失败\n";
    }
    else
    {
        // 四种读取
        // 1
        char buff[1024] = {0};
        while (ifs >> buff) // 就像cin一样，遇到空格或换行符就停止，然后下一次读取（会覆盖），直到EOF
        {
            cout << buff << endl;
        }
        // 2
        char buff2[1024] = {0};
        while (ifs.getline(buff2, sizeof(buff2)))
        {
            cout << buff2 << endl;
        }
        // 3
        string s;
        while (getline(ifs, s))
        {
            cout << s << endl;
        }
        // 4，不推荐
        char buf;
        while ((buf = ifs.get()) != EOF)
        {
            cout << buf << endl;
        }
        ifs.close();
    }
}
int main()
{
    readFile();
    return 0;
}