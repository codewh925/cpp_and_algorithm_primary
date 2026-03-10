#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;
const int N = 100;
int a[N];
int n;
// 优化1：随机选取基准元素
int getRandom(int left, int right)
{
    assert(left <= right);
    return a[rand() % (right - left + 1) + left];
}
void quickSort(int left, int right)
{
    if (left >= right) // 等于为终止条件
        return;
    // 1，获取基准元素
    int random = getRandom(left, right);
    // 优化2：将数组分为三块（小于，等于，大于）
    // 2，分区
    int l = left, r = right, i = left;
    while (i <= r)
    {
        if (a[i] < random)
        {
            swap(a[i], a[l]);
            i++, l++;
        }
        else if (a[i] == random)
        {
            i++;
        }
        else if (a[i] > random)
        {
            swap(a[i], a[r]);
            r--;
        }
    }
    // 分成了：[left,l-1],[l,r],[r+1,right]

    // 3，递归，继续细分
    quickSort(left, l - 1);
    quickSort(r + 1, right);
}
int main()
{
    srand(time(0));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    quickSort(1, n);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}