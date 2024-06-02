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
const int mod = 998244353;
template<typename T, typename Compare =less<>>
using pqinit = priority_queue<T, vector<T>, Compare>;


void init() {
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int sums = accumulate(a.begin(), a.end(), 0ll);
//    debug(sums);
    vector<int> dp(sums + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = sums; j >= a[i]; j--) {
            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
        }
    }
//    debug(dp);
    int ans = 0;
    for (int i = 1; i <= sums; i++) {
        ans = (ans + (i + 1) / 2 * dp[i] % mod) % mod;
//        debug((i + 1) / 2 , dp[i] ,i);
    }
//    debug(ans);
    for (auto i: a) {
        for (int j = 0; j <= i; j++) {
            ans = (ans - ((i + j + 1) / 2 *dp[j] ) % mod + mod) % mod;

            ans = (ans + i * dp[j] % mod) % mod;
        }
    }
    cout << ans << endl;

}

signed main() {
    IOS;
    init();
    // debug(1);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}
