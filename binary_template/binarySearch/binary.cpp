// 在排序数组中查找元素第一个和最后一个位置
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> a;
    int n, target;
    cin >> n >> target;
    // 非降序输入
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        a.push_back(num);
    }
    int releft, reright;
    if (n < 1)
    {
        releft = -1, reright = -1;
        cout << releft << " " << reright;
        return 0;
    }
    // 1，查找第一个出现位置（二分查找区间左端点）
    int l = 0, r = n - 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (a[mid] >= target)
            r = mid;
        else
            l = mid + 1;
    }
    releft = l;
    // 2，查找最后一个出现的位置（二分查找区间右端点）
    l = 0, r = n - 1;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (a[mid] > target)
            r = mid - 1;
        else
            l = mid;
    }
    reright = r;
    cout << releft << " " << reright;
    return 0;
}