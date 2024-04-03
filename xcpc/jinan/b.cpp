//2
//2 1 1 2
//5
//1 3 1
//0
//2 1 1 2 1
//2 3 2 2 1
//3 1 5 2 3 3 4
//1 2 5
//3 2 1 1 1 3 4
//1 1 3
//0
//1 3 2
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


void solve() {
    int g;
    cin >> g;
    map<int, int> ans;
    stack<pair<int, int>> st;
    stack<int> complate;
    for (int i = 1; i <= g; i++) {
        int u, v;
        cin >> u >> v;
        st.emplace(u, v);
    }
    int n;
    cin >> n;
    map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>> mp;
    vector<vector<pair<int, int>>> valus(n + 1);

    vector<int> du(n + 1);
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        du[i] = m;
        for (int j = 1; j <= m; j++) {
            int u, v;
            cin >> u >> v;
            mp[u].emplace(v, i);
        }
        if (du[i] == 0) complate.emplace(i);
        cin >> m;
        for (int j = 1; j <= m; j++) {
            int u, v;
            cin >> u >> v;
            valus[i].emplace_back(u, v);
        }

    }
    int cnt = 0;
    while (!st.empty() || !complate.empty()) {
        while (!complate.empty()) {
            cnt++;
            auto id = complate.top();
            complate.pop();
            for (auto [i, j]: valus[id]) {
                st.emplace(i, j);
            }
        }
        while (!st.empty()) {
            auto [i, j] = st.top();
            st.pop();
            ans[i] += j;
//            debug(ans[i]);
            while (!mp[i].empty()) {
                auto [va, vb] = mp[i].top();
                if (va <= ans[i]) {
//                    debug(vb);
                    mp[i].pop();
                    du[vb]--;
                    if (du[vb] == 0) {

                        complate.emplace(vb);
                    }
                } else break;
            }
            debug(du);
        }
    }
    cout << cnt << endl;

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
