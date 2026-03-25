// 贪心算法解决最大字段和问题
#include <iostream>
using namespace std;
const int N = 1e6 + 1;
int a[N];
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ret = -1e6;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        // 贪心策略
        sum += a[i];
        ret = max(sum, ret);
        if (sum < 0)
            sum = 0;
    }
    cout << ret << endl;
    return 0;
}