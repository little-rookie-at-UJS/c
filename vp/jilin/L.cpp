//
// Created by DELLPC on 24-5-19.
//
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;

#define  endl '\n'
//2
//7
//4 6 1
//12 14 2
//5 11 3
//1 6 4
//11 13 4
//4 7 5
//3 5 6
//4 7
//1
//2 4 2
//2 5

void solve() {
    i64 k, x, y;
    cin >> k >> x >> y;
    i64 t1 = k / 2;
    i64 t2 = k % 2;
    if (k == 1) {
        cout << x + y << endl;
    } else if (t2 == 0) {
        cout << (x + 2 * y) / k << endl;
    } else {
        i64 mintimes = min(x, y / t1);
        i64 cnt = mintimes;
        x -= mintimes;
        y -= mintimes * t1;
        if (!x) {
            cnt += (y / (t1 + 1));
        } else {
            cnt += (x + 2 * y) / k;
        }
        cout << cnt << endl;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

