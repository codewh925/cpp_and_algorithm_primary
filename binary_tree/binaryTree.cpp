// 二叉树的链式存储和遍历
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
// 链式存储
struct BiTNode
{
    int data;
    BiTNode *lchild;
    BiTNode *rchild;
    BiTNode *parent;
};
class BiTree
{
private:
    BiTNode *root;

public:
    // 采用递归自动连接一颗二叉树
    void creatBiTree(BiTNode **rt = nullptr, BiTNode *parent = nullptr)
    {
        int val;
        cin >> val;
        //-1代表NULL
        if (val == -1)
            *rt = nullptr;
        else
        {
            // 使用二级指针是为了将函数内的修改传递回原变量（也可以用一级指针的引用）
            if (!rt) // 第一次进入函数
            {
                BiTNode *newNode = creatNode(val);
                rt = &newNode;
                root = newNode;
            }
            else
            {
                BiTNode *newNode = creatNode(val);
                *rt = newNode;
            }
            (*rt)->parent = parent;
            // 先构建左子树，再构建右子树
            creatBiTree(&((*rt)->lchild), *rt);
            creatBiTree(&((*rt)->rchild), *rt);
        }
    }
    // 创建结点，可以用于后续手动连接，也可以用于自动连接
    BiTNode *creatNode(int val)
    {
        BiTNode *newNode = new BiTNode;
        newNode->data = val;
        return newNode;
    }
    BiTNode *getRoot()
    {
        return root;
    }
    void destoryTree(BiTNode *rt)
    {
        if (!rt)
            return;
        BiTNode *cur1 = rt->lchild;
        BiTNode *cur2 = rt->rchild;
        delete rt;
        destoryTree(cur1);
        destoryTree(cur2);
    }
    // 前序遍历
    void preOrder(BiTNode *rt)
    {
        if (!rt) // 防止对空指针进行解引用
            return;
        printf("%d ", rt->data);
        preOrder(rt->lchild);
        preOrder(rt->rchild);
    }
    // 广度优先遍历
    void bfs()
    {
        BiTNode *rt = getRoot();
        if (!rt) // 空树
            return;
        vector<BiTNode *> vt;
        // 根结点进队
        vt.push_back(rt);
        while (vt.size())
        {
            // 取队顶
            BiTNode *h = vt.front();
            // 对顶孩子入队
            if (h->lchild && h->rchild) // 确保非空
            {
                vt.push_back(h->lchild);
                vt.push_back(h->rchild);
            }
            // 对顶出队
            cout << vt.front()->data << " ";
            vt.pop_back();
        }
    }
};
int main()
{
    BiTree bt1;
    bt1.creatBiTree();
    BiTNode *root = bt1.getRoot();
    bt1.preOrder(root);
    bt1.destoryTree(root);
    return 0;
}