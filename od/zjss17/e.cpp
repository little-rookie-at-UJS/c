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

struct node {
    node *l, *r;
    int siz, val;

    node() {
        l = nullptr, r = nullptr;
        siz = 0;
        val = 0;
    }
};

const int siz = 1e5 + 10;
node *t[siz];


void pushup(node *p) {
    p->siz = (p->l == NULL ? 0 : p->l->siz) + (p->r == NULL ? 0 : p->r->siz);
    p->val = (p->l == NULL ? 0 : p->l->val) + (p->r == NULL ? 0 : p->r->val);

}
//
int query(node *pp, node *p, int l, int r, int k) {
    if (l == r) {
        return k * l;
    }
    int mid = (l + r) / 2;
    int rr = (pp->r != NULL ? pp->r->siz : 0);
    int rl = ((p != NULL) && (p->r != NULL) ? p->r->siz : 0);
    int riz = rr - rl;
    if (riz >= k) {
        return query(pp->r, (p != NULL ? p->r : NULL), mid + 1, r, k);
    } else {
        int rsum = (pp->r != NULL ? pp->r->val : 0) - (p != NULL && p->r != NULL ? p->r->val : 0);
        return rsum + query(pp->l, (p != NULL ? p->l : NULL), l, mid, k - riz);

    }
};

//
node *add(node *p, int l, int r, int q) {
    node *pp = new node();
    if (p != nullptr)
        *pp = *p;
    if (l == r) {

        pp->siz++;
        pp->val += q;
        return pp;
    }

    int mid = (l + r) / 2;
    if (mid >= q) {
        pp->l = add(pp->l, l, mid, q);
    } else pp->r = add(pp->r, mid + 1, r, q);
    pushup(pp);
    return pp;

}


void add(int j, int k) {
    int x = 1e6+10;
    t[j] = add(t[j - 1], 1, x, k);
}

int query(int l, int r, int k) {
    int x = 1e6+10;
    return query(t[r], t[l - 1], 1, x, k);
}


void init() {
}


void solve() {
    int n;
    cin >> n;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        ans[i] = i * i + ans[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        add(i, x);
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        int anss = query(l, r, k);
        debug(anss + ans[r - l + 1]);
        cout << anss + ans[r - l + 1] << endl;
    }

}

signed main() {
    IOS;
    init();
    // debug(1);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
