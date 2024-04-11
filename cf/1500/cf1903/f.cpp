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
template<typename T, typename Compare =less<>>
using pqinit = priority_queue<T, vector<T>, Compare>;

void init() {
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> satAdj(6 * n + 1);
    function<void(int, int, int)> build = [&](int q, int l, int r) {
        if (l == r) {
            satAdj[q].emplace_back(4 * n + l);
            return;
        }
        int mid = (l + r) / 2;
        satAdj[q].emplace_back(q << 1);
        satAdj[q].emplace_back(q << 1 | 1);
        build(q << 1, l, mid);
        build(q << 1 | 1, mid + 1, r);
    };
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        satAdj[4 * n + u].emplace_back(v + 5 * n);
        satAdj[4 * n + v].emplace_back(u + 5 * n);
    }
    build(1, 1, n);
    auto check = [&](int ka) {
        vector<vector<int>> mp = satAdj;
        function<void(int, int, int, int, int, int)> connect = [&](int id, int q, int l, int r, int L, int R) {
            if (R < L) return;
            if (L <= l && r <= R) {
                mp[id].emplace_back(q);
                return;
            }
            if (r < L || l > R)return;
            int mid = (l + r) >> 1;
            if (mid >= L) {
                connect(id, q << 1, l, mid, L, R);
            }
            if (mid < R) {
                connect(id, q << 1 | 1, mid + 1, r, L, R);
            }
        };

        for (int i = 1; i <= n; i++) {
            int l = max(1ll, i + 1 - ka);
            int r = min(n, i + ka - 1);
            connect(i + 5 * n, 1, 1, n, l, i - 1);
            connect(i + 5 * n, 1, 1, n, i + 1, r);
        }

        stack<int> s;
        int t = 0;
        int sc = 0;
        vector<int> dfn(6 * n + 1), low(6 * n + 1), scc(6 * n + 1), inStack(6 * n + 1);
        function<void(int)> dfs = [&](int u) {
            low[u] = ++t;
            dfn[u] = low[u];
            s.emplace(u);
            inStack[u] = 1;
            for (int v: mp[u]) {
                if (dfn[v] == 0) {
                    dfs(v);
                    low[u] = min(low[u], low[v]);
                } else if (inStack[v] == 1) {
                    low[u] = min(low[u], dfn[v]);
                }
            }
            if (dfn[u] == low[u]) {
                sc++;
                while (!s.empty() && s.top() != u) {
                    auto tt = s.top();
                    s.pop();
                    scc[tt] = sc;
                    inStack[tt] = 0;
                }
                scc[u] = sc;
                inStack[u] = 0;
                s.pop();
            }
        };
        for (int i = 1; i < 6 * n + 1; i++) {
            if (!dfn[i]) dfs(i);
        }
        for (int i = 1; i <= n; i++) {
            if (scc[i + 4 * n] == scc[i + 5 * n]) {
                return false;
            }
        }
        return true;
    };
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
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
