#include "bits/stdc++.h"

using namespace std;

#ifndef ONLINE_JUDGE
#include "test.h"
// #include "dbg.h"
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> patten(n), pre(n, -1), ys(n + 1), match(m);
    vector bi(m + 1, vector<int>(30, -1));
    for (int i = 0; i < n; i++) {
        cin >> patten[i];
        ys[patten[i]] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> match[i];
        match[i] = ys[match[i]];
    }
    for (int i = m - 1; i >= 0; i--) {
        bi[i][0] = pre[(match[i] + 1) % n];
        pre[match[i]] = i;
    }
    for (int i = 0; (1 << i) <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (bi[j][i] != -1)
                bi[j][i + 1] = bi[bi[j][i]][i];
        }
    }
    vector<pair<int,int>> ans;
    for (int i = 0; i < m; i++) {
        ans.emplace_back(i, i);
    }
    int k = n - 1;
    int now = 25;
    while (k) {
        if (k & (1 << now)) {
            vector<pair<int,int>> mi;
            for (auto [f,t]: ans) {
                if (bi[t][now] != -1) {
                    mi.emplace_back(f, bi[t][now]);
                }
            }
            k ^= (1 << now);
            ans = mi;
        }
        now--;
    }
    vector<int> _sg(8 * m);
    vector arr(m + 1, inf);
    for (auto [i,j]: ans) {
        i++;
        j++;
        arr[i] = j;
    }
    auto pushup = [&](int q) {
        _sg[q] = min(_sg[q << 1], _sg[q << 1 | 1]);
    };
    function<void(int,int,int)> build = [&](int q,int l,int r) {
        if (l == r) {
            _sg[q] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(q << 1, l, mid);
        build(q << 1 | 1, mid + 1, r);
        pushup(q);
    };
    build(1, 1, m);
    function<int(int,int,int,int,int)> query = [&](int q,int l, int r,int L, int R) {
        if (L <= l && r <= R) {
            return _sg[q];
        }
        if (r < L || l > R)
            return inf;
        int mid = (l + r) / 2;
        int anss = inf;
        if (L <= mid) {
            anss = min(anss, query(q << 1, l, mid, L, R));
        }
        if (mid < R) {
            anss = min(anss, query(q << 1 | 1, mid + 1, r, L, R));
        }
        return anss;
    };

    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        int anss = query(1, 1, m, l, r);
        if (anss <= r)cout << 1;
        else cout << 0;
    }
}

signed main() {
    IOS;
    init();
    int t = 1;
    while (t--) {
        solve();
    }
}

// 3 6 3
// 2 1 3
// 1 2 3 1 2 3
// 1 5
// 2 6
// 3 5
