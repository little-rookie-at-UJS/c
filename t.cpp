/*

Author: Haze

2024/4/24

*/

#include <bits/stdc++.h>
//#include "test.h"

#define IOS ios::sync_with_stdio(false), cin.tie(nullptr);
using namespace std;
using ll = long long;
#define int ll

#define debugs(x) cerr<<#x<<" "<<x<<endl;


void solve() {
    int n;
    cin >> n;

    vector<vector<tuple<int, int, int>>> adj(n * 2 + 10);
    vector<set<int>> ans1(n * 2 + 10);
    vector<int> arr1(n * 2 + 10);
    vector<set<int>> ans2(n * 2 + 10);
    vector<int> arr2(n * 2 + 10);
    vector<int> vis(n * 2 + 10);
    vector<int> du(n * 2 + 10);

    for (int i = 1; i <= n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w, i);
        adj[v].emplace_back(u, w, i);
        du[u]++;
        du[v]++;
        if (u > n)return;
        if (v > n)return;
    }
    stack<int> st;
//    debug(du);
    for (int i = 1; i <= n; i++) {
        if (du[i] == 1) {
            st.emplace(i);
        }
    }

    while (!st.empty()) {
        auto t = st.top();
        du[t] = 0;
//        debug(t);
        st.pop();
//        if (i > n)return;
//        if (id > n)return;
        if (t > n)return;
//        vis[t] = 1;
        for (auto [i, w, id]: adj[t]) {
            du[i]--;

            if (du[i]) {
                if (i > n)return;
                if (id > n)return;
                if (t > n)return;
                arr1[id] = t;
                ans1[t].emplace(1);
                ans1[i].emplace(w);

                arr2[id] = t;
                ans2[t].emplace(1);
                ans2[i].emplace(w) ;
                if (du[i] == 1)
                    st.emplace(i);
            }
        }
    }
//    debug(du);
    function<void(int, int, int)> dfs = [&](int pre, int now, int be) {
//        debug(now);
        if (now > n)return;
//        vis[now] = 1;
        for (auto [i, w, id]: adj[now]) {
            if (du[i] == 0 || i == pre) continue;
//            cerr << now << " " << i << " " << w << " " << id << endl;
            if (i > n)return;
            if (id > n)return;
//            debug(now, i, id);
            arr1[id] = now;
            ans1[now].emplace(1);
            ans1[i].emplace(w);

            arr2[id] = i;
            ans2[now].emplace(w);
            ans2[i].emplace(1);
            if (i != be) {
                dfs(now, i, be);
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (du[i] != 0) {
            for (auto [j, w, id]: adj[i]) {
//                debug(i, j);
                if (j > n) return;
                if (id > n) return;
                if (du[j] != 0) {
                    arr1[id] = i;
                    ans1[i].emplace(1);
                    ans1[j].emplace(w);

                    arr2[id] = j;
                    ans2[i].emplace(w);
                    ans2[j].emplace(1);

                    dfs(i, j, i);
//                    debug(i, j);
//                    return;

                    bool flag = true;
                    for (int k = 1; k <= n; k++) {
                        if (ans1[k].size() != adj[k].size()) {
//                            debugs(k);
                            flag = false;
                        }
                    }
                    if (flag) {
                        for (int k = 1; k <= n; k++) {
                            cout << arr1[k] << endl;
                        }
                        return;
                    }


                    flag = true;
                    for (int k = 1; k <= n; k++) {
                        if (ans2[k].size() != adj[k].size()) {
//                            debugs(k);
                            flag = false;
                        }
                    }
                    if (flag) {
                        for (int k = 1; k <= n; k++) {
                            cout << arr2[k] << endl;
                        }
                        return;
                    }

                    cout << "impossible" << endl;
                    return;
                }
            }
            return;
        }
    }


}

signed main() {
//    IOS
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}