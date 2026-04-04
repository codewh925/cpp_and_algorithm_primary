#include <cstdio>
#include <vector>
using namespace std;
int n;
vector<std::pair<bool, int>> a;
vector<int> path;
void fullArrange(int pos)
{
    if (pos == n)
    {
        for (int i : path)
            printf("%d ", i);
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        // 可行性剪枝，避免重复
        if (i > 0 && a[i].second == a[i - 1].second && !a[i - 1].first)
            continue;
        if (!a[i].first) // 可行性剪枝，该数已选，则不可选
        {
            path.push_back(a[i].second);
            a[i].first = true;
            fullArrange(pos + 1);
            path.pop_back();
            a[i].first = false;
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        a.push_back({false, num});
    }
    printf("全排列：\n");
    fullArrange(0);
    return 0;
}