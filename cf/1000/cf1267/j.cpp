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
    int n;
    cin >> n;
    vector<int> mp(n + 1);
//    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<int> v;
    for (auto j: mp) {
        if (j)
            v.emplace_back(j);
    }
    sort(v.begin(), v.end());
    debug(v);
    int maxs = 0;
    auto check = [&](int i, int j) {
        if (j == 1)return true;
        int x = i / (j - 1);
        int z = i % (j - 1);
        if (z > x) {
            return false;
        }
        return true;
    };
    for (int i = 1; i <= v[0] + 1; i++) {
        bool flag = true;
        for (auto j: v) {
            if (!check(j, i)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            maxs = i;
        }
    }
    int ans = 0;
    for (auto j: v) {
        ans += (j + maxs - 1) / (maxs);
    }
    cout << ans << endl;
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
