#include <iostream>
using namespace std;
const int M = 1e6 + 10;
int f[M];
int main()
{
    int N, K;
    cin >> N >> K;
    f[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (i - j < 0)
                break;
            f[i] += f[i - j];
        }
        f[i] %= 100003;
    }
    cout << f[N] << endl;
    return 0;
}