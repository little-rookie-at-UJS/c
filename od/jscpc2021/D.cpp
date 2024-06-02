#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define vv vector
typedef pair<int, int> p11;
#define per(a, b, c) for(int a = b; a <= c; a ++)
#define rep(a, b, c) for(int a = b; a >= c; a --)

vv<p11> ans;

void huahua(int n, int m)
{
    int cn = n / 4;
    per(k, 0, cn - 1)
    {
        int qin = k * 4 + 1;
        ans.pb(qin, 1);
        per(i, 2, m)
        {
            ans.pb(qin + 1, i);
            ans.pb(qin, i);
        }
        ans.pb(qin + 1, 1);
        ans.pb(qin + 2, m);
        rep(i, m - 1, 1)
        {
            ans.pb(qin + 3, i);
            ans.pb(qin + 2, i);
        }
        ans.pb(qin + 3, m);
    }
    if(n % 4 == 2)
    {
        int qin = cn * 4 + 1;
        ans.pb(qin, 1);
        per(i, 2, m)
        {
            ans.pb(qin + 1, i);
            ans.pb(qin, i);
        }
        ans.pb(qin + 1, 1);
    }
}

// void huahua2(int n, int m)
// {

// }

int main()
{
    int n, m;
    cin >> n >> m;
    bool fanzhuan = 0;
    if(m % 2 == 0 || n % 2 == 0)
    {
        if(n % 2 == 1 && m % 2 == 0)
            swap(n, m), fanzhuan = 1;
        huahua(n, m);
    }
//    else
//    {
//        huahua2(n, m);
//    }
    for(auto [x, y] : ans)
        cout << x << ' ' << y << endl;
//    if(fanzhuan)
//    {
//
//    }
    return 0;
}