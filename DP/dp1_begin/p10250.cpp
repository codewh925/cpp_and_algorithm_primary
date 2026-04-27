// dp入门，爬楼梯问题
#include <iostream>
using namespace std;
const int N = 65;
typedef long long LL;
int f[N]; // 状态表示，f[i]表示有i个阶梯时的解
int main()
{
    int n;
    cin >> n;
    // 初始化
    f[0] = 1, f[1] = 1, f[2] = 2;
    for (int i = 3; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2] + f[i - 3]; // 状态推导方程
    cout << f[n] << endl;
    return 0;
}