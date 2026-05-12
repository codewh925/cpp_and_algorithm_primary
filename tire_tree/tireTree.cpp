// 字典树模板
#include <iostream>
#include <string>
using namespace std;
const int N = 1e6 + 10; // N表示所有字符的出现次数上限（结点数）
int tree[N][26];        // 第二维度的数组表示边代表的26个字符，tree[i]表示i号结点的孩子信息
int p[N];               // 记录pass信息
int e[N];               // 记录end信息
int idx;                // 为新来的字符分配位置
void insert(string &s)
{
    int cur = 0; // 从根节点开始
    p[cur]++;    // pass一次
    for (auto ch : s)
    {
        int path = ch - 'a';         // 当前字符所走路径
        if (tree[cur][path] == 0)    // 没有这条路径
            tree[cur][path] = ++idx; // 分配路径
        cur = tree[cur][path];       // 分配下一个结点
        p[cur]++;                    // pass一次
    }
    e[cur]++; // end一次
}
// 查找字符串出现次数
int find(string &s)
{
    int cur = 0;
    for (auto ch : s)
    {
        int path = ch - 'a';
        if (tree[cur][path] == 0)
            return 0;
        cur = tree[cur][path];
    }
    return e[cur];
}
// 查找前缀出现次数
int find_pre(string &s)
{
    int cur = 0;
    for (auto ch : s)
    {
        int path = ch - 'a';
        if (tree[cur][path] == 0)
            return 0;
        cur = tree[cur][path];
    }
    return p[cur];
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        insert(s);
    }
    string s = "hello";
    cout << find(s);
    s = "h";
    cout << endl
         << find_pre(s);
    return 0;
}