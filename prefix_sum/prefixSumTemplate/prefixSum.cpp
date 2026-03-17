#include <iostream>
using namespace std;
const int N = 1e5 + 1;
int a[N];
int f[N]; // 前缀和预处理数组
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // 前缀和数组预处理，f[i]代表区间[1,i]的元素和，f[i]=f[i-1]+a[i];
    for (int i = 1; i <= n; i++)
        f[i] = f[i - 1] + a[i];
    // 询问
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        // 输出[l,r]的a的和
        int num = f[r] - f[l - 1];
        cout << num << endl;
    }
    return 0;
}