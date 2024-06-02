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

    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << k << endl;
        return;
    }
    int now = 1;
    int first = 0;
    while (first + now < k) {
        first = first + now;
        now *= 2;
        debug(now);
    }
    cout << first << " " << k - first << " ";
    for (int i = 3; i <= n; i++) {
        cout << "0 " ;
    }
    cout << endl;
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
