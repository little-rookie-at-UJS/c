//
// Created by DELLPC on 24-5-19.
//
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;

#define  endl '\n'


void solve() {
    int n, k;
    cin >> n >> k;
    vector<i64> a(n);
    for (auto &i: a)cin >> i;
    sort(a.begin(), a.end(), [&](int u, int v) {
        return (k - u % k) < (k - v % k);
    });
    int m;
    cin >> m;
    for (auto &i: a) {
        i64 ned = (k - i % k);
        cerr << ned << endl;
        if (ned <= m) {
            i += ned;
            m -= ned;

        }
    }
    i64 ans = 0;
    for (auto &i: a) {
        ans += i / k;
    }
    ans += m / k;
    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}


