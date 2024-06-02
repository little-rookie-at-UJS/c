#include "bits/stdc++.h"

using namespace std;

#ifndef ONLINE_JUDGE
#include "test.h"
#include "dbg.h"
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

// int n = 20;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)cin >> v[i];
    int k = (v[1] - v[n] + n) % n;
    for (int i = 1; i < n; i++) {
        if ((v[i] + k) % n != v[i + 1]) {
            cout << -1 << endl;
            return;
        }
    }
    if (k != 0) {
        if (v[1] == 0)cout << k << endl;
        else
            cout << k + 1 << endl;
    }
    else if (v[1] == 0) cout << 0 << endl;
    else cout << n + 1 << endl;
}

signed main() {
    IOS;
    init();
    // debug(1);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
