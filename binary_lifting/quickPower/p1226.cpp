// 快速幂：求a^b%p
#include <iostream>
#include <cstdio>
using namespace std;
long long qPower(long long a, long long b, long long p)
{
    long long ret = 1;
    // 用b的二进制序列结合倍增快速求出a^b
    while (b)
    {
        if (b & 1)
            ret = ret * a % p;
        a = a * a % p; // 倍增
        b >>= 1;
    }
    // 以上while循环内便是倍增/快速幂的写法，用了取模运算的性质
    return ret;
}
int main()
{
    long long a, b, p;
    cin >> a >> b >> p;
    long long ret = qPower(a, b, p);
    printf("%lld ^ %lld mod %lld = %lld", a, b, p, ret);
    return 0;
}