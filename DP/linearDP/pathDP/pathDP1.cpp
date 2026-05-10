#include <iostream>
#include <cstring>
using namespace std;
const int N = 510;
int main()
{
    int n, m;
    cin >> n >> m;
    int f[N];
    memset(f, 0x3f, sizeof(f)); // 批量无穷大
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int a;
            cin >> a;
            f[j] = min(f[j - 1], f[j]) + a;
        }
    }
    cout << f[m] << endl;
    return 0;
}