//
// Created by DELLPC on 2024/3/27.
//
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll llinf = 4e18;
using i64 = long long;
ll calc(ll b, ll step) {
    // ++ step;
    ll e = (b + step - 1);
    return (b + e) * step / 2;
}
#define LD long double
#define IOS ios::sync_with_stdio(0),cin.tie(0)
ll work(ll x, ll y) {
    ll sum = 0;
    ll bg = floor(sqrtl(2.00 * x) + 1.50);
    LD n0 = 0.50 * (1.0 - 2.0 * bg + sqrtl((LD)1.00 * (2 * bg - 1) * (2 * bg - 1) + 8.00 * (1.0 * y - x)));
    n0 = ceil(n0);
    while(calc(bg, n0) - (y - x) < 0)++ n0;
    while(calc(bg, n0 - 1) - (y - x) >= 0)-- n0;
    sum = n0 + calc(bg, n0) - (y - x);
    return sum;
}
void solve() {
    ll x, y;
    cin >> x >> y;
    if(x >= y) {
        cout << x - y << '\n';
        return;
    }
    ll ans = llinf;
    ans = min(ans, work(x, y));
    ll bg = floor(sqrtl(2.00 * x) + 1.50);

    LD X = 0.50 * (1.0 * bg - 1.5) * (1.0 * bg - 1.5);
    ll x1 = ceil(X);
    while(floor(sqrtl(2.00 * x1) + 1.50) == bg)
        -- x1;
    ans = min(ans, work(x1, y) + (x - x1));
    cout << ans << '\n';


}
int main() {
    // IOS;
    // for(ll x = 100000000; x <= 100000000000000; ++ x) {
    //     int lst = floor(sqrtl(2.0 * x) + 1.5) - 1;
    //     while(x <= 1e18) {
    //         ll dt = floor(sqrtl(2.0 * x) + 1.5);
    //         if(dt - 1 != lst) {
    //             cerr << x << endl;
    //         }
    //         lst = dt;
    //         x += dt;
    //     }
    // }
    // // 9007199590285315
    // return 0;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
