#include <iostream>
#include <cstring>
using namespace std;
const int N = 1010;
int v[N], w[N]; // 每个物品的体积和价值
int f[N][N];    // f[i][j]表示从1~i物品，体积不超过j能选的最大价值
int dp[N][N];   // dp[i][j]表示从1~i物品，体积等于j时的最大价值
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 物品个数与背包体积上限
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    // 初始化全为0即可

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j - v[i] >= 0)
                f[i][j] = max(f[i][j], w[i] + f[i - 1][j - v[i]]);
        }
    }
    cout << f[n][m] << endl;

    // 第二问，体积恰好为m的最大价值
    memset(dp, 0xcf, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - v[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}