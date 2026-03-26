#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> discretize(vector<int> &a)
{
    // 1，copy a array
    vector<int> all = a;
    int n = a.size();
    // 2,sort the copy and unique
    sort(all.begin(), all.end()); // sort的第三个参数是自定义排序函数，不能乱传参数
    // 这里涉及到了unique的用法，简单来说unique函数的功能就是将相邻的重复元素（因为只处理相邻的，所以需要sort再使用）移到末尾，返回不含重复元素的结尾迭代器
    // 如：1 2 2 2 3 3->unique()->1 2 3 2 2 3
    all.erase(unique(all.begin(), all.end()), all.end());
    // 3，binary search
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        res[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin() + 1; // add 1 to let the index start with 1
    }
    return res;
}
int main()
{
    vector<int> a = {5, 12, 5, -3, 999}; // 离散且大的数据
    vector<int> ans = discretize(a);
    for (int i : ans)
        cout << i << " ";
    return 0;
}