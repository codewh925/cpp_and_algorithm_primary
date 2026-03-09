// 二进制枚举：子集问题
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> subset(vector<int> nums)
{
    vector<vector<int>> ret;
    int n = nums.size();
    for (int i = 0; i < (1 << n); i++) // 依次枚举0~2^n-1
    {
        vector<int> temp; // 临时数组，用于保存当前枚举下的子集
        // 确定当前i代表的子集（二进制的0代表空，1代表选）
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1) // i的二进制的第j位为1
                temp.push_back(nums[j]);
        }
        ret.push_back(temp);
    }
    return ret;
}
int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    vector<vector<int>> ret = subset(nums);
    while (ret.size())
    {
        vector<int> temp = ret.back();
        while (temp.size())
        {
            cout << temp.back() << " ";
            temp.pop_back();
        }
        ret.pop_back();
        cout << endl;
    }
    return 0;
}