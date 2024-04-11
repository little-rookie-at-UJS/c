#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

#ifndef ONLINE_JUDGE

#include "test.h"

#else
#define debug(...) 42
#define debug_assert(...) 42
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> satAdj(6 * n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        debug(x, y);
        satAdj[x + 4 * n].push_back(y + 5 * n);
        satAdj[y + 4 * n].push_back(x + 5 * n);
    }

    function<void(int, int, int)> init = [&](int id, int l, int r) {
        if (l == r) {
            satAdj[id].push_back(l + 4 * n);
            debug(id, l);
        } else {
            int mid = (l + r) >> 1;
            satAdj[id].push_back(2 * id);
            satAdj[id].push_back(2 * id + 1);
            init(2 * id, l, mid);
            init(2 * id + 1, mid + 1, r);
        }
    };
    init(1, 0, n - 1);

    auto check = [&](int d) -> bool {
        vector<vector<int>> adj = satAdj;
        function<void(int, int, int, int, int, int)> build =
                [&](int id, int u, int ql, int qr, int l, int r) {
                    if (ql > qr) return;
                    if (ql <= l && r <= qr) {
//                        debug(u - 5 * n, id);
                        adj[u].push_back(id);
                    } else {
                        int mid = (l + r) >> 1;
                        if (ql <= mid) build(2 * id, u, ql, qr, l, mid);
                        if (qr > mid) build(2 * id + 1, u, ql, qr, mid + 1, r);
                    }
                };
//        cerr << "d = " << d << endl;
        for (int i = 0; i < n; i++) {
            int l = max(0, i + 1 - d);
            int r = min(n - 1, i + d - 1);
//            debug(i, l, r);
            build(1, i + 5 * n, l, i - 1, 0, n - 1);
            build(1, i + 5 * n, i + 1, r, 0, n - 1);
        }
        bool ans = true;
        vector<int> dfn(6 * n, 0);
        vector<int> low = dfn;
        vector<int> scc = dfn;
        vector<int> s;
        vector<int> inStack = dfn;
        int time = 0;
        int sc = 0;
        function<void(int)> tarjan = [&](int u) {
            low[u] = ++time;
            dfn[u] = low[u];
            s.push_back(u);
            inStack[u] = 1;
            for (int v: adj[u]) {
                // cout << u << ":" << v << "\n";
                if (dfn[v] == 0) {
                    tarjan(v);
                    low[u] = min(low[u], low[v]);
                } else if (inStack[v] == 1) {
                    low[u] = min(low[u], dfn[v]);
                }
            }
            if (dfn[u] == low[u]) {
                ++sc;
                while (s.back() != u) {
                    scc[s.back()] = sc;
                    inStack[s.back()] = 0;
                    s.pop_back();
                }
                scc[s.back()] = sc;
                inStack[s.back()] = 0;
                s.pop_back();
            }
        };
        for (int i = 0; i < 6 * n; i++) {
            if (dfn[i] == 0) { tarjan(i); }
        }
//        debug(scc);
        for (int i = 0; i < n; i++) {
//            debug(i, scc[i + 4 * n], scc[i + 5 * n]);
            if (scc[i + 4 * n] == scc[i + 5 * n]) { ans = false; }
        }
        return ans;
    };
    int l = 1, r = n;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
//        debug(mid);
        if (check(mid)) {
            ans = mid;
//            debug(ans, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}