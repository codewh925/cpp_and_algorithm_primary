// #include <iostream>
// #include <cstring>
// using namespace std;
// const int N = 1010;
// int f[N][N]; // f[i][j]表示从1到i中选，空间不超过j的最大价值
// int v[N], w[N];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, V;
//     cin >> n >> V;
//     for (int i = 1; i <= n; i++)
//         cin >> v[i] >> w[i];
//     // 初始化已完成

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 0; j <= V; j++)
//         {
//             f[i][j] = f[i - 1][j];
//             if (j - v[i] >= 0)
//                 // 将选1，2，3···k个的所有情况用f[i][j-v[i]]+w[i]代替
//                 f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
//         }
//     }
//     cout << f[n][V] << endl;
//     return 0;
// }

// 空间优化版
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1010;
int f[N];
int v[N], w[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, V;
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    // 初始化已完成

    for (int i = 1; i <= n; i++)
    {
        for (int j = v[i]; j <= V; j++)//需要从左往右填，所以不改变遍历顺序
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[V] << endl;
    return 0;
}