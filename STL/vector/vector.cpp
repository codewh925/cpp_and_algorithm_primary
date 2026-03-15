#include <iostream>
#include <vector>
using namespace std;
const int N = 10;
struct Test
{
    int num;
    float h;
};
int main()
{
    // vector：动态顺序表，即可变长数组
    // 1,创建
    vector<int> a1;                   // 空的，存储数据为int 的
    vector<int> a2(N);                // capacity为10的，存储数据为int的，且默认全为0
    vector<int> a3(N, 1);             // capacity为10，且数据全为1
    vector<int> a5 = {1, 2, 3, 4, 5}; // 创建同时初始化
    vector<Test> a4;                  // 数据类型为Test的空的顺序表
    vector<vector<int>> a6;           // 二维顺序表
    // 各种成员函数和性质
    for (int i = 0; i < 10; i++)
    {
        a2[i] = i;
    }
    for (auto i : a2)
    {
        cout << i << endl;
        a2.pop_back();
    }
    cout << a2.capacity();      // capacity没有变
    int front_num = a5.front(); // 返回值为引用
    cout << endl << front_num;
    a5.clear(); // 清空所有值，但不释放内存

    return 0;
}