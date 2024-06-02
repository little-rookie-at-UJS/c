//
// Created by DELLPC on 24-5-19.
//
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;

#define  endl '\n'
const i64 mod = 1e9 + 7;



class Graph {
private:
    vector<int> dfn, dep, fa, son, siz, top, mir;
    vector<vector<int>> adj;
    int tot = 0;

    void dfs1(int u, int f) {
        dep[u] = dep[f] + 1;
        fa[u] = f;
        for (auto v: adj[u]) {
            if (v == f) continue;
            dfs1(v, u);
            siz[u] += siz[v];
            if (siz[v] > siz[son[u]]) {
                son[u] = v;
            }
        }
    }

    void dfs2(int u, int topf) {
        dfn[u] = ++tot;
        mir[tot] = u;
        top[u] = topf;
        if (!son[u]) return;
        dfs2(son[u], topf);
        for (auto v: adj[u]) {
            if (v == fa[u] || v == son[u]) continue;
            dfs2(v, v);
        }
    }

public:
    Graph(int n) : dfn(n + 1), dep(n + 1), fa(n + 1), son(n + 1), siz(n + 1, 1), top(n + 1), mir(n + 1), adj(n + 1) {
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        siz[0] = 0;
        dfs1(1, 0);
        dfs2(1, 1);

    }

    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            u = fa[top[u]];
//            assert(u);
        }
        return dep[u] < dep[v] ? u : v;
    }

    int dis(int u, int v) {

        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

    bool test(int a, int b, int c) {

        return dis(a, c) == dis(b, c) + dis(a, b);
    }
};


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    Graph g(n);

    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    int ans = m;
    auto test = [&](int i) {
        if (i <= 0) return false;
        if (i + 2 > m) return false;
//        cerr << i << " " << i + 1 << " " << i + 2 << endl;
//        cerr << a[i] << " " << a[i + 1] << " " << a[i + 2] << endl;
        return g.test(a[i], a[i + 1], a[i + 2]);
    };
    for (int i = 0; i <= m; i++) {
        if (test(i)) ans--;
//        cerr << test(i) << endl;
    }


    while (q--) {
        int x;
        cin >> x;
        ans += test(x - 2);

        ans += test(x - 1);
        ans += test(x);


        cin >> a[x];

        ans -= test(x - 2);

        ans -= test(x - 1);
        ans -= test(x);

        cout << ans << endl;

    }

}

