#include "bits/stdc++.h"

using namespace std;

#ifndef ONLINE_JUDGE
#include "test.h"
#include "dbg.h"
#else
#define debug(...) 42
#define debug_assert(...) 42
#endif


#define IOS ios::sync_with_stdio(0),cin.tie(0)

using ll = long long;
using ull = unsigned long long;

#define endl '\n'
// #define int ll

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
    vector<int> arr(n);
    vector<vector<int>> pos(10);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        arr[i] = x;
        pos[x].emplace_back(i);
    }

    auto check = [&](int mid) {
        vector<int> nums(10, 0);
        vector<vector<int>> f(n + 1, vector<int>(1 << 8, -1));
        f[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (1 << 8); j++) {
                if (f[i][j] >= 0) {
                    for (int k = 0; k < 8; k++) {
                        if (j & (1 << k))continue;
                        int last = nums[k] + mid - 1;
                        if (last < pos[k].size()) {
                            f[pos[k][last]][j | (1 <<k)] = max(f[pos[k][last]][j | (1 << k)], f[i][j]);
                        }
                        last++;
                        if (last < pos[k].size()) {
                            f[pos[k][last]][j | (1 << k)]
                                    = max(f[pos[k][last]][j | (1 << k)], f[i][j] + 1);
                        }
                    }
                }
            }
            nums[arr[i]]++;
        }

        int ret = -1;
        for (int i = 1; i <= n; i++) {
            ret = max(ret, f[i][(1 << 8) - 1]);
        }
        if (ret < 0)return 0;
        return mid * 8 + ret;
    };

    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    int ans = check(l);
    if (!ans) {
        for (auto i: pos) {
            if (!i.empty())ans++;
        }
    }
    cout << ans << endl;
}

signed main() {
    IOS;
    init();
    // debug(1);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
