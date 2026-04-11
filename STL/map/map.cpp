#include <map>
#include <iostream>
using namespace std;
int main()
{
    // 创建
    // map只要使用了[]就会创建一个键或者覆盖原有值
    map<int, string> mp1; // key:int,value:string
    map<string, int> mp2; // key:string,value:int
    // 插入
    mp1[1] = "haha";
    mp1[2] = "hello";
    mp1.insert({3, "world"}); // 就像pair一样成双成对
    mp2["a"] = 10086;
    mp2["b"] = 9178;
    // 迭代器或范围for
    for (auto i = mp1.begin(); i != mp1.end(); i++)
        cout << i->first << "：" << i->second << endl;
    for (auto i = mp2.begin(); i != mp2.end(); i++)
        cout << i->first << "：" << i->second << endl;
    // 查找
    auto it = mp1.find(1); // 失败返回end
    if (it != mp1.end())
        cout << it->second << endl;
    // 删除（使用键或者迭代器）
    mp2.erase("a");
    mp1.erase(it); // 迭代器更快
    // 判空
    mp1.size();
    mp1.empty();
    //当然还有swap
    return 0;
}