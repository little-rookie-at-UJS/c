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

//vector<pair<int, int>> edge;
vector<int> st;
vector<int> instack;
vector<int> vis;

bool dfs(int u, int v, int f, vector<vector<int>> &adj) {
    if (v == f)return true;
    st.emplace_back(v);
    instack[v] = 1;
    for (auto i: adj[v]) {
        if (i == f)continue;
//        st.emplace_back(i);
        if (dfs(v, i, f, adj)) {
            return true;
        }
    }
    instack[v] = 0;
    st.pop_back();
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    instack.resize(n + 1);

    vector<int> du(n + 1);

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        du[u]++;
        du[v]++;
    }
    for (int i = 1; i <= n; i++) {
        if (du[i] >= 4) {
            for (auto j: adj[i]) {
                ranges::fill(instack, 0);
                st.resize(0);
                st.emplace_back(i);
                if (dfs(i, j, i, adj)) {
                    debug(st);
                    int cnt = 0;
                    vector<int> ans;
                    for (auto k: adj[i]) {
//                        cnt++;
                        ans.emplace_back(k);
                        for (auto l: adj[k]) {
                            if (instack[l]) {
                                cnt--;
                                ans.pop_back();
                                break;
                            }
                        }
                        if (ans.size() >= 2) {
                            break;
                        }
                    }

                    if (ans.size() >= 2) {
                        cout << "Yes" << endl;
                        cout << st.size() - 1 + 2 << endl;
                        for (int k = 1; k < st.size(); k++) {
                            cout << st[k - 1] << " " << st[k] << endl;
                        }
                        cout << i << " " << ans[0] << "\n" << i << " " << ans[1] << endl;
                    }
                }
            }

        }
    }
}

signed main() {
    IOS;
    init();
    // debug(1);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
