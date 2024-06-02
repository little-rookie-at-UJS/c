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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1);
    int xorr = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        xorr ^= arr[i];
    }

    VII mp(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);

    }
    if (xorr == 0) {
        cout << "YES" << endl;
        return;
    }
    vector<int> ans(n + 1);
    debug(xorr);
    function<bool(int, int)> dfs = [&](int f, int now) {
        for (auto &i: mp[now]) {
            if (i == f)continue;
            if (dfs(now, i))return true;
            arr[now] ^= arr[i];
            ans[now] += ans[i] != 0;
        }
        debug(now, arr[now], ans[now]);
        if (arr[now] == 0 && ans[now] >= 1)return true;
        if (ans[now] >= 2)return true;
        if (arr[now] == xorr && ans[now] == 0)ans[now]++;
        return false;
    };

    if (k > 2 && dfs(0, 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
