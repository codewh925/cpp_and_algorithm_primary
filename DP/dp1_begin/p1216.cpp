#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int a[N][N]; // 存数据
int f[N][N]; // f[i][j]代表从a[1][1]走到a[i][j]的最短权值和
int f1[N];   // 空间优化
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];
    /*二维版
    //dp
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
            f[i][j]=max(f[i-1][j],f[i-1][j-1])+a[i][j];//状态转移方程
    }
    */
    // 空间优化版（一维数组）
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 0; j--)
            f1[j] = max(f1[j], f1[j - 1]) + a[i][j];
    }
    // 最后结果
    int ret = 0;
    // for(int j=1;j<=n;j++)
    // ret=max(ret,f[n][j]);
    for (int j = 1; j <= n; j++)
        ret = max(ret, f1[j]);
    cout << ret << endl;
    return 0;
}