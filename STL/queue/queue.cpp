#include <queue>
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    queue<int> q1;
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i : arr)
    {
        q1.push(i);
    }
    cout << q1.size() << endl;
    printf("front:%d back:%d\n", q1.front(), q1.back());
    // 遍历
    while (!q1.empty())
    {
        printf("%d ", q1.front()); // 尾进头出
        q1.pop();
    }

    return 0;
}