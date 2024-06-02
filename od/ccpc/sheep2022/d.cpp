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
    cin >> n;
    vector<pair<double, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin()+1, a.end(), greater<>());

    vector<pair<double, int>> b;
    b.push_back({0, 0});
    for (int i = 1; i <= n; i++) {
        if (i == 0 || a[i].first != a[i - 1].first) {
            b.push_back(a[i]);
        } else {
            b.back().second += a[i].second;
        }
    }
    n = b.size();
    b.push_back({0, 0});
    vector<int> pre(n + 2, 0), suf(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        pre[i ] = pre[i-1] + b[i].second;
    }
    for (int i = n; i > 0; i--) {
        suf[i] = suf[i + 1] + b[i].second;
    }
    debug(b, pre, suf);
    double ans = 0;
    for (int i = 0, p = n - 1; i < n; i++) {
        while (p > i && pre[i] / b[i].first > suf[p] / (1 - b[p].first)) --p;
        ans = max(ans, pre[i] + suf[p + 1] - pre[i] / b[i].first);
        debug(i, p, ans, pre[i], suf[p + 1], pre[i] / b[i].first);
        if (i >= p) break;
        ans = max(ans, pre[i] + suf[p] - suf[p] / (1 - b[p].first));
        debug(i, p, ans, pre[i], suf[p], suf[p] / (1 - b[p].first));
    }
    cout << fixed << setprecision(10) << ans << endl;


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
