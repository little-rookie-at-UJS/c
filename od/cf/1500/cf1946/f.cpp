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
VII mp;
const int maxn = 1e6 + 7;

void init() {
    mp.resize(maxn);
    for (int i = 1; i < maxn; i++) {
        for (int j = i + i; j < maxn; j += i) {
            mp[j].emplace_back(i);
        }
    }
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1), loc(n + 1), fenwick(n + 1), ans(m + 1);
    vector<int> f(n + 1);
    auto add = [&](int q,int x) {
        while (q <= n) {
            fenwick[q] += x;
            q += q & -q;
            // debug(q);
        }
    };
    auto sum = [&](int q) {
        int ans = 0;
        while (q) {
            ans += fenwick[q];
            q -= q & -q;
            // debug(q);
        }
        return ans;
    };
    vector<vector<PII>> query(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        loc[arr[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        query[r].emplace_back(l, i);
    }
    for (int i = 1; i <= n; i++) {
        priority_queue<int> q;
        q.emplace(i);
        f[i] = 1;
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            int v = arr[t];
            for (auto j: mp[v]) {
                int len = loc[j];
                if (len < t) {
                    if (!f[len]) {
                        q.emplace(len);
                    }
                    f[len] += f[t];
                }
            }
            add(t, f[t]);
            f[t] = 0;
        }
        for (auto [l,j]: query[i]) {
            ans[j] = sum(n) - sum(l - 1);
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
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
