// 滑动窗口经典模板
#include <iostream>
#include <unordered_map>
using namespace std;
const int N = 1e6 + 10;
int a[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, ret = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        // 1，初始化
        int left = 1, right = 1;
        unordered_map<int, int> window;
        while (right <= n)
        {
            // 2，进窗口
            window[a[right]]++;
            // 3，检查并滑动
            while (window[a[right]] > 1)
            {
                window[a[left]]--;
                left++;
            }
            // 4，更新状态
            ret = max(ret, right - left + 1);
            right++;
        }
        cout << ret << endl;
    }
    return 0;
}