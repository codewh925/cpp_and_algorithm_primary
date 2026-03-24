#include <iostream>
using namespace std;
const int N = 5e5 + 10;
int n;
typedef long long LL;
int a[N];
int temp[N];
LL merge(int left, int right)
{
    if (left >= right)
        return 0;
    LL ret = 0;
    int mid = (left + right) / 2;
    // 分治，先计算左边和右边的逆序对数目，在计算一左一右的
    LL l = merge(left, mid);
    LL r = merge(mid + 1, right);
    // 一左一右的逆序对（归并排序的合并那一步，合并的同时累加）
    int cur1 = left, cur2 = mid + 1, i = left;
    while (cur1 <= mid && cur2 <= right)
    {
        if (a[cur1] <= a[cur2])
            temp[i++] = a[cur1++];
        else
        {
            ret += mid - cur1 + 1;
            temp[i++] = a[cur2++];
        }
    }
    // 最后剩余部分拷贝至temp[]
    while (cur1 <= mid)
        temp[i++] = a[cur1++];
    while (cur2 <= right)
        temp[i++] = a[cur2++];
    // 将temp拷贝回原数组
    for (int j = left; j <= right; j++)
        a[j] = temp[j];
    ret += l + r; // 总的逆序对数目等于左加右加一左一右
    return ret;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << merge(1, n);
    return 0;
}