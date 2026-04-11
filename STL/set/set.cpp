#include <set>
#include <iostream>
using namespace std;
int main()
{
    set<int> s1;
    set<int> s2 = {1};
    set<int, greater<int>> s3; // 调整为降序
    int n;
    cin >> n;
    // 1，insert插入
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        s1.insert(num);
    }
    // 2，迭代器
    for (auto i = s1.begin(); i != s1.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    // 3，其余各种函数
    // end()返回的是尾后迭代器
    s1.erase(s1.begin()); // erase释放函数，需要指定值，返回值为新的end的迭代器
    s1.size();
    s1.empty();
    // 查找
    auto it = s1.find(5); // 找到则返回迭代器，没找到则返回end
    if (it != s1.end())
    {
        cout << *it << endl;
    }
    // 只查找是否存在，count返回个数，有就是1，没有就是0
    if (s1.count(3))
    {
        cout << "存在" << endl;
    }
    s1.swap(s2); // set自带的swap，交换两个同类型set
    s1.clear();  // 清空

    return 0;
}