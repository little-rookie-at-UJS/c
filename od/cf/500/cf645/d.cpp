#include "bits/stdc++.h"

using namespace std;

#ifndef ONLINE_JUDGE

#include "test.h"

#else
#define debug(...) 42
#define debug_assert(...) 42
#endif


#define IOS ios::sync_with_stdio(0),cin.tie(0)


namespace test {
    using ll = long long;
    using ull = unsigned long long;

#define endl '\n'
#define int ll
    const int inf = 1e18;
    const int mod = 1e9 + 7;
    template<typename T, typename Compare =less<>>
    using pqinit = priority_queue<T, vector<T>, Compare>;

    // 全局变量

    void init() {

    }
//    4 5
//2 1
//1 3
//2 3
//4 2
//4 3

    class solution {
    private:
        vector<pair<int, int>> edge;
        int n, m;

        bool check(int x) {
            vector<vector<int>> adj(n + 1);
            vector<int> du(n + 1);
            vector<int> dep(n + 1);
            vector<int> dep1(n + 1);
            vector<int> vis(n + 1);
            for (int i = 0; i < x; i++) {
                auto [xx, yy] = edge[i];
                adj[xx].emplace_back(yy);
                du[yy]++;
            }
            stack<int> s;
            for (int i = 1; i <= n; i++) {
                if (!du[i]) {
                    s.emplace(i);
                }
            }
            while (!s.empty()) {
                auto xxx = s.top();
                s.pop();
//                if(vis[xxx])continue;
                dep1[dep[xxx]]++;
                debug(xxx);
                if (dep1[dep[xxx]] > 1)return false;
                for (auto i: adj[xxx]) {
                    du[i]--;
                    dep[i] = max(dep[xxx] + 1, dep[i]);
                    if (du[i] == 0) {
                        debug("emplace", i);
                        s.emplace(i);
                    }
                }
            }
            return true;
        }

    public:
        void run() {
            cin >> n >> m;
            for (int i = 1; i <= m; i++) {
                int x, y;
                cin >> x >> y;
                edge.emplace_back(x, y);
            }
            if (!check(m)) {
                cout << -1 << endl;
                return;
            }
            if (n == 1) {
                cout << 0 << endl;
                return;
            } else {
                int l = 1, r = m;
                while (l < r) {
                    int mid = (l + r) / 2;
                    debug(mid);
                    if (check(mid)) {
                        r = mid;
                    } else {
                        l = mid + 1;
                    }
                }
                cout << r << endl;
            }

        }
    };

#undef int
#undef endl
};// namespace test


signed main() {
    IOS;
    test::init();
    // debug(1);
    int t = 1;
//    cin >> t;
    while (t--) {
        test::solution s;
        s.run();
    }
}
