#include <iostream>
using namespace std;
const int N = 1e5;
int Set[N];
void merge(int n, int m)
{
    Set[m] = n;
}
int find(int m)
{
    if (Set[m] == m)
        return m;
    Set[m] = find(Set[m]); // 压缩路径
    return Set[m];
}
int main()
{
    int n;
    cin >> n;
    // 初始化
    for (int i = 1; i <= n; i++)
        Set[i] = i;
    for (int i = 1; i <= n; i++)
    {
        int n, m;
        cin >> n >> m;
        merge(n, m);
    }
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        if (find(i) == i)
            ret++;
    }
    cout << ret << endl;
    return 0;
}