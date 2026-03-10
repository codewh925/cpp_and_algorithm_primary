#include <iostream>
using namespace std;
// 插入排序（封装后）
const int N = 11;
struct Arr
{
    int a[N];
    // 升序版
    void insertSort()
    {
        for (int i = 2; i < N; i++)
        {
            // 提前保存a[i]
            int key = a[i];
            int j = i - 1;
            // 所有大于key的全部右移
            while (j >= 1 && a[j] > key)
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = key;
        }
    }
    void print()
    {
        for (int i = 1; i < N; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Arr a1;
    int t[N] = {0, 10, 5, 8, 9, 2, 3, 4, 7, 1, 6};
    for (int i = 0; i < N; i++)
    {
        a1.a[i] = t[i];
    }
    a1.insertSort();
    a1.print();
    return 0;
}