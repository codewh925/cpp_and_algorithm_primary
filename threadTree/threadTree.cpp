#include <iostream>
using namespace std;

using PointerTag = enum { Link,
                          Thread };
// Link表示左右指针指向孩子
// Thread表示左右指针指向前驱和后继
struct BiThrNode
{
    int data;
    BiThrNode *left, *right;
    PointerTag LTag;
    PointerTag RTag;
};

// 二叉树中序线索化的实现
BiThrNode *pre; // 记录前驱
void InThreading(BiThrNode *p)
{
    if (p)
    {
        // 左子树线索化
        InThreading(p->left);

        // 当前结点线索化
        if (!p->left)
        {
            p->LTag = Thread;
            p->left = pre;
        }
        if (!pre->right)
        {
            pre->RTag = Thread;
            pre->right = p;
        }
        // 更新前驱
        pre = p;

        // 右子树线索化
        InThreading(p->right);
    }
}

// 线索二叉树的遍历
// T指向头结点，T->left = root,T->right = nail
// first->left = T,nail->right = T
void InOrderThr(BiThrNode *T)
{
    BiThrNode *p;
    p = T->left; // 根
    while (p != T)
    {
        // 沿着左子树一直走
        while (p->LTag == Link)
            p = p->left;
        // 访问
        cout << p->data << " ";

        // 直接利用后继
        while (p->RTag == Thread && p->right != T)
        {
            p = p->right;
            cout << p->data << " ";
        }

        //进入右子树
        p = p->right;
    }
}