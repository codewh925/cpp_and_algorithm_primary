#include <iostream>
using namespace std;
// val树结点
struct Node
{
    int val;
    int height;
    Node *left;
    Node *right;
};
// 生成新的结点，返回值为指向新结点的指针
Node *newNode(int val)
{
    Node *node = new Node;
    node->val = val;
    node->height = 1;
    node->left = node->right = nullptr;
    return node;
}

// 获取树的高度
int getHeight(Node *node)
{
    if (!node)
        return 0;
    return node->height;
}

// 获取平衡因子
int getBalance(Node *node)
{
    return getHeight(node->left) - getHeight(node->right);
}
// 左旋函数，返回指向新根的指针
Node *leftRoate(Node *root)
{
    if (!root)
        return nullptr;
    // 1，当前结点的右子树作为新树的根结点
    // 2，当前结点作为新的根结点的左子树
    // 3，如果原根的右子树（新根）有左子树，那么这个左子树作为原根的右子树

    Node *newroot = root->right;
    Node *tmp = newroot->left;
    newroot->left = root;
    root->right = tmp;
    // 更新树高
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    newroot->height = 1 + max(getHeight(newroot->left), getHeight(newroot->right));

    return newroot;
}

// 右旋函数，返回指向新根的指针
Node *rightRoate(Node *root)
{
    if (!root)
        return nullptr;
    // 1，root的左子树作为新的根
    // 2，root变成新根的右子树
    // 3，如果root的左子树有右子树，那么这个右子树变成root的左子树
    Node *newroot = root->left;
    Node *tmp = newroot->right;
    newroot->right = root;
    root->left = tmp;

    // 更新树高
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    newroot->height = 1 + max(getHeight(newroot->left), getHeight(newroot->right));

    return newroot;
}

// 插入结点函数
Node *insertNode(Node *root, int val)
{
    if (!root)
        return newNode(val);
    if (val < root->val)
        root->left = insertNode(root->left, val);
    else if (val > root->val)
        root->right = insertNode(root->right, val);
    else
        return root;
    // 更新树高
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // 获取平衡因子
    int balance = getBalance(root);

    // LL失衡
    if (balance > 1 && getBalance(root->left) > 0)
        return rightRoate(root);

    // LR失衡
    else if (balance > 1 && getBalance(root->left) < 0)
    {
        leftRoate(root->left);
        return rightRoate(root);
    }
    // RR失衡
    else if (balance < -1 && getBalance(root->right) < 0)
        return leftRoate(root);

    // RL失衡
    else if (balance < -1 && getBalance(root->right) > 0)
    {
        rightRoate(root->right);
        return leftRoate(root);
    }

    return root;
}

// 先序遍历
void preOrder(Node *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// 中序遍历
void midOrder(Node *root)
{
    if (!root)
        return;
    midOrder(root->left);
    cout << root->val << " ";
    midOrder(root->right);
}

// 查找函数
Node *findNode(Node *root, int val, int *cnt = 0)
{
    if (!root)
        return nullptr;
    Node *cur = root;
    while (cur)
    {
        if (val < cur->val)
        {
            cur = cur->left;
            (*cnt)++;
        }
        else if (val > cur->val)
        {
            cur = cur->right;
            (*cnt)++;
        }
        else
            return cur;
    }
    // 没找到
    return nullptr;
}

// 删除结点函数
Node *erase(Node *root, int val)
{
    if (!root)
        return nullptr;
    if (val < root->val)
        root->left = erase(root->left, val);
    else if (val > root->val)
        root->right = erase(root->right, val);
    else
    {
        // 1，是叶子结点
        if (!root->left && !root->right)
        {
            Node *tmp = root;
            delete tmp;
            root = nullptr;
        }
        // 2，只有左孩子
        else if (root->left && !root->right)
        {
            Node *tmp = root;
            root = root->left;
            delete tmp;
        }
        // 3，只有右孩子
        else if (!root->left && root->right)
        {
            Node *tmp = root;
            root = root->right;
            delete tmp;
        }
        // 4，左右孩子都有
        else
        {
            Node *cur = root->right;
            while (cur->left)
            {
                cur = cur->left;
            }
            root->val = cur->val;
            root->right = erase(root->right, root->val);
        }
    }
    if (!root)
        return root;
    // 更新树高
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // 获取平衡因子
    int balance = getBalance(root);
    // LL失衡
    if (balance > 1 && getBalance(root->left) > 0)
        return rightRoate(root);

    // LR失衡
    else if (balance > 1 && getBalance(root->left) < 0)
    {
        leftRoate(root->left);
        return rightRoate(root);
    }
    // RR失衡
    else if (balance < -1 && getBalance(root->right) < 0)
        return leftRoate(root);

    // RL失衡
    else if (balance < -1 && getBalance(root->right) > 0)
    {
        rightRoate(root->right);
        return leftRoate(root);
    }
    return root;
}