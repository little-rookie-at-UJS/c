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


class Graph {
private:
    int n;
    // 原图
    vector<vector<int>> adj;

    //缩点 n-->scc
    vector<int> scc;

    // 缩点后的图
    vector<vector<int>> adj2;

    vector<int> dfn, low, ish, du, vis, ans;
    stack<int> s;
    int sccc, tot;

    // tarjan
    void dfs(int x) {
        dfn[x] = low[x] = tot++;
        scc[x] = -1;
        s.emplace(x);
        for (auto i: adj[x]) {
            if (!dfn[i]) {
                dfs(i);
                low[x] = min(low[x], low[i]);
            } else if (scc[i] == -1) {
                low[x] = min(low[x], dfn[i]);
            }
        }
        if (dfn[x] == low[x]) {
            while (1) {
                auto t = s.top();
                s.pop();
                scc[t] = sccc;
                if (t == x)break;
            }
            sccc++;
        }

    }


    // dfs 求度数

    void dfs2(int x) {
        vis[x] = 1;
        for (auto i: adj2[x]) {
            du[i]++;
            if (!vis[i]) dfs2(i);
        }
    }

public:
    Graph(int n) : n(n), adj(n + 1), scc(n + 1), dfn(n + 1), low(n + 1), tot(1), sccc(1) {};
    void add_edge(int x, int y) {
        adj[x].emplace_back(y);
    }
    void rebuild() {
        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) {
                dfs(i);
            }
        }

        adj2.resize(sccc);
        ish.resize(sccc);
        du =vis = ans = ish ;

        for (int i = 1; i <= n; i++) {
            for (auto j: adj[i]) {
                if (scc[i] == scc[j]) {
                    ish[scc[i]] = 1;
                } else {
                    adj2[scc[i]].emplace_back(scc[j]);

                }
            }
        }
        dfs2(scc[1]);

        s = stack<int>();
        s.emplace(scc[1]);
        ans[scc[1]] = 1;
        if (ish[scc[1]]) ans[scc[1]] = -1;
        while (!s.empty()) {
            auto x = s.top();
            s.pop();
            if (ish[x]) ans[x] = -1;
            for (auto i: adj2[x]) {
                if (ans[x] < 0) {
                    ans[i] = -1;
                } else if (ans[i] >= 0) {
                    ans[i] += ans[x];
                    ans[i] %= mod;
                }
                du[i]--;
                if (du[i] == 0) {
                    s.emplace(i);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << (ans[scc[i]] > 1 ? 2 : ans[scc[i]]) << " ";
        }
        cout << endl;
    }


};

void solve() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g.add_edge(u, v);
    }
    g.rebuild();
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
