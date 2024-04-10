//
// Created by DELLPC on 24-4-10.
//
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 x, y, n;
    cin >>x >> y >>n;

    cout << min((n + x + y - 1) / (x + y) * 3 * x, (n) / (x + y) * 3 * x + n % (x + y) * 3)<<endl;
}

int main() {
    int t;
    cin >>t;
    while(t--) {
        solve();
    }
    return 0;
}
