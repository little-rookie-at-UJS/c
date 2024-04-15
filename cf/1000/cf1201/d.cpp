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

//3 3 3 2
//1 1
//2 1
//3 1
//2 3
void solve() {
    int n, m, c1, c2;
    cin >> n >> m >> c1 >> c2;
    vector<int> fix(m + 1, 0), pre(m + 2, 0), nex(m + 2, 0);
    vector<int> l(n + 1, 0), r(n + 1, 0);
    n = 0, m = 0;
    for (int i = 1; i <= c1; i++) {
        int x, y;
        cin >> x >> y;
        n = max(n, x);
        m = max(m, y);
        l[x] = l[x] ? min(l[x], y) : y;
        r[x] = max(r[x], y);
    }
    if (!l[1]) l[1] = r[1] = 1;
    for (int i = 1; i <= c2; i++) {
        int x;
        cin >> x;
        fix[x] = 1;
        m = max(m, x);
    }
    for (int i = 1; i <= m; i++) {
        pre[i] = fix[i] ? i : pre[i - 1];
    }
    for (int i = m; i >= 1; i--) {
        nex[i] = fix[i] ? i : nex[i + 1];
    }
    auto cal = [&](int x, int y) {
        if (x > y) swap(x, y);
        debug(x, y, nex[x], pre[y]);
        if ( pre[y] >= x) return y - x;
        int res = inf;
        if (pre[x]) {
            res = min(res, x + y - (pre[x] * 2));
            debug(res, x, y, pre[x] );

        }

        if (nex[y]) {
            res = min(res, (nex[y] * 2) - x - y);
            debug(res, x, y, nex[y]);
        }
        return res;
    };
    vector<vector<int>> f(n + 1, vector<int>(2));
    f[1][0] = r[1] - l[1] + r[1] - 1;
    f[1][1] = r[1] - 1;
    for (int i = 2; i <= n; i++) {
        if (!l[i]) {
            l[i] = l[i - 1];
            r[i] = r[i - 1];
            f[i][0] = f[i - 1][0];
            f[i][1] = f[i - 1][1];
        } else {
            //  走到最左边
            f[i][0] = min(f[i - 1][0] + cal(l[i], l[i - 1]), f[i - 1][1] + cal(r[i - 1], l[i]));
//            debug(f[i - 1][0] + cal(l[i], l[i - 1]),
//                  f[i - 1][1] + cal(r[i - 1], l[i]), l[i], l[i - 1], r[i - 1], l[i]);
            //  走到最右边
            f[i][1] = min(f[i - 1][0] + cal(r[i], l[i - 1]), f[i - 1][1] + cal(r[i - 1], r[i]));
//            cout << f[i - 1][0] + cal(r[i], l[i - 1]) << " " << f[i - 1][1] + cal(r[i - 1], r[i]) << endl;
//            debug(f[i - 1][0] + cal(r[i], l[i - 1]),
//                  f[i - 1][1] + cal(r[i - 1], r[i]), r[i], l[i - 1], r[i - 1], r[i]);
            f[i][0] += r[i] - l[i];
            f[i][1] += r[i] - l[i];
            swap(f[i][0], f[i][1]);
        }
    }
    cout << min(f[n][0], f[n][1]) + n - 1 << endl;

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
