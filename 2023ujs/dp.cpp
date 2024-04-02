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
const int mod = 998244353;

void init() {
}


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ys(k + 10), nex(k + 10), val(k + 10);
    VII mp(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        mp[u].emplace_back(v);
        mp[v].emplace_back(u);
    }
    function<vector<pair<int,int>>(int,int)> dfs = [&](int f,int l) {
        vector<PII> dp = {{1, 1}};
        int len = 1;
        for (auto i: mp[l]) {
            if (i == f)continue;
            auto ans = dfs(l, i);
            for (auto [l1,v1]: dp) {
                for (auto [l2,v2]: ans) {
                    if (l1 + l2 <= k + 1) {
                        if (!ys[l1 + l2]) {
                            ys[l1 + l2] = len;
                            nex[len] = l1 + l2;
                            len++;
                        }
                        val[ys[l1 + l2]] = (val[ys[l1 + l2]] + (v1 * v2) % mod) % mod;
                    }
                }
            }
            vector<PII> mdp;
            for (int j = 1; j < len; j++) {
                mdp.emplace_back(nex[j], val[j]);
                val[j] = 0;
                ys[nex[j]] = 0;
                nex[j] = 0;
            }
            len = 1;
            dp = mdp;
        }
        int n0 = -1, nk = -1, nkk = -1;
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i].first == 0) {
                n0 = i;
            }
            else if (dp[i].first == k) {
                nk = i;
            }
            else if (dp[i].first == k + 1) {
                nkk = i;
            }
        }
        if (nk != -1 || nkk != -1) {
            if (n0 == -1) {
                dp.emplace_back(0, 0);
                n0 = dp.size() - 1;
            }
            dp[n0].second = ((dp[n0].second + ((nk == -1)
                                                   ? 0ll
                                                   : dp[nk].second) +
                              ((nkk == -1)
                                   ? 0ll
                                   : dp[nkk].second))) % mod;
        }
        if (nkk != -1) {
            swap(dp[nkk], dp.back());
            dp.pop_back();
        }
        debug(l, dp);
        return dp;
    };
    auto ans = dfs(0, 1);
    debug(ans);
    for (auto [i,j]: ans) {
        if (i == 0) {
            cout << j << endl;
            return;
        }
    }
    cout << 0 << endl;
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

// 11 1
//  11 10
//  1 4
//  9 10
//  8 4
//  3 6
//  5 7
//  6 1
//  10 2
//  11 7
//  11 1