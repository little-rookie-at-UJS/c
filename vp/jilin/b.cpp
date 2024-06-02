//
// Created by DELLPC on 24-5-19.
//
//3
//2
//1 2
//1 2
//4
//1 1 222 222
//1 2
//1 3
//2 4
//6
//1 5 4 6 1 1
//6 1
//4 5
//4 2
//1 4
//1 3
//
// Created by DELLPC on 24-5-19.
//
//
// Created by DELLPC on 24-5-19.
//
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;

#define  endl '\n'


void solve() {
    struct node {
        i64 j, o, siz;
    };
    int n;
    cin >> n;
    vector<int> va(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> va[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    function<node(int, int)> dfs = [&](int u, int v) -> node {
        node ans = {va[v], 0, 1};
        vector<node> ji, ou;

        for (auto i: adj[v]) {
            if (i == u)continue;
            auto ans1 = dfs(v, i);
//            cerr << i << " " << ans1.siz << " " << ans1.j << " " << ans1.o << endl;
            if (ans1.siz & 1)ji.emplace_back(ans1);
            else ou.emplace_back(ans1);
            ans.siz += ans1.siz;
        }
        if (!ji.empty()) {
            for (auto i: ou) {
                ans.j += max(i.j, i.o);
                ans.o += max(i.j, i.o);
            }
            sort(ji.begin(), ji.end(), [](node a, node b) {
                return a.j - a.o > b.j - b.o;
            });
            for (int i = 0; i < (ji.size()) / 2; i++) {
                ans.j += ji[i].j;
            }
            for (int i = (ji.size()) / 2; i < ji.size(); i++) {
                ans.j += ji[i].o;
            }
            sort(ji.begin(), ji.end(), [](node a, node b) {
                return a.j - a.o > b.j - b.o;
            });
            for (int i = 0; i < (ji.size() + 1) / 2; i++) {
                ans.o += ji[i].j;

            }

            for (int i = (ji.size() + 1) / 2; i < ji.size(); i++) {
                ans.o += ji[i].o;
            }
        } else {
            for (auto i: ou) {
                ans.j += i.o;
                ans.o += i.j;
            }
        }

        return ans;
    };
    auto ans = dfs(0, 1);
//    cerr << 1 << " " << ans.siz << " " << ans.j << " " << ans.o << endl;
    cout << ans.o << endl;


};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}



