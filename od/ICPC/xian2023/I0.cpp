//
// Created by DELLPC on 2024/3/27.
//
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    i64 x, y;
    cin >> x >> y;
    if(x >= y)
        cout << x - y << endl;
    else {
        i64 x1 = x, x2 = x - 1;
        i64 cnt1 = 0, cnt2 = 1;
        while(x1 < y) {
            x1 += sqrt(2 * x1 ) + 1.5;

            cnt1++;
        }
        cnt1 += x1 - y;
        while(x2 < y) {
            x2 += sqrt(2 * x2 ) + 1.5;
            cnt2++;
        }
        cnt2 += x2 - y;
        cout << min(cnt1, cnt2) << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
