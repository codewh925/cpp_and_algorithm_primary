#include <iostream>
using namespace std;
const int N = 5001;
int a[N];
int f[N]; // f[i]表示以a[i]结尾的最长上升子序列长度
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ret = 1;
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1; // 自己单独为一个子序列
        // 找出第一个比a[i]小的数的f[]
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j])
                f[i] = max(f[j] + 1, f[i]);
        }
        ret = max(ret, f[i]);
    }
    cout << ret << endl;
    return 0;
}