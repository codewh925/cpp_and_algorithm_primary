#include <iostream>
#include <deque>
using namespace std;
const int N = 1e5 + 10;
int n, k; // k表示窗口大小
int a[N];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    deque<int> dq; // 求最大值，单调递减，存下标
    for (int i = 1; i <= n; i++)
    {
        while (dq.size() && a[dq.back()] <= a[i])
            dq.pop_back();
        dq.push_back(i);
        // 确保窗口合法性
        if (dq.back() - dq.front() + 1 > k)
            dq.pop_front(); // 需要同时前后pop，这便是用双端队列的原因，起初思考问题为队列，后续发现规律该使用dequeue
        if (i >= k)         // 确保第一次填充后窗口满再输出
            cout << a[dq.front()] << " ";
    }
    cout << endl;
    dq.clear();
    // 求窗口内最小值，单调递增，存下标
    for (int i = 1; i <= n; i++)
    {
        while (dq.size() && a[dq.back()] >= a[i])
            dq.pop_back();
        dq.push_back(i);
        if (dq.back() - dq.front() + 1 > k)
            dq.pop_front();
        if (i >= k)
            cout << a[dq.front()] << " ";
    }
    return 0;
}