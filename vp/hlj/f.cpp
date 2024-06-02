//
// Created by DELLPC on 24-5-19.
//
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;

#define  endl '\n'

//4 5
//5 6 3 4
//1 2
//1 3
//2 3
//2 4
//3 4
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;

    int maxn = -1;
    vector<int> val(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++) {
        maxn = max(val[i], maxn);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end(), [&](auto a, auto b) {
            return val[a] > val[b];
        });
    }
    for (int i = 1; i <= n; i++) {
        for (auto j: adj[i]) {
            maxn = max(val[j] + val[i], maxn);
            for (auto k: adj[i]) {
                if (j == k) continue;
                maxn = max(val[j] + val[i] + val[k], maxn);
                vector<int> l, r;
                for (auto ll: adj[k]) {
                    if (ll != i && ll != k && ll != j) {
                        l.emplace_back(ll);
                    }
                    if (l.size() > 4)break;
                }
                for (auto rr: adj[j]) {
                    if (rr != i && rr != k && rr != j) {
                        r.emplace_back(rr);
                    }
                    if (r.size() > 4)break;
                }
                for (auto ll: l) {
                    maxn = max(val[j] + val[i] + val[k] + val[ll], maxn);
                    for (auto rr: r) {
                        if (ll == rr)continue;
                        maxn = max(val[j] + val[i] + val[k] + val[ll] + val[rr], maxn);
                    }
                }
            }
        }
    }
    cout << maxn << endl;

}


