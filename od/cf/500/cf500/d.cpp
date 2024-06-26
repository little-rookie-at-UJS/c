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
    vector<vector<pair<int, int>>> adj;
//    map<pair<int, int>, int> mp;
    vector<array<int, 3>> mp;
    vector<int> size;
    double ans;
    double temp;
    int n;

    void add_edge(int u, int v, int w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    void dfs(int u, int v) {
        for (auto [i, w]: adj[u]) {
            if (i == v)continue;
            dfs(i, u);
//            size[v] += size[i];
            size[u] += size[i];
        }
    }

    long double work(int u, int v, int w) {
//        debug("work", u, v, w);
        int sz = min(size[u], size[v]);
        int other = n - sz;
        debug(sz);
        debug((sz * (sz - 1) / 2 * other) +
              (sz * other * (other - 1) / 2));
        long double anss = w * ((sz * (sz - 1) / 2 * other) +
                                (sz * other * (other - 1) / 2));
        return anss * 2.0;
    }

public:
    Graph(int n) : adj(n + 1), size(n + 1, 1),
                   ans(0), n(n), temp(0), mp(n + 1) {
        for (int i = 1; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            add_edge(u, v, w);
            mp[i][0] = u;
            mp[i][1] = v;
            mp[i][2] = w;
        }
        temp = 1.0 * (n) * (n - 1) * (n - 2) / 6.0;
        dfs(1, 0);
        debug(size);
        for (auto [u, v, w]: mp) {
            ans += work(u, v, w);
            debug(u, v, w, ans);

        }
        debug(ans);
    }

    void change(int u, int w) {
        ans -= work(mp[u][0], mp[u][1], mp[u][2]);
        mp[u][2] = w;
        ans += work(mp[u][0], mp[u][1], mp[u][2]);
        debug(ans);
        long double ansss = ans / temp;
        cout << fixed << setprecision(8) << ansss << endl;
    }
};

void solve() {
    int n;
    cin >> n;
    Graph g(n);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int u, v;
        cin >> u >> v;
        g.change(u, v);
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
