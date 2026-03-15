#include <iostream>
#include <stack>
#include <deque>
using namespace std;
int main()
{
    // 1,常见初始化方式
    stack<int> st1; // 空栈初始化，最常用
    // 用底层容器初始化(需同类型)
    deque<int> d{1, 2, 3};
    stack<int> st_d(d); // 栈顶为3
    // 拷贝初始化
    stack<int> st2(st_d);
    // 移动初始化
    stack<int> st3(std::move(st_d)); // st_d变为空栈
    // 2,核心成员函数
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (auto i : arr)
    {
        st1.push(i);
    }
    cout << st1.size() << endl;
    // 遍历
    while (!st1.empty())
    {
        cout << st1.top() << " ";
        st1.pop();
    }
    return 0;
}