#include "rbTree.h"
using namespace std;
void test()
{
    int arr[] = {10, 50, 60, 62, 65, 70};
    rbTree *T = new rbTree;
    T->nil = new rbTNode;
    T->nil->color = BLACK;
    T->root = T->nil;
    // 插入结点
    for (int x : arr)
    {
        rbTNode *node = newNode(T, x);
        rbTreeInsert(T, node);
    }
    // 检查结果
    cout << "中序遍历：\n";
    midOrder(T, T->root);
    cout << "先序遍历：\n";
    preOrder(T, T->root);
}
int main()
{
    test();
    return 0;
}