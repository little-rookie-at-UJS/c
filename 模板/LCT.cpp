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

struct Node {
    int val, sum, swp;
    Node *l, *r, *p;

    Node() {
        val = sum = swp = 0;
        l = r = p = nullptr;
    }

    void Swap() {
        swp ^= 1;
        swap(l, r);
    }
};

struct LCT {
    vector<Node> nodes;

    LCT() = default;

    explicit LCT(int n) : nodes(n + 1) {};

    static void PushUp(Node *x) {
        x->sum = x->val ^ (x->l ? x->l->sum : 0) ^ (x->r ? x->r->sum : 0);
    }

    static void PushDown(Node *x) {
        if (x->swp) {
            if (x->l)x->l->Swap();
            if (x->r)x->r->Swap();
            x->swp = 0;
        }

    }

    static bool isRoot(Node *x) {
        return x->p == nullptr || (x->p->l != x && x->p->r != x);
    }

    void UpDate(Node *x) {
        if (!isRoot(x))UpDate(x->p);
        PushDown(x);
    }

    static void Rotate(Node *x) {
        Node *y = x->p, *z = y->p;
        if (!isRoot(y)) {
            if (y == z->l)z->l = x;
            else z->r = x;
        }
        if (x == y->l) {
            y->l = x->r;
            if (x->r)
                x->r->p = y;
            x->r = y;
        } else {
            y->r = x->l;
            if (x->l)
                x->l->p = y;
            x->l = y;
        }
        x->p = z;
        y->p = x;
        PushUp(y);
    }

    void Splay(Node *x) {
        UpDate(x);
        while (!isRoot(x)) {
            Node *y = x->p, *z = y->p;
            if (!isRoot(y)) {
                if ((y == z->l) ^ (x == y->l))Rotate(x);
                else Rotate(y);
            }
            Rotate(x);
        }
        PushUp(x);
    }

    void Access(Node *x) {
        for (Node *y = nullptr; x;) {
            Splay(x);
            x->r = y;
            PushUp(x);
            y = x;
            x = x->p;
        }
    }

    void MakeRoot(Node *x) {
        Access(x);
        Splay(x);
        x->Swap();
    }

    Node *FindRoot(Node *x) {
        Access(x);
        Splay(x);
        while (x->l) {
            PushDown(x);
            x = x->l;
        }
        Splay(x);
        return x;
    };

    void Link(Node *x, Node *y) {
        MakeRoot(x);
        if (FindRoot(y) != x)
            x->p = y;

    }

    void Cut(Node *x, Node *y) {
        MakeRoot(x);
        if (FindRoot(y) == x && y->p == x && !y->l) {
            x->r = y->p = nullptr;
            PushUp(y);
        }
    }

    int Query(Node *x, Node *y) {
        MakeRoot(x);
        Access(y);
        Splay(y);
        return y->sum;
    }

    void Update(Node *x, int v) {
        Splay(x);
        x->val = v;
        PushUp(x);
    }

    void link(int x, int y) {
        Link(&nodes[x], &nodes[y]);
    }

    void cut(int x, int y) {
        Cut(&nodes[x], &nodes[y]);
    }

    int query(int x, int y) {
        return Query(&nodes[x], &nodes[y]);
    }

    void update(int x, int v) {
        Update(&nodes[x], v);
    }


};

void init() {


}


void solve() {
    int n, m;
    cin >> n >> m;
    LCT lct(n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        lct.update(i, x);
    }
    for (int i = 1; i <= m; i++) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 0) {
            cout << lct.query(x, y) << endl;
        } else if (op == 1) {
            lct.link(x, y);
        } else if (op == 2) {
            lct.cut(x, y);
        } else {
            lct.update(x, y);
        }
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