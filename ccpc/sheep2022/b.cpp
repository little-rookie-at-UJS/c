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
    struct Peo {
        int l, r, k;
    };
    vector<Peo> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r >> a[i].k;
    }
    vector<vector<int>> _stg(4 << __lg(n));
    int block = sqrt(n);
    function<void(int, int, int, int, int, int)> insert = [&](int q, int id, int l, int r, int L, int R) {
        if (l <= L && R <= r) {
            _stg[q].push_back(id);
            return;
        }
        if (l > R || r < L) return;
        int M = (L + R) / 2;
        if (l <= M) insert(q << 1, id, l, r, L, M);
        if (r > M) insert(q << 1 | 1, id, l, r, M + 1, R);
    };
    queue<int> qu;
    auto delNode = [&](int x) {
        vector<int> q;
        for (auto i: _stg[x]) {
            a[i].k--;
            if (a[i].k > 0) {
                q.push_back(i);
            } else if (a[i].k == 0) {
                qu.push(i);
            }
        }
        _stg[x] = q;
    };
    function<void(int, int, int, int)> del = [&](int q, int x, int l, int r) {
        delNode(q);
        if (l == r) return;
        int M = (l + r) / 2;
        if (x <= M) del(q << 1, x, l, M);
        else del(q << 1 | 1, x, M + 1, r);
    };

    vector<int> s(n + 1), vis(n + 1), eras(n + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i].k == 0) {
            qu.push(i);
            eras[i] = 1;
        }
    }
    int now = 0;


    while (!qu.empty()) {
        auto x = qu.front();
        qu.pop();
        if (now % block == 0) {
            for (int i = 1; i <= n; i++) {
                s[i] = s[i - 1] + vis[i];
            }
            for (int i = 1; i <= n; i++) {
                if (!eras[i] && s[a[i].r] - s[a[i].l - 1] + block >= a[i].k) {
                    a[i].k -= s[a[i].r] - s[a[i].l - 1];
                    insert(1, i, a[i].l, a[i].r, 1, n);
                    eras[i] = 1;
                }
            }
        }
        now++;
        del(1, x, 1, n);
        vis[x] = 1;
    }
    cout << now << endl;

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





