#include <ranges>

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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> mp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cin >> mp[i][j];
        }
    }
    vector<vector<int>> ans(n + 3);
    ans[n + 1].emplace_back(0);
    ans[n + 2].emplace_back(0);
    priority_queue<int, vector<int>, greater<>> cho;
    cho.emplace(0);
    // 计算 到第i为止，前k大
    for (int i = n; i; i--) {
        priority_queue<pair<int, int>> q;
        for (int j = i; j <= n; j++) {
            q.emplace(mp[i][j], -j);
        }
        while (!q.empty()) {
            auto [_, j] = q.top();
            q.pop();
            j = -j;
            for (auto l: ans[j + 2]) {
                if (cho.size() < k) {
                    cho.emplace(mp[i][j] + l);
                } else {
                    if (mp[i][j] + l > cho.top()) {
                        cho.pop();
                        cho.emplace(mp[i][j] + l);
//                        cho.emplace(1);
                    } else break;
                }
            }
        }
        while (!cho.empty()) {
            ans[i].emplace_back(cho.top());
            cho.pop();
        }
        ranges::reverse(ans[i]);
        for (auto j: ans[i]) {
            cho.emplace(j);
        }
    }

    for (auto i: ans[1])cout << i << " ";
    cout << endl;

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
