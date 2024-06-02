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

//
struct Graph {
private:
    vector<vector<pair<int, int>>> adj;
public:
    Graph(int n) {
        adj.resize(n + 1);
    }

    //
    void add_edge(int u, int v, int w) {
        adj[u].emplace_back(v, w);
    }

    vector<int> dij(int k, int n) {
        vector<int> dis(n + 1, inf);
        dis[k] = 0;
        pqinit<pair<int, int>, greater<>> pq;
        pq.emplace(k, 0);
        while (!pq.empty()) {
            auto [u, dis1] = pq.top();
            pq.pop();
            if (dis1 > dis[u]) continue;
            for (auto [v, w]: adj[u]) {
                if (w + dis1 < dis[v]) {
                    dis[v] = w + dis1;
                    pq.emplace(v, w + dis1);
                }
            }
        }
        return dis;
    };
};


struct TGraph {
private:
    vector<vector<pair<int, int>>> adj;
    map<int, int> edge;
    vector<int> vis, dfn, low;
    vector<int> fa;
    stack<int> s;

    int tot = 0;

public:
    set<int> ans;

    TGraph(int n) : dfn(n + 1), adj(n + 1), vis(n + 1), low(n + 1), fa(n + 1) {
        tot = 1;
    }

    void add_edge(int u, int v, int id) {
        adj[u].emplace_back(v, id);
        adj[v].emplace_back(u, id);
        edge[id]++;
    }

    void dfs(int u) {
        dfn[u] = low[u] = tot;
        tot++;
        vis[u] = 1;
        s.emplace(u);
        for (auto [i,id]: adj[u]) {
            if (!dfn[i]) {
                fa[i] = u;
                dfs(i);
                low[u] = min(low[u], low[i]);
                if (low[i] > dfn[u] && edge[id] == 1) {
                    ans.emplace(id);
                }
            } else if (i != fa[u]) {
                low[u] = min(low[u], dfn[i]);
            }
        }

    }


};

void init() {
}


void solve() {
    int n, m, f, t;
    cin >> n >> m >> f >> t;
    vector<array<int, 3>> edge(m + 1);
    Graph g(n), rg(n);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.add_edge(u, v, w);
        rg.add_edge(v, u, w);
        edge[i] = {u, v, w};
    }
    vector<int> disf = g.dij(f, n), dist = rg.dij(t, n);
    TGraph tg(n);
    for (int i = 1; i <= m; i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        int w = edge[i][2];
        if (disf[u] + dist[v] + w == disf[t]) {
            tg.add_edge(u, v,i);
        }
    }
    tg.dfs(f);
    set<int> ans = tg.ans;
    debug(ans);
    for (int i = 1; i <= m; i++) {
        auto [u, v, w] = edge[i];
        if (disf[u] + dist[v] + w == disf[t] && ans.count(i)) {
            cout << "YES" << endl;
            continue;
        }
        int y = disf[t] - (disf[u] + dist[v]) - 1;
//        debug(w, y);
        if (y <= 0) {
            cout << "NO" << endl;
        } else {
            cout << "CAN " << w - y << endl;
        }
    }
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
