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
    VII mp(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        mp[u].emplace_back(v);
        mp[v].emplace_back(u);
    }
    int cen;
    VI siz(n + 1, 1);
    function<void(int,int,int)> dfs = [&](int fa,int now,int x) {
        for (auto i: mp[now]) {
            if (i == fa)continue;
            dfs(now, i, x);
            siz[now] += siz[i];
        }
        if (siz[now] >= x) {
            siz[now] = 0;
            cen++;
        }
    };

    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        ranges::fill(siz, 1);
        cen = 0;

        dfs(0, 1, mid);
        debug(mid, cen);
        if (cen > k) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    cout << l << endl;;
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
