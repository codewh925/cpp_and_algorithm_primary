// 计算哈夫曼编码的长度
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
int main()
{
    long long n;
    cin >> n;
    LL ret = 0;
    priority_queue<LL, vector<LL>, greater<LL>> heap;
    // 依次读入每个字符出现的次数
    for (int i = 1; i <= n; i++)
    {
        int count;
        cin >> count;
        heap.push(count);
    }
    // 利用哈夫曼树的性质计算转换后的哈夫曼编码的值
    // 哈夫曼编码长即为哈夫曼树的带权路径长度
    while (heap.size() > 1)
    {
        // 取权值最小的两个结点
        LL x = heap.top();
        heap.pop();
        LL y = heap.top();
        heap.pop();
        ret += x + y; // 累加带权路径长度
        // 新的二叉树的根结点入堆
        heap.push(x + y);
    }
    cout << ret;
    return 0;
}