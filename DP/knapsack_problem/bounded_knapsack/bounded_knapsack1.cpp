// #include <iostream>
// using namespace std;
// const int N = 110;
// int f[N];
// int w[N]; // 重量
// int v[N]; // 价值
// int x[N]; // 个数
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, m;
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> x[i] >> w[i] >> v[i];
//     for (int i = 1; i <= n; i++)
//         for (int j = m; j >=0; j--)
//             for (int k = 0; k <= x[i] && j - k * w[i] >= 0; k++)
//                 f[j] = max(f[j], f[j - k * w[i]] + k * v[i]);
//     cout << f[m] << endl;
//     return 0;
// }

// 二进制优化
#include <iostream>
using namespace std;
const int N = 110 * 5;
int f[N];
int pos;
int w[N], v[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z; // 个数，重量，价值
        int t = 1;
        while (x - t >= 0)
        {
            pos++;
            w[pos] = t * y;
            v[pos] = t * z;
            x -= t;
            t *= 2;
        }
        if (x) // 剩余个数
        {
            pos++;
            w[pos] = x * y;
            v[pos] = x * z;
        }
    }
    for (int i = 1; i <= pos; i++)
        for (int j = m; j >= w[i]; j--)
            f[j] = max(f[j], f[j - w[i]] + v[i]); // 01背包
    cout << f[m] << endl;
    return 0;
}