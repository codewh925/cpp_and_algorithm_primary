#include "avlTree.h"
void test()
{
    Node *root = nullptr;
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 60);
    root = insertNode(root, 70);

    int cnt = 0;
    Node *result = findNode(root, 70, &cnt);
    cout << "查找次数：" << cnt << endl;
    cout << "先序遍历结果：" << endl;
    preOrder(root);
    cout << endl;
    cout << "中序遍历结果: " << endl;
    midOrder(root);
    cout << endl;
    root = erase(root, 50);
    root = erase(root, 20);
    cout << "删除后的中序遍历结果: " << endl;
    midOrder(root);
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    test();
    return 0;
}