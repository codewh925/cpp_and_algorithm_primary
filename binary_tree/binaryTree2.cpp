// 二叉树的顺序存储和遍历
// 顺序存储仅适合完全二叉树，否则会造成很大的空间浪费
#include <iostream>
#include <cstdio>
using namespace std;
const int SIZE = 1e5;
int n; // 总结点个数
// 用0表示置空
int BiTree[SIZE] = {0}; // 从上到下，从左到右，并利用完全二叉树的编号性质
int lChild(int pos)
{
    if (pos > 0 && pos < SIZE / 2)
        return pos * 2;
    return 0;
}
int rChild(int pos)
{
    if (pos > 0 && pos < SIZE / 2)
        return pos * 2 + 1;
    return 0;
}
int parent(int pos)
{
    if (pos > 1 && pos < SIZE)
        return pos / 2;
    return 0;
}
// 前序遍历
void preOrder(int pos = 1)
{
    if (pos < SIZE && pos > 0)
    {
        if (BiTree[pos]) // 非空
        {
            printf("%d ", BiTree[pos]);
            preOrder(lChild(pos));
            preOrder(rChild(pos));
        }
    }
}
// 广度优先遍历：直接从头到尾遍历数组就行

int main()
{
    cin >> n;
    if (n >= SIZE)
    {
        printf("it is too big\n");
    }
    else
    {
        // 输入所有结点的编号和val
        for (int i = 1; i <= n; i++)
        {
            int pos, val;
            printf("please input positon and value\n");
            cin >> pos >> val;
            BiTree[pos] = val;
        }
    }
    preOrder();
    return 0;
}