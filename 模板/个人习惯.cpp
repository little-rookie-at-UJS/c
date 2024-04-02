#include "bits/stdc++.h"

using namespace std;

#ifndef ONLINE_JUDGE

#include "test.h"

#else
#define debug(...) 42
#define debug_assert(...) 42
#endif


#define IOS ios::sync_with_stdio(0),cin.tie(0)

using ll = long long;
using ull = unsigned long long;

#define endl '\n'
#define int ll

using VI = vector<int>;
using VII = vector<VI>;
using PII = pair<int, int>;
const int inf = 1e18;
const int mod = 1e9 + 7;

void init() {
}


void solve() {


    while (l < r) {
        int mid = (l + r) / 2;
        if (
                check(mid)
                <= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (
                check(mid)
                > k) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
}

signed main() {
    IOS;
    init();
    // debug(1);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}