// 一，采用差分数组定义法
//  #include<iostream>
//  using namespace std;
//  const int N=1e5+10;
//  int a[N];
//  int f[N];
//  int main()
//  {
//      int n;
//      cin>>n;
//      for(int i=1;i<=n;i++)
//          cin>>a[i];
//      //1，预处理差分数组
//      for(int i=1;i<=n;i++)
//          f[i]=a[i]-a[i-1];
//      //2，处理差分数组
//      int q;
//      cin>>q;
//      for(int i=1;i<=q;i++)
//      {
//          int l,r,k;
//          cin>>l>>r>>k;
//          f[l]+=k,f[r+1]-=k;//中间的数据都加上了K，差不变
//      }
//      //3，还原至原数组
//      for(int i=1;i<=n;i++)
//      {
//          a[i]=f[i]+a[i-1];
//      }
//      //4，输出结果
//      for(int i=1;i<=n;i++)
//          cout<<a[i]<<" ";
//      cout<<endl;
//      return 0;
//  }
// 二，不额外开辟差分数组，采用差分的性质原地进行差分预处理
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main()
{
    int n;
    cin >> n;
    // 1，原地差分
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        a[i] += num, a[i + 1] -= num; // 原地差分，输入一个值时，a[i]处增加，a[i+1]减小（因为差变小）
    }
    // 2，输入操作
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        a[l] += k, a[r + 1] -= k;
    }
    // 3，前缀和逆运算获取原数据
    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}