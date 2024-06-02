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
    vector<int> a(6, -1);
    // 0 下 1 前 2 上 3 后 4 左 5 右
    auto down = [&](vector<int> &a) {
        vector<int> b(6);
        b[0] = a[1];
        b[1] = a[2];
        b[2] = a[3];
        b[3] = a[0];
        b[4] = a[4];
        b[5] = a[5];
        return b;
    };
    // 0 下 1 前 2 上 3 后 4 左 5 右
    auto up = [&](vector<int> &a) {
        vector<int> b(6);
        b[0] = a[3];
        b[1] = a[0];
        b[2] = a[1];
        b[3] = a[2];
        b[4] = a[4];
        b[5] = a[5];
        return b;
    };
    // 0 下 1 前 2 上 3 后 4 左 5 右
    auto left = [&](vector<int> &a) {
        vector<int> b(6);
        b[0] = a[4];
        b[5] = a[0];
        b[2] = a[5];
        b[4] = a[2];
        b[1] = a[1];
        b[3] = a[3];
        return b;
    };
    // 0 下 1 前 2 上 3 后 4 左 5 右
    auto right = [&](vector<int> &a) {
        vector<int> b(6);
        b[0] = a[5];
        b[4] = a[0];
        b[2] = a[4];
        b[5] = a[2];
        b[1] = a[1];
        b[3] = a[3];
        return b;
    };

    int n;
    cin >> n;
    vector<vector<int>> mp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mp[i][j];
        }
    }
    a[0] = mp[1][1];
    vector<int> ans;
    auto dfs
            = [&](int x, int y, int gx, int gy, vector<int> arr, auto self) -> pair<bool, vector<int>> {
                if (arr[0] != -1 && arr[0] != mp[x][y]) {
                    return make_pair(false, vector<int>());
                }
                if (arr[0] == -1)
                    arr[0] = mp[x][y];
//                debug(x, y, arr);
                if (x == gx && y == gy) {
                    return make_pair(true, arr);
                }
                if (x < gx) {
                    auto [ok, b] = self(x + 1, y, gx, gy, down(arr), self);
                    if (ok) {
                        return make_pair(true, up(b));
                    }
                }
                if (y < gy) {
                    auto [ok, b] = self(x, y + 1, gx, gy, right(arr), self);
                    if (ok) {
                        return make_pair(true, left(b));
                    }
                }
                return make_pair(false, vector<int>());
            };
    auto [ok, b] = dfs(1, 1, n, n, a, dfs);
    if (ok) {
        cout << "Yes" << endl;
        for (auto &x: b) {
            if (x == -1) {
                x = 1;
            }
        }
        cout << b[0] << " " << b[4] << " " << b[3] << " " << b[1] << " " << b[5] << " " << b[2] << endl;
    } else {
        cout << "No" << endl;
    }
}

signed main() {
//    IOS;
    init();
    // debug(1);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
