#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, k;
vector<int> a;
int path;
int count;
bool isPrime(int n)
{
    bool ret = true;
    for (int i = 2; i <= (int)sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ret = false;
            break;
        }
    }
    return ret;
}
void dfs(int pos, int begin)
{
    if (pos > k)
    {
        if (isPrime(path))
            count++;
        return;
    }
    for (int i = begin; i < n; i++)
    {
        path += a[i];
        dfs(pos + 1, i + 1);
        path -= a[i];
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        a.push_back(num);
    }
    dfs(1, 0);
    /*for(int i=0;i<n;i++)
    {
        if(isPrime(a[i]))
            cout<<a[i]<<" ";
    }*/
    cout << count << endl;
    return 0;
}