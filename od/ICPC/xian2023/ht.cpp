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
#define int ll

using VI = vector<int>;
using VII = vector<VI>;
using PII = pair<int, int>;
const int inf = 1e18;
const int mod = 1e9 + 7;

void init() {
}

const int n = 10;

void solve() {
    // int n;
    // cin >> n;
    array<int, 10> a;
    ranges::fill(a, 0);

    set<array<int, 10>> s;
    queue<pair<array<int, 10>,int>> q;
    s.emplace(a);
    q.emplace(a, 0);
    while (!q.empty()) {
        auto f = q.front();
        q.pop();
        for (auto i: f.first) cout << i << " ";
        cout << endl;
        for (int i = 0; i < n; i++) {
            array<int, 10> vv{};
            ranges::fill(vv, 0);
            for (int j = 0; j < n; j++) {
                vv[j] = (f.first[j] + i + j) % n;
            }
            if (!s.contains(vv)) {
                q.emplace(vv, f.second + 1);
                s.emplace(vv);
            }
        }
    }
    cout << s.size();
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
