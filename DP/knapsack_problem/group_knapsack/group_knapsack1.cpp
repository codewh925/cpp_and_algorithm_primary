#include <iostream>
#include <vector>
using namespace std;
vector<vector<pair<int, int>>> a; // a[i]表示第i组，每一组的pair表示重量，价值
//其实也可以用vector<pair<int,int> >a[N]来实现，这样写起来更方便
const int N = 1010;
int f[N]; // f[i][j]表示1到i组选，重量不超过j的最大价值

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z; // 重量，价值，组数
        while (a.size() <= z)
        {
            vector<pair<int, int>> tmp;
            a.push_back(tmp);
        }
        a[z].push_back({x, y});
    }
    // dp
    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = m; j >= 0; j--)
        {
            // i组组内背包
            for (auto k : a[i])
            {
                if (j >= k.first)
                    f[j] = max(f[j], f[j - k.first] + k.second);
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}