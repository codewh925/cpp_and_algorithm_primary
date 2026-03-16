#include <queue>
#include <iostream>
using namespace std;

int main()
{
    // 大根堆：
    priority_queue<int> heap;
    priority_queue<int, vector<int>, less<int>> heap2;
    // 小根堆：
    priority_queue<int, vector<int>, greater<int>> heap3;
    // 成员函数
    int arr[] = {1, 2, 3, 4, 5};
    for (int i : arr)
    {
        heap.push(i); // push后会自动调整为大根堆
    }
    while (!heap.empty())
    {
        // 取出根
        cout << heap.top() << " ";
        // 删除
        heap.pop(); // 删除后也会自动调整为大根堆
    }
    // 这其实就是利用STL模板容器实现堆排序
    return 0;
}
