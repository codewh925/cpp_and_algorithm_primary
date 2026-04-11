#include <bitset>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    bitset<4> bs1;     // 0000
    bitset<4> bs2 = 5; // 0101
    bitset<5> bs3("10110");
    string s = "100100";
    bitset<4> bs4(s, 0, 4); // 1001

    bs1.set(1);   // 0010
    bs1.set();    // 1111
    bs1.reset(0); // 1110
    bs1.reset();  // 0000
    unsigned long num = bs1.to_ulong();
    if (isalnum(num))
        cout << "is alpha or number" << endl;
    if (isalpha(s[0]))
        cout << "is alpha" << endl;
    // 此外，还有islower()判断小写字母，isupper()判断大写字母
    // tolower()将字母转换为小写字母，toupper()将字母转换为大写字母

    // biset支持整体位运算
    bs1.flip(); // 1111
    bitset<4> result = bs1 & bs2;
    cout << result << endl; // 0101
    for (int i = 0; i < 4; i++)
        cout << result[i] << " "; // 1010，倒序输出
    cout << endl;

    return 0;
}