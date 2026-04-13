#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int main()
{
    // 其实就是不会自动排序的map和set
    unordered_map<int, string> ump;
    unordered_set<int> ust;
    unordered_map<int, string> ump2 = {{1, "haha"}, {2, "hello"}};
    ump[1] = "zhenhao";
    ump.insert({2, "nihao"});
    ust.insert(1);
    // 当然还有迭代器，查找，状态判断等等
    return 0;
}