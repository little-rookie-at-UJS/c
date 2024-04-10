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

// 12 10
// 1 Jessica 5 10
// 1 Sara 4 7
// 1 Peter 7 9
// 2 3 5
// 2 3 7
// 1 Olivia 4 6
// 2 1 3
// 2 8 8
// 2 8 9
// 2 3 11

void solve() {
    int n, q;
    cin >> n >> q;
    vector<priority_queue<int>> _sg(4 * n), lazy(4 * n);

    map<int, string> ans;
    ans[0] = ">_<";
    set<int> s;
    auto addlazy = [&](int q, int x) {
        _sg[q].emplace(x);
        lazy[q].emplace(x);
    };

    auto update = [&](int q) {
        while (!_sg[q].empty() && s.count(_sg[q].top())) {
            _sg[q].pop();
        }
    };
    auto push = [&](int q) {
        update(q);
        while (!lazy[q].empty()) {
            int x = lazy[q].top();
            lazy[q].pop();
            addlazy(q << 1, x);
            addlazy(q << 1 | 1, x);
        }
    };

    function<void(int, int, int, int, int, int)> add = [&](int q, int a, int l, int r, int L, int R) {
        update(q);
        if (L <= l && r <= R) {
            addlazy(q, a);
            return;
        }
        if (l > R || r < L) return;
        push(q);
        _sg[q].emplace(a);
        int mid = (l + r) / 2;
        if (mid >= L) {
            add(q << 1, a, l, mid, L, R);
        }
        if (mid < R) {
            add(q << 1 | 1, a, mid + 1, r, L, R);
        }
    };
    function<int(int, int, int, int, int)> query = [&](int q, int l, int r, int L, int R) {
        update(q);
        if (L <= l && r <= R) {
            if (!_sg[q].empty()) {
                return _sg[q].top();
            }
            return 0ll;
        }
        if (l > R || r < L) return 0ll;
        push(q);
        int mid = (l + r) / 2;
        int ans = 0;
        if (mid >= L) {
            ans = max(query(q << 1, l, mid, L, R), ans);
        }
        if (mid < R) {
            ans = max(query(q << 1 | 1, mid + 1, r, L, R), ans);
        }
        return ans;
    };

    for (int i = 1; i <= q; i++) {
//        debug(i);
        int x;
        cin >> x;
        if (x == 1) {
            string st;
            int l, r;
            cin >> st >> l >> r;
            ans[i] = st;
//            debug("add", i, l, r);
            add(1, i, 1, n, l, r);
        } else {
            int l, r;
            cin >> l >> r;
            int mins = query(1, 1, n, l, r);
            debug(mins);
            cout << ans[mins] << endl;
            s.insert(mins);
        }
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
