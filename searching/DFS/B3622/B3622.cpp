// 方法一：
//  // 字典序输出子集
//  #include <cstdio>
//  #include <iostream>
//  #include <string>
//  using namespace std;
//  int n;
//  string path;
//  void DFS(int pos)
//  {
//      if (pos >= n)
//      {
//          cout << path << endl;
//          return;
//      }
//      // 走决策树左
//      path += 'N';
//      DFS(pos + 1);
//      // 回溯
//      path.pop_back();
//      // 再走右边
//      path += 'Y';
//      DFS(pos + 1);
//      path.pop_back(); // 回溯
//  }
//  int main()
//  {
//      scanf("%d", &n);
//      int pos = 0;
//      DFS(pos);
//      return 0;
//  }

// 方法二：
#include <iostream>
#include <string>
using namespace std;
const int N = 1 << 10; // 递归最深为10
int a[N];              // 顺序存储满二叉树
int n;
string path;
void DFS(int pos)
{
    if (pos >= (1 << n))
    {
        cout << path << endl;
        return;
    }
    // 左孩子
    path += 'N';
    DFS(pos * 2);
    path.pop_back(); // 回溯
    // 右孩子
    path += 'Y';
    DFS(pos * 2 + 1);
    path.pop_back(); // 回溯
}
int main()
{
    cin >> n;
    DFS(1);
    return 0;
}