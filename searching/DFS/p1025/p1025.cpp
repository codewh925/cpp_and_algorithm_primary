// 将n分为k份的分法
#include <cstdio>
using namespace std;
int n, k;
int path;
int count;
void dfs(int pos, int begin)
{
    if (pos == k)
    {
        if (path == n)
            count++;
        return;
    }
    for (int i = begin; i <= n; i++)
    {
        // 可行性剪枝，剪枝不能放在外面，否则会超时
        if ((path + begin * (k - count)) > n)
            return;
        path += i;
        dfs(pos + 1, i);
        path -= i; // 回溯
    }
}
int main()
{
    scanf("%d %d", &n, &k);
    dfs(0, 1);
    printf("%d\n", count);
    return 0;
}