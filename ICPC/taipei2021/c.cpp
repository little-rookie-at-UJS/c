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
//#define int ll

using VI = vector<int>;
using VII = vector<VI>;
using PII = pair<int, int>;
//const int inf = 1e18;
//const int mod = 1e9 + 7;
template<typename T, typename Compare =less<>>
using pqinit = priority_queue<T, vector<T>, Compare>;

void init() {
}

class STG {
    struct node {
        priority_queue<int> part, all;
        int l, r;
    };
    set<int> er;
    vector<node> tr;

    void build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    void update(int q) {
        while (!tr[q].part.empty() && er.count(tr[q].part.top())) {
            tr[q].part.pop();
        }
        while (!tr[q].all.empty() && er.count(tr[q].all.top())) {
            tr[q].all.pop();
        }
    }

public:
    STG(int n) : tr(n << 2) {
        build(1, 1, n);
    }

    void insert(int u, int l, int r, int x) {
        update(u);
        tr[u].part.push(x);
        if (tr[u].l >= l && tr[u].r <= r) {
            tr[u].all.push(x);
            return;
        }
        if (l > tr[u].r || r < tr[u].l)return;
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid) insert(u << 1, l, r, x);
        if (r > mid) insert(u << 1 | 1, l, r, x);
    }

    int query(int u, int l, int r) {
        update(u);
        if (tr[u].l >= l && tr[u].r <= r) {
            if (!tr[u].part.empty()) return tr[u].part.top();
            else return 0;
        }
        if (l > tr[u].r || r < tr[u].l)return 0;
        int mid = (tr[u].l + tr[u].r) >> 1;
        int ans = 0;
        if (l <= mid) ans = query(u << 1, l, r);
        if (r > mid) ans = max(ans, query(u << 1 | 1, l, r));
        if (!tr[u].all.empty())
            ans = max(ans, tr[u].all.top());
        return ans;
    }

    void erase(int x) {
        er.insert(x);
    }
};

//12 10
//1 Jessica 5 10
//1 Sara 4 7
//1 Peter 7 9
//2 3 5
//2 3 7
//1 Olivia 4 6
//2 1 3
//2 8 8
//2 8 9
//2 3 11
void solve() {
    int n, m;
    cin >> n >> m;
    STG stg(n);
    map<int, string> mp;
    mp[0] = ">_<";
    for (int i = 1; i <= m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            string s;
            int l, r;
            cin >> s >> l >> r;
            mp[i] = s;
            l++;
            r++;
            stg.insert(1, l, r, i);
        } else {
            int l, r;
            cin >> l >> r;
            l++;
            r++;
            int ans = stg.query(1, l, r);
            stg.erase(ans);
            cout << mp[ans] << endl;
        }
    }


    cout << endl;
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
