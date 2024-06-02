//
// Created by DELLPC on 24-3-31.
//
#include <bits/stdc++.h>

using namespace std;
#define int long  long
//3 2 2
// 1 1 1
// 2 3 10
// 1 2 1
// 3 2
const int mod = 998244353;

signed main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> num(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    vector<priority_queue<tuple<int, int, int, int>,
            vector<tuple<int, int, int, int>>, greater<>>> mp(n + 1);
    vector<int> dis(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        mp[u].emplace(w, 0, w, v);
        mp[v].emplace(w, 0, w, u);
    }
    vector<int> ans(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> ans[i];
    }
    for (int i = k; i; i--) {
        do {
            auto [_, ta, w, v] = mp[ans[i]].top();
            if (ta != dis[v]) {
                mp[ans[i]].pop();
                mp[ans[i]].emplace((dis[v] + w), dis[v], w, v);
            } else break;
        } while (true);

        auto [w, _, __, ___] = mp[ans[i]].top();
        dis[ans[i]] = w;
    }
    int sums = 0;
    for (int i = 1; i <= n; i++) {
        sums += (num[i] * (dis[i] % mod)) % mod;
        sums %= mod;
    }
    cout << sums << endl;
}

