#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    // 如：
    // int a[]={1,2,2,2,3,4,5,6,6,8};
    // int* left=lower_bound(a,a+10,6);//返回值为第一个出现的第三个参数的迭代器，类似与begin()一样
    // int* right=upper_bound(a,a+10,6)-1;//返回值为最后一个出现的第三个参数的迭代器的下一位，类似于end()一样
    int n, target;
    cin >> n >> target;
    vector<int> a;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        a.push_back(num);
    }
    // lower_bound返回第一个不小于target的
    // upper_bound返回第一个大于target的
    int left = lower_bound(a.begin(), a.end(), target) - a.begin();
    int right = upper_bound(a.begin(), a.end(), target) - 1 - a.begin();

    return 0;
}