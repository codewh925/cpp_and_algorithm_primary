#include <iostream>
#include <stack>
using namespace std;
const int N = 1e5 + 10;
int n;
int a[N];
int ret[N];
void test()
{
    stack<int> st; // 单调递减的栈，存下标
    for (int i = 1; i <= n; i++)
    {
        while (st.size() && a[st.top()] <= a[i])
            st.pop();
        if (st.size())
            ret[i] = st.top();
        st.push(i);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    test();
    cout << "左边第一个比当前元素大的元素下标：" << endl;
    for (int i = 1; i <= n; i++)
        cout << ret[i] << " ";
    return 0;
}