//
// Created by DELLPC on 24-5-19.
//
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;

#define  endl '\n'


void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<tuple<int, int, int >>> adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, kk, a;
        cin >> u >> v >> kk >> a;
        adj[u].emplace_back(v, kk, a);
    }


    queue<pair<int, int>> q;
    q.emplace(0, 0);
    for (int i = 1; i <= k; i++) {
        int c, l;
        cin >> c >> l;
        q.emplace(c, l);
    }
    priority_queue<tuple<pair<int, int>, int, int, queue<pair<int, int>>>,
            vector<tuple<pair<int, int>, int, int, queue<pair<int, int>>> >, greater<>> pq;
    pq.emplace(make_pair(0, 0), 0, 1, q);

    vector<pair<int, int>> dis(n + 1, {1e9, 1e9});
    vector<int> vis(n + 1);
    dis[0] = {0, 0};
    while (!pq.empty()) {
        auto [pp, left, now, qq] = pq.top();
        auto [siz, cole] = pp;
        pq.pop();
        if (!vis[now]) vis[now] = 1;
        else continue;
        for (auto [t, cc, le]: adj[now]) {
            if (cc == cole && le <= left) {
                pair<int, int> sss = {siz, left - le};
                if (sss < dis[t]) {
                    dis[t] = sss;
                    pq.emplace(make_pair(siz, cole), left - le, t, qq);
                }
            } else {
                auto qqq = qq;
                qqq.pop();
                while (!qqq.empty() && (qqq.front().first != cc || qqq.front().second < le))
                    qqq.pop();
                if (!qqq.empty()) {
                    pair<int, int> sss = {-qqq.size(), qqq.front().second - le};
                    if (sss < dis[t]) {
                        dis[t] = sss;
                        pq.emplace(make_pair(qqq.size(), cc), qqq.front().second - le, t, qqq);
                    }
                }
            }
        }

    }
    for (int i = 1; i <= n; i++) {
        if (vis[i])cout << 1;
        else cout << 0;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}


