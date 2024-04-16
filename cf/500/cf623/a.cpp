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
template<typename T, typename Compare =less<>>
using pqinit = priority_queue<T, vector<T>, Compare>;

void init() {
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        mp[u][v] = 1;
        mp[v][u] = 1;
    }
    vector<char> color(n + 1, '0');
    for (int i = 1; i <= n; i++) {
        mp[i][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int j = 1; j <= n; j++) {
            if (!mp[i][j]) flag = false;
        }
        if (flag) color[i] = 'b';
    }
    auto same = [&](int x, int y) {

    };
    bool flag = true;
    auto dfs = [&](auto self, int x) {
        for (int i = 1; i <= n; i++) {
            if (!mp[x][i]) {
                if (color[x] == color[i]) {
                    flag = false;
                    return;
                }
                if (color[i] == '0') {
                    color[i] = 2 - color[x] + 'a' * 2;

                    self(self, i);
                }
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        if (color[i] == '0') {
            color[i] = 'a';
            dfs(dfs, i);
        }
    }
    debug(color);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (color[i] == color[j] && (!mp[i][j]))flag = false;
            if (color[i] == 'a' && color[j] == 'c' && mp[i][j])flag = false;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
        for (int i = 1; i <= n; i++) {
            cout << color[i];
        }
    } else {
        cout << "No" << endl;
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
