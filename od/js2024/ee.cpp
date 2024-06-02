#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
const int maxn = 2e6;

class stg {
private:
    struct node {
         int l,r, val;

        node() {
            l = r = val = 0;
        }
    };

    int tot;
    vector<node> v;
    vector<int> ys;
#define rc(i) v[i].r
#define lc(i) v[i].l

    void pushup(int q) {
        v[q].val = v[rc(q)].val + v[lc(q)].val;
    }

    int add(int j, int l, int r, int q) {
        int len = tot;
        tot++;
        v[len] = v[j];
        if (l == r) {
            v[len].val++;
            return len;
        }
        int mid = (l + r) / 2;
        if (mid >= q) {
            v[len].l = add(lc(len), l, mid, q);
        } else {
            v[len].r = add(rc(len), mid + 1, r, q);
        }
        pushup(len);
        return len;
    }

    int query(int i, int j, int l, int r, int k) {
        if (l == r) {
            return l;
        }
        int mid = (l + r) / 2;
        if (lc(i)) {
            int siz = v[lc(i)].val - v[lc(j)].val;
            if (siz >= k) {
                return query(lc(i), lc(j), l, mid, k);
            }
            k -= siz;
        }
        return query(rc(i), rc(j), mid + 1, r, k);
    };


public:

    stg() {
        v.resize(maxn * 30);
        ys.resize(maxn);
        tot = 1;
    }

    void copy(int x, int y) {
        ys[x] = ys[y];
    }


    void add(int i, int j, int q) {
        ys[i] = add(ys[j], 1, maxn, q);
    }

    int query(int r, int l, int k) {
        r = ys[r];
        l = ys[l];
        int sz = v[r].val - v[l].val;
        if (sz < k) return 0;
        return query(r, l, 1, maxn, k);
    }


};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    stg s;
    vector<int> ans(maxn);
    vector<vector<int>> op(n + 1);

    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x) {
            pq.emplace(x, i);
        }
    }
    int time = 1;
    while (!pq.empty()) {
        auto [x, len] = pq.top();
        pq.pop();
        ans[time] = x;
        op[len].emplace_back(time);
        x /= 2;
        time++;
        if (x) {
            pq.emplace(x, len);
        }
    }
    for (int i = 1; i <= n; i++) {
        s.copy(i, i - 1);
        for (auto t: op[i]) {
            s.add(i, i, t);
        }
    }
    for (int i = 1; i <= q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        int len = s.query(r, l - 1, k+1);
        cerr << len << endl;
        cout << ans[len] << endl;

    }

}

