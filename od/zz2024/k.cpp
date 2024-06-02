#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

const i64 mod = 998244353;

const i64 maxn = 1e6 + 10;

vector<i64> fact(maxn, 1);
vector<i64> infact(maxn, 1);

i64 comb(int x, int y) {
    if (x == 0 || x - y < 0) return 0;
    return (infact[x] * fact[y]) % mod * fact[x - y] % mod;
}

i64 qpow(i64 x, i64 y) {
    i64 ans = 1;
    while (y) {
        if (y & 1) {
            ans *= x;
            ans %= mod;
        }
        y /= 2;
        x *= x;
        x %= mod;
    }
    return ans;
}

i64 inv(i64 x) {
    return qpow(x, mod - 2);
}

void solve() {
//3
//1 2 3
//1 2
//2 3
    int n;
    cin >> n;
    int k = 0;
    vector<int> value(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int cnt = 0;
    vector<int> go(n + 1);
//认为一个节点是美丽节点，当且仅当该节点作为根时，对于除根节点以外的所有节点，其
//点权都不. 小. 于. 其父亲节点的点权的 1/2
    function<void(int, int)> dfs1 = [&](int u, int v) {
        if (u == 0) {
            go[v] = 1;
            cnt++;
        }
        for (auto i: adj[v]) {
            if (i == u) continue;
            if ((value[v] + 1) / 2 <= value[i]) {
                go[i] = 1;
                cnt++;
            }
            dfs1(v, i);
        }
    };
    dfs1(0, 1);

    int no = 0;
//    if (cnt == n) no++;
    function<void(int, int, int)> dfs2 = [&](int u, int v, int k) {
        if (k == n) no++;
//        cerr << v << endl;
//        for (int i = 1; i <= n; i++) {
//            cerr << go[i] << " ";
//        }
//        cerr << k << endl;
        for (auto i: adj[v]) {
            if (i == u) continue;

            int g1 = go[i];
            int g2 = go[v];
            go[i] = 0;
            go[v] = 0;
            k -= g1 + g2;
            go[i] = 1;

            if ((value[i] + 1) / 2 <= value[v]) {
                go[v] = 1;
            }
            int g3 = go[i];
            int g4 = go[v];
            k += g3 + g4;
            dfs2(v, i, k);
            k -= g3 + g4;
            go[i] = g1;
            go[v] = g2;
            k += g1 + g2;
        }
    };
    dfs2(0, 1, cnt);
    cout << no << endl;
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0);


    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

}
//2
//4
//8 3 3 5
//1 2 3 2
//5
//4 3 4 5 6
//3 1 3 1 1