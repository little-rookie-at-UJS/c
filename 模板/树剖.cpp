#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ull = unsigned long long;

#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define int ll

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> mp(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        mp[x].emplace_back(y, z);
        mp[y].emplace_back(x, z);
    }
    vector<pair<int, int>> fa(n + 1, {0, 0}), top(n + 1, {0, 0});
    vector<int> son(n + 1, 0), siz(n + 1, 1), dep(n + 1, 0);
    siz[0] = 0;
    function<void(int, int)> dfs1 = [&](int f, int now) {
        for (auto [i, w]: mp[now]) {
            if (i == f)continue;
            dep[i] = dep[now] + 1;
            fa[i] = {now, w};
            dfs1(now, i);
            siz[now] += siz[i];
            if (siz[son[now]] < siz[i])son[now] = i;
        }
    };
    function<void(int, int)> dfs2 = [&](int f, int now) {
        if (son[fa[now].first] == now) {
            top[now] = top[fa[now].first];
            top[now].second += fa[now].second;
        } else {
            top[now] = {now, 0};
        }
        for (auto [i, w]: mp[now]) {
            if (i == f)continue;
            dfs2(now, i);
        }
    };
    function<int(int, int)> lca = [&](int x, int y) {
        int ans = 0;
        while (top[x].first != top[y].first) {
            if (dep[top[x].first] < dep[top[y].first])
                swap(x, y);
            ans += top[x].second + fa[top[x].first].second;
            x = fa[top[x].first].first;
        }
        if (dep[x] < dep[y])swap(x, y);
        ans += top[x].second - top[y].second;
        return ans;
    };
    dfs1(0, 1);
    dfs2(0, 1);

    vector<int> v(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> v[i];
    }
    int sums = 0;
    for (int i = 1; i < m; i++) sums += lca(v[i], v[i + 1]);
    for (int i = 1; i <= m; i++) {
        if (i == 1) {
            cout << sums - lca(v[i], v[i + 1]) << ' ';
        } else if (i == m) {
            cout << sums - lca(v[i - 1], v[i]) << ' ';
        } else {
            cout << sums - lca(v[i - 1], v[i]) - lca(v[i], v[i + 1]) + lca(v[i - 1], v[i + 1]) << ' ';
        }
    }

}


signed main() {
    IOS
    int t = 1;
//    cin >> t;
    while (t--)solve();
}