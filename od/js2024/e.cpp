#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;

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
//#define int ll

using VI = vector<int>;
using VII = vector<VI>;
using PII = pair<int, int>;
//const int inf = 1e18;
const int mod = 1e9 + 7;

void init() {
}


int maxn = 1e6 + 10 + 7e5;

struct node {
    node *l, *r;
    int val;

    node() {
        l = nullptr;
        r = nullptr;
        val = 0;
    }
};

void pushup(node *p) {
    p->val = (p->l ? p->l->val : 0) + (p->r ? p->r->val : 0);
}

node *add(node *p, int l, int r, int k) {
    node *pp = new node();
    if (p != nullptr) {
        *pp = *p;
    }
    if (l == r) {
//        debug("add", l);
        pp->val++;
        return pp;
    }
    int mid = (l + r) / 2;
    if (mid >= k) {
        pp->l = add(pp->l, l, mid, k);
    } else {
        pp->r = add(pp->r, mid + 1, r, k);
    }
    pushup(pp);

    return pp;
}

node *add(node *p, int k) {
    return add(p, 1, maxn, k);
}


int query(node *p, node *pp, int l, int r, int k) {
    if (l == r) {
        return l;
    }
    int mid = (l + r) / 2;
    if (p->l) {
        int size = p->l->val - (pp && pp->l ? pp->l->val : 0);

        if (size >= k) {
            return query(p->l, (pp ? pp->l : nullptr), l, mid, k);
        }
        k -= size;
    }
    return query(p->r, (pp ? pp->r : nullptr), mid + 1, r, k);

}

int query(node *p, node *pp, int k) {
    int sums = p->val - pp->val;
    if (sums < k) return 0;
    return query(p, pp, 1, maxn, k);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> time(maxn);
    vector<node *> tree(n + 1);
    vector<vector<int>> op(n + 1);
    priority_queue<pair<int, int>> arr;
    tree[0] = new node();
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x)
            arr.emplace(x, i);
    }
    int k = 1;
    while (!arr.empty()) {
        auto [x, len] = arr.top();
        arr.pop();
        time[k] = {x, len};
        op[len].emplace_back(k);
        x /= 2;
        k++;
        if (x) {
            arr.emplace(x, len);
        }
    }
    for (int i = 1; i <= n; i++) {

        tree[i] = tree[i - 1];

        for (auto t: op[i]) {
            tree[i] = add(tree[i], t);
        }
    }
//    cin >> q;
    while (q--) {
        int l, r, kk;
        cin >> l >> r >> kk;
//        debug(l, r, kk);
        int tt = query(tree[r], tree[l - 1], kk + 1);
//        debug(tt);
        auto [ans, len] = time[tt];
        cout << ans << endl;
    }


}

signed main() {
    IOS;
    int xx = 2e6;
    int x = 24 * 2e6 * __lg(xx) / 1024 / 1024;
    debug(x);
    init();
    int siz = sizeof node();
    debug(siz);
    // debug(1);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }

}
