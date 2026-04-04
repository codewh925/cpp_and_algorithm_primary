// 马的遍历
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 410;
int dist[N][N];
int n, m, x, y;
// 方向向量
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
typedef pair<int, int> xy;
queue<xy> q;
void bfs()
{
    q.push({x, y});
    dist[x][y] = 0; // 到起点的步数为0
    while (q.size())
    {
        // 取队头
        auto h = q.front();
        q.pop();
        for (int k = 0; k < 8; k++)
        {
            int a = h.first + dx[k];
            int b = h.second + dy[k];
            if (a < 1 || a > n || b < 1 || b > m)
                continue;
            if (dist[a][b] != -1)
                continue;
            dist[a][b] = dist[h.first][h.second] + 1;
            q.push({a, b});
        }
    }
}
int main()
{
    cin >> n >> m >> x >> y;
    memset(dist, -1, sizeof(dist)); //-1表示无法走到，并且也可以防止死循环
    bfs();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}