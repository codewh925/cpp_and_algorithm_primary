//深度优先遍历其实就是递归，递归本质就是树的建立过程，递归展开图就是一棵树
// //使用vector数组存储的树
// #include<iostream>
// #include<vector>
// using namespace std;
// const int N=1e5+10;
// int n;
// vector<int>edges[N];
// bool my_signal[N];//标记是否已经遍历过
// //深度优先遍历
// void dfs(int n)
// {
//     cout << n << " ";
//     my_signal[n]=true;
//     for(int child:edges[n])
//     {
//         if(!my_signal[child])
//         {
//             dfs(child);
//         }
//     }
// }
// int main()
// {
//     cin >> n;
//     for(int i=1;i<n;i++)
//     {
//         int a,b;
//         cin >> a >> b;
//         edges[a].push_back(b);
//         edges[b].push_back(a);
//     }
//     //深度优先遍历
//     dfs(1);
//     return 0;
// }
// 使用链式前向星存储的树
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int h[N];
int e[N * 2], ne[N * 2];
bool my_signal[N];
int n, id;
void add(int a, int b)
{
    id++;
    // 头插
    ne[id] = h[a];
    e[id] = b;
    h[a] = id;
}
// 深度优先遍历
void dfs(int n = 1)
{
    cout << n << " ";
    my_signal[n] = true;
    for (int i = h[n]; i; i = ne[i]) // i为n的孩子结点在e[]中的下标
    {
        int nd = e[i];
        if (!my_signal[nd])
        {
            dfs(nd);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    return 0;
}