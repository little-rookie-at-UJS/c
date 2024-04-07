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
    int mins = inf;
    pqinit<tuple<int, int, int>, greater<>> pq1, pq2;
    map<int, int> ans;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pq1.emplace(a, b, c);
    }
    while (!pq1.empty()) {
        auto [a, b, c] = pq1.top();

        pq1.pop();
        while (!pq2.empty() && get<0>(pq2.top()) < a) {
            auto [a1, b1, c1] = pq2.top();
            pq2.pop();
            debug("insert", a1, b1, c1);
            int kk = a1 - b1 + 1;
            if (!ans.count(kk))
                ans[kk] = c1;
            else
                ans[kk] = min(ans[kk], c1);
            debug("ans", kk, ans[kk]);
        }
        debug("check", a, b, c);
        int kk = k - (b - a + 1);
        if (ans.count(kk))
            mins = min(mins, ans[kk] + c);
        pq2.emplace(b, a, c);
    }
    if (mins == inf)
        cout << -1 << endl;
    else
        cout << mins << endl;


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
