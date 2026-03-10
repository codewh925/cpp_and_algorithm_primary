#include <iostream>
using namespace std;
const int N = 10;
int a[N];
int temp[N];
int n;
void merge(int left, int mid, int right)
{
    // 双指针归并
    int k = left;
    int cur1 = left, cur2 = mid + 1;
    while (cur1 <= mid && cur2 <= right)
    {
        if (a[cur1] > a[cur2])
        {
            temp[k++] = a[cur2++];
        }
        else
            temp[k++] = a[cur1++];
    }
    // 连接上剩余部分
    while (cur1 <= mid)
    {
        temp[k++] = a[cur1++];
    }
    while (cur2 <= right)
    {
        temp[k++] = a[cur2++];
    }
    // 拷贝回原数组
    for (int i = left; i <= right; i++)
    {
        a[i] = temp[i];
    }
}
void mergeSort(int left, int right)
{
    // 递归终止条件
    if (left >= right)
        return;
    // 1，二分
    int mid = (left + right) >> 1;
    // 2，排序
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    // 3，合并有序数组
    merge(left, mid, right);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    mergeSort(1, n);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}