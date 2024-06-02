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

//3 3
//1 2 B
//3 1 R
//3 2 B


//

void init() {
}


struct Graph {
    int n;
    vector<vector<int>> adj, chose;
    vector<int> dfn, low, in, arr;
    stack<int> stk;
    int ans, index, scc;

    Graph(int n) : n(n), adj(2 * n + 1),
                   chose(2 * n + 1), dfn(2 * n + 1), low(2 * n + 1),
                   in(2 * n + 1), ans(0), index(0), scc(1) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u) {
        index++;
        dfn[u] = low[u] = index;
        in[u] = -1;
        stk.push(u);
        for (auto i: adj[u]) {
            if (!dfn[i]) {
                dfs(i);
                low[u] = min(low[u], low[i]);
            }
            if (in[i] == -1) low[u] = min(low[u], dfn[i]);
        }
        if (dfn[u] == low[u]) {
            int v;
            do {
                v = stk.top();
                stk.pop();
                in[v] = scc;
                //小于等于n的点代表要选的点
                if (v <= n) {
                    chose[scc].push_back(v);
                }
            } while (v != u);
            scc++;
        }
    }


    void run() {
        for (int i = 1; i <= n * 2; i++) {
            if (!dfn[i]) {
                dfs(i);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (in[i] == in[i + n]) {
                ans = inf;
                return;
            }
        }
        vector<int> vis(scc + 10);
        for (int i = 1; i <= n; i++) {
//            debug(i, in[i], in[i + n]);
            if (!vis[in[i]]) {
                vis[in[i]] = 1;
                vis[in[i + n]] = 1;
                if (chose[in[i]].size() < chose[in[i + n]].size()) {
                    ans += chose[in[i]].size();
                    arr.insert(arr.end(), chose[in[i]].begin(), chose[in[i]].end());
                } else {
                    ans += chose[in[i + n]].size();
                    arr.insert(arr.end(), chose[in[i + n]].begin(), chose[in[i + n]].end());
                }
            }
        }

    }

};

void solve() {
    int n, m;
    cin >> n >> m;
    Graph g1(n), g2(n);
    for (int i = 1; i <= m; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        // g1 是代表变成蓝色
        if (c == 'R') {
            // u,v选一个 g1
            g1.add_edge(u, v + n);
            g1.add_edge(v, u + n);
//            debug("addg1", u, v + n);
//            debug("addg1", v, u + n);
            // u,v选两个或者都不选 g2
            g2.add_edge(u + n, v + n);
            g2.add_edge(v, u);
//            debug("addg2", u + n, v + n);
//            debug("addg2", v, u);
        } else {
            // u,v选一个 g2
            g2.add_edge(u, v + n);
            g2.add_edge(v, u + n);
//            debug("addg2", u, v + n);
//            debug("addg2", v, u + n);
            // u,v选两个或者都不选 g1
            g1.add_edge(u + n, v + n);
            g1.add_edge(v, u);
//            debug("addg1", u + n, v + n);
//            debug("addg1", v, u);
        }
    }
    g1.run();
    g2.run();
    debug(g1.ans, g1.arr);
    debug(g2.ans, g2.arr);
    if (g1.ans < g2.ans) {
        cout << g1.ans << endl;
        for (auto x: g1.arr) {
            cout << x << " ";
        }
    }else {
        if(g2.ans == inf){
            cout << -1;
            return;
        }else{
            cout << g2.ans << endl;
            for (auto x: g2.arr) {
                cout << x << " ";
            }
        }
    }
}

signed main() {
    IOS;
    init();
    // debug(1);
    int t = 1;
//    cin >> t;/**/
    while (t--) {
        solve();
    }
}
