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
    int n;
    vector<vector<int>> mp(1e6);
    vector<int> cnt(1e6), vis(1e6, 1);

    cin >> n;
    int maxs = -1;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mp[x].push_back(i);
        maxs = max(maxs, x);
    }
    vis[0] = vis[n + 1] = 0;
    for (int i = 1; i <= maxs; i++) {
        cnt[i] = cnt[i - 1];
        for (auto x: mp[i]) {
//            debug(i, x, vis[x - 1], vis[x + 1] ,vis[x - 1] & vis[x + 1]  ,!(vis[x - 1] | vis[x + 1]));
            cnt[i] += (vis[x - 1] & vis[x + 1]) - (!(vis[x - 1] | vis[x + 1]));
            vis[x] = 0;
        }
//        debug(i, cnt[i]);
    }
    for(int i = 0; i <= maxs; i++){
        debug(i, cnt[i]);
    }
    for (int i = 1; i <= maxs; i++) {
        int ans = 0;
        for (int now = 0; now < maxs; now += i) {
            ans += cnt[now] + 1;
        }
        cout << ans << " ";
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
