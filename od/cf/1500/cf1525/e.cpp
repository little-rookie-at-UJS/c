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
const int mod = 998244353;

int qpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) {
            ans *= x;
            ans %= mod;
        }
        y /= 2;
        x *= x;
        x %= mod;
    }
    return ans;
}

int inv(int x) {
    return qpow(x, mod - 2);
}

void init() {
}


void solve() {
    int n, m;
    cin >> n >> m;
    int tmp = 1;
    for (int i = 1; i <= n; i++) {
        tmp = (tmp * i) % mod;
    }
    tmp = inv(tmp);
    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
//    vector<vector<int>> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;

    for (int i = 1; i <= m; i++) {
        vector<int> dis;
        dis.emplace_back(1);
        for (int j = 1; j <= n; j++) {
            dis.emplace_back(arr[j][i]);
        }
        sort(dis.begin(), dis.end());
        int le = 1;
        debug(dis);
        for (int j = 1; j <= n; j++) {
            if (dis[j] - j < 0)le = 0;
            else {
                le *= (dis[j] - j);
                le %= mod;
            }
        }
        debug(le, tmp);
        ans = (ans + 1 - (le * tmp) % mod + mod) % mod;
    }
    cout << ans << endl;
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
