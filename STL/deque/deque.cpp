#include <deque>
#include <cstdio>
using namespace std;
int main()
{
    // 初始化方式与vector一致
    deque<int> d1;
    deque<int> d2(3, 1);
    deque<int> d3(d2.begin(), d2.end());
    deque<int> d4 = {1, 2, 3, 4};
    d1.push_back(1);
    d1.push_front(2);
    for (int i : d1)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (auto i = d2.begin(); i != d2.end(); i++)
    {
        printf("%d ", *i);
    }
    printf("\n");
    d2[2] = 2;
    printf("%d\n", d2[2]);

    return 0;
}