#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using LL = long long;
vector<pair<LL, LL>> xy;
bool pass[60];
LL x_0, y_0, ax, ay, bx, by, xs, ys, t;
void initXy()
{
    xy.push_back({x_0, y_0});
    LL xi = x_0;
    LL yi = y_0;
    for (int i = 1; i < 60; i++)
    {
        xi = ax * xi + bx;
        yi = ay * yi + by;
        xy.push_back({xi, yi});
    }
}
LL len(pair<LL, LL> a, pair<LL, LL> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}
pair<LL, LL> nearst(pair<LL, LL> ds, int &pos)
{
    pair<LL, LL> ret=xy[59];

    for (int i = 0; i < 60; i++)
    {
        if (len(xy[i], ds) < len(ret, ds) && pass[i] == false)
        {
            pos = i;
            ret = xy[i];
        }
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> x_0 >> y_0 >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;

    initXy();

    LL time = 0;
    int pos = 0;
    pair<LL, LL> tmp = nearst({xs, ys}, pos);
    pair<LL, LL> cur = {xs, ys};
    int cnt = 0;
    while (1)
    {
        LL dif = len(cur, tmp);
        if (dif + time > t)
            break;
        time += dif;
        cnt++;
        pass[pos] = true;

        cur = tmp;
        tmp = nearst(tmp, pos);
    }
    cout << cnt << endl;
    return 0;
}