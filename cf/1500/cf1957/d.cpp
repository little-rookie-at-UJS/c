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
//#define int ll

using VI = vector<int>;
using VII = vector<VI>;
using PII = pair<int, int>;
const int inf = 1e18;
const int mod = 1e9 + 7;

void init() {
}


void solve() {

    int n;

    cin >> n;
//    vector<vector<vector<int>>>
//            a(n + 2, vector<vector<int>>(32, vector<int>(2)));
//    vector<vector<vector<int>>> b = a;
    vector<vector<int>>
            a(n + 2, vector<int>(32));
    auto b = a;
    vector<int> arr(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        a[i] = a[i - 1];
        for (int j = 30; j >= 0; j--) {
            bool f = (arr[i] >> j) & 1;
            if (f) {
                a[i][j] = i - a[i][j];
            }

        }
    }

    for (int i = n; i; i--) {
        b[i] = b[i + 1];
        for (int j = 30; j >= 0; j--) {
            bool f = (arr[i] >> j) & 1;
            if (f) {
                b[i][j] = n - i + 1 - b[i][j];
            }
        }
    }
    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        int j = __lg(arr[i]);
        ll l1 = a[i][j];
        ll l2 = i - l1;
        ll r1 = b[i][j];
        ll r2 = n - i + 1 - r1;
        ans += l1 * r2 + l2 * r1;
        debug(j, l1, l2, r1, r2);
    }
    cout << ans << endl;
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
