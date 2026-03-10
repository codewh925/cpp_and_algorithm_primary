#include <iostream>
using namespace std;
// 选择排序，每次找出最小值，与最前方数字交换
const int N = 11;
int arr[N];
void selectionSort()
{
    for (int i = 1; i < N; i++)
    {
        // 待排序区间起点
        int pos = i;
        for (int j = i; j < N; j++)
        {
            // 最小元素的下标
            if (arr[j] < arr[pos])
            {
                pos = j;
            }
        }
        // 交换
        swap(arr[i], arr[pos]);
    }
}
void print()
{
    for (int i = 1; i < N; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    for (int i = 1; i < N; i++)
    {
        cin >> arr[i];
    }
    selectionSort();
    print();
    return 0;
}