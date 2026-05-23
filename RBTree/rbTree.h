#pragma once
#include <iostream>
#define KeyType int
#define BLACK 2
#define RED 1
struct rbTNode
{
    unsigned char color; // 红色是1，黑色是2
    KeyType key;
    rbTNode *left;
    rbTNode *right;
    rbTNode *parent;
    void *val; // 用不到
};
struct rbTree
{
    rbTNode *root;
    rbTNode *nil; // 叶子结点（外部结点，虽是NULL，但仍需空间赋值颜色）
};
// 生成新结点
rbTNode *newNode(rbTree *T, KeyType key)
{
    rbTNode *newNode = new rbTNode;
    newNode->color = RED; // 所有新插入的结点颜色都是红色
    newNode->key = key;
    newNode->val = NULL;
    newNode->left = T->nil;
    newNode->right = T->nil;
    newNode->parent = T->nil;
    return newNode;
}
// 左旋函数
void leftRotate(rbTree *T, rbTNode *root)
{
    rbTNode *newroot = root->right;
    rbTNode *T2 = newroot->left;

    root->right = T2;

    // 修改父节点
    if (T2 != T->nil)
        T2->parent = root;
    // 原根若是树根
    if (root->parent == T->nil)
        T->root = newroot;
    else if (root->parent->left == root)
        root->parent->left = newroot;
    else if (root->parent->right == root)
        root->parent->right = newroot;

    newroot->parent = root->parent;

    newroot->left = root;
    root->parent = newroot;
}
// 右旋函数
void rightRotate(rbTree *T, rbTNode *root)
{
    rbTNode *newroot = root->left;
    rbTNode *T2 = newroot->right;

    root->left = T2;

    // 修改父节点
    if (T2 != T->nil)
        T2->parent = root;
    // 原根若是树根
    if (root->parent == T->nil)
        T->root = newroot;
    else if (root->parent->left == root)
        root->parent->left = newroot;
    else if(root->parent->right == root)
        root->parent->right = newroot;

    newroot->parent = root->parent;
    newroot->right = root;
    root->parent = newroot;
}
// 调整平衡函数
void rbTFixup(rbTree *T, rbTNode *u)
{
    // 只有当u的父节点的颜色为红色时才需要调整
    while (u->parent->color == RED)
    {
        // Lxx:
        if (u->parent == u->parent->parent->left)
        {
            // 获取u的叔父结点y
            rbTNode *y = u->parent->parent->right;
            // Lxr：只需变色
            /*
            1，u的父节点变黑
            2，u的叔父结点变黑
            3，u的祖父节点变红
            4，以u的祖父结点为新的u继续向上检查
            */
            if (y->color == RED)
            {
                u->parent->color = BLACK;
                y->color = BLACK;
                y->parent->color = RED;
                u=y->parent;
            }
            // LXb:旋转+变色
            else if (y->color == BLACK)
            {
                // LRb
                /*
                1，先对u的父节点为根的子树进行左旋，转换为LLb：pu变成u
                2，u(原pu)的父节点变成黑色
                3，u的祖父结点变成红色
                4，对以u的祖父结点为根的子树进行右旋
                */
                if (u == u->parent->right)
                {
                    // 调整为LLb
                    u = u->parent;
                    leftRotate(T, u);
                }
                // LLb
                /*
                1，u的父节点变为黑色
                2，u的祖父结点变为红色
                3，对u的祖父结点为根的子树进行右旋
                */
                u->parent->color = BLACK;
                u->parent->parent->color = RED;
                rightRotate(T, u->parent->parent);
            }
        }
        // Rxx:
        else
        {
            // 获取u的叔父结点y
            rbTNode *y = u->parent->parent->left;
            // Rxr：只需变色
            /*
            1，u的父节点变黑
            2，u的叔父结点变黑
            3，u的祖父节点变红
            4，以u的祖父结点为新的u继续向上检查
            */
            if (y->color == RED)
            {
                u->parent->color = BLACK;
                y->color = BLACK;
                y->parent->color = RED;
                u=y->parent;
            }
            // RXb:旋转+变色
            else if (y->color == BLACK)
            {
                // RLb
                /*
                1，先对u的父节点为根的子树进行右旋，转换为LLb：pu变成u
                2，u(原pu)的父节点变成黑色
                3，u的祖父结点变成红色
                4，对以u的祖父结点为根的子树进行左旋
                */
                if (u == u->parent->left)
                {
                    // 调整为RRb
                    u = u->parent;
                    rightRotate(T, u);
                }
                // RRb
                /*
                1，u的父节点变为黑色
                2，u的祖父结点变为红色
                3，对u的祖父结点为根的子树进行左旋
                */
                u->parent->color = BLACK;
                u->parent->parent->color = RED;
                leftRotate(T, u->parent->parent);
            }
        }
    }
    T->root->color = BLACK;
}
// 插入新结点函数
void rbTreeInsert(rbTree *T, rbTNode *z)
{
    rbTNode *y = T->nil;
    rbTNode *x = T->root;

    // 定位，x最终为z要插入的位置
    while (x != T->nil)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else if (z->key > x->key)
            x = x->right;
        else
            return;
    }

    // z的父节点
    z->parent = y;

    // z插入
    if (y == T->nil) // x是树根的位置
        T->root = z;
    else if (z->key < y->key)
        y->left = z;
    else if (z->key > y->key)
        y->right = z;

    // 插入后的平衡调整
    rbTFixup(T, z);
}

// 先序遍历
void preOrder(rbTree *T, rbTNode *node)
{
    if (node == T->nil)
        return;
    std::cout << "key:" << node->key << " color:" << (node->color == 1 ? "红色" : "黑色") << '\n';
    preOrder(T, node->left);
    preOrder(T, node->right);
}
// 中序遍历
void midOrder(rbTree *T, rbTNode *node)
{
    if (node == T->nil)
        return;
    midOrder(T, node->left);
    std::cout << "key:" << node->key << " color:" << (node->color == 1 ? "红色" : "黑色") << '\n';

    midOrder(T, node->right);
}