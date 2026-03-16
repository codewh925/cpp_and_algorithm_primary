#include <iostream>
#include <list>
using namespace std;
int main()
{
    // 创建
    list<int> lst1(5, 1);       // 元素个数为5，所有值赋值为1
    list<int> lst2 = {1, 2, 3}; // 三个元素，1，2，3
    list<int> alst[4];          // 元素为list<int>的数组
    // 增删查改
    lst1.push_back(2);
    lst1.unique();
    // 迭代器
    for (auto it = lst1.begin(); it != lst1.end(); it++)
    {
        cout << *it << " ";
        //*经过了重载，所以对lst1的迭代器解引用可以得到结点内部的值
    }
    cout << endl;
    // 范围for（底层也是迭代器遍历）
    for (auto i : lst1)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << lst1.max_size() << endl; // 由硬件决定
    cout << lst1.size() << endl;
    lst1.push_front(3);
    cout << lst1.front() << endl;
    lst1.sort(); // 默认升序
    // lst1.sort(comp);单参数版本，可降序
    for (auto i : lst1)
    {
        cout << i << " ";
    }
    return 0;
}