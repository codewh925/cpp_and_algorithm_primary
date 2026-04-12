// //vector数组存储的树
// #include<iostream>
// #include<vector>
// #include<queue>//使用队列的先进先出的性质实现广度优先
// using namespace std;
// const int N=1e5+10;
// int n;
// vector<int>edges[N];
// queue<int>q;
// bool my_signal[N];
// //广度优先遍历
// void bfs(int n=1)
// {
//     q.push(n);
//     my_signal[n]=true;
//     int cur=n;
//     while(q.size())
//     {
//         //孩子进队
//         for(int i:edges[cur])
//         {
//             if(!my_signal[i])
//             {
//                 q.push(i);
//                 my_signal[i]=true;//进队标记
//             }
//         }
//         //出队列
//         cout << q.front() <<" ";
//         q.pop();
//         cur=q.front();//迭代
//     }
// }
// int main()
// {
//     cin >> n;
//     for(int i=1;i<n;i++)
//     {
//         int a,b;
//         cin >> a >>b;
//         edges[a].push_back(b);
//         edges[b].push_back(a);
//     }
//     bfs();
//     return 0;
// }
// 使用链式前向星存储的树
#include <iostream>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
int n, id;
int h[N], e[N * 2], ne[N * 2];
queue<int> q;
bool my_signal[N];
void add(int a, int b)
{
    id++;
    ne[id] = h[a];
    e[id] = b;
    h[a] = id;
}
void bfs(int nd = 1)
{
    q.push(nd);
    my_signal[nd] = true;
    int cur = nd;
    while (q.size())
    {
        // 孩子结点入队
        for (int i = h[cur]; i; i = ne[i])
        {
            int j = e[i];
            if (!my_signal[j])
            {
                q.push(j);
                my_signal[j] = true;
            }
        }
        // 出队
        cout << q.front() << " ";
        q.pop();
        // 迭代
        cur = q.front();
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> b >> a;
        add(a, b);
        add(b, a);
    }
    bfs();
    return 0;
}