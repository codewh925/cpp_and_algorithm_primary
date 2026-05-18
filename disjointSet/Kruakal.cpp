#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 图的边
struct Edge
{
    int u, v, w;
    // 重载"<"为边的权值比较
    bool operator<(Edge e)
    {
        return w < e.w;
    }
};
const int N = 1e4;
vector<Edge> edges;
int Set[N];
void merge(int n, int m)
{
    Set[m] = n;
}
int find(int n)
{
    if (Set[n] == n)
        return n;
    Set[n] = find(Set[n]);
    return Set[n];
}
int kruskal(int n)
{
    sort(edges.begin(), edges.end());
    // 初始化并查集
    for (int i = 1; i <= n; i++)
        Set[i] = i;
    int sum = 0, count = 0;
    for (auto x : edges)
    {
        int u = x.u, v = x.v, w = x.w;
        // 如果不在一个集合
        if (find(u) != find(v))
        {
            merge(u, v);
            sum += w;
            count++;
        }
        if (count == n - 1)
            break;
    }
    return sum; // 最小生成树总权值
}
int main()
{
    // 点的个数和边的条数
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Edge e;
        e.u = u, e.v = v, e.w = w;
        edges.push_back(e);
    }
    cout << kruskal(n) << endl;
    return 0;
}