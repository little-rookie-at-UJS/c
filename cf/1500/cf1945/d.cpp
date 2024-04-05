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
    int n, k, now;
    cin >> n >> k;
    now = n + 1;
    vector<PII> arr(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].second;
    }
    int sums = 0;
    int ans = 1e18;
    // int sums = arr[k].first;
    for (int i = k + 1; i <= n; i++) {
        sums += min(arr[i].first, arr[i].second);
    }
    for (int i = k; i > 0; i--) {
        ans = min(ans, sums + arr[i].first);
        sums += min(arr[i].first, arr[i].second);
    }
    cout << ans << endl;

    // cout << sums << endl;
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
