#include <iostream>
#include <vector>
using namespace std;
// 1，利用vector数组实现
const int N = 1e5 + 10;
int n;
vector<int> edges[N]; // 存储树
// 2，链式前向星
int id; // 计数
const int N_2 = 1e5 + 10;
int h[N_2];
int e[2 * N_2], ne[2 * N_2]; // 无根树每个边需要存储两遍
int n2;
void add_child(int a, int b)
{
    id++;
    // 头插
    ne[id] = h[a];
    h[a] = id;
    e[id] = b;
}
int main()
{
    // 方法一：
    cin >> n;
    for (int i = 1; i < n; i++) // 边数=结点数-1
    {
        int a, b;
        // a结点与b结点之间有一条边
        cin >> a >> b;
        // 无根树
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    // 方法二：
    cin >> n2; // 结点数
    for (int i = 1; i < n2; i++)
    {
        int a, b;
        cin >> a >> b;
        add_child(a, b);
        add_child(b, a);
    }
    return 0;
}