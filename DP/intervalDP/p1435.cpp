#include <iostream>
#include <string>
using namespace std;
const int N = 1010;
int f[N][N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    // 区间DP特有的循环方式：
    // 1，第一层循环区间长度
    // 2，第二层循环区间起点
    for (int len = 1; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            if (s[i] == s[j])
                f[i][j] = f[i + 1][j - 1];
            else
                f[i][j] = min(f[i + 1][j] + 1, f[i][j - 1] + 1);
        }
    }
    cout << f[1][n] << endl;
    return 0;
}