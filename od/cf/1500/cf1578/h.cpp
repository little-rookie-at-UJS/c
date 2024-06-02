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

//线段树
class SegmentTree {
private:
    struct Node {
        int l, r;
        int sum;
        int lazy;
    };
    vector<Node> tree;
    int n;

#define ls q<<1
#define rs q<<1|1

    void pushup(int q) {
        tree[q].sum = min(tree[ls].sum, tree[rs].sum);
    }

    void add(int q, int v) {
        tree[q].sum += v;
        tree[q].lazy += v;
    }

    void pushdown(int q) {
        if (tree[q].lazy) {
            add(ls, tree[q].lazy);
            add(rs, tree[q].lazy);
            tree[q].lazy = 0;
        }
    }

    void build(int q, int l, int r, const vector<int> &arr) {
        tree[q].l = l;
        tree[q].r = r;
        if (l == r) {
            tree[q].sum = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(ls, l, mid, arr);
        build(rs, mid + 1, r, arr);
        pushup(q);
    }

    void modify(int q, int l, int r, int L, int R, int k) {
        if (l >= L && r <= R) {
            add(q, k);
            return;
        }
        if (l > R || r < L)return;
        pushdown(q);
        int mid = (l + r) >> 1;
        if (mid >= L) modify(ls, l, mid, L, R, k);
        if (mid < R) modify(rs, mid + 1, r, L, R, k);
        pushup(q);
    }

    int query(int q, int l, int r, int L, int R) {
        if (l >= L && r <= R) {
            return tree[q].sum;
        }
        if (l > R || r < L)return 0;
        pushdown(q);
        int mid = (l + r) >> 1;
        int ans = inf;
        if (mid >= L) ans = min(ans, query(ls, l, mid, L, R));
        if (mid < R) ans = min(ans, query(rs, mid + 1, r, L, R));
        pushup(q);
        return ans;
    }

#undef ls
#undef rs

public:
    SegmentTree() = default;

    SegmentTree(int n) {
        this->n = n;
        tree.resize(4 * n + 1);
        build(1, 1, n, vector<int>(n + 1, 0));
    }

    SegmentTree(const vector<int> &arr) {
        n = arr.size();
        tree.resize(4 * n + 1);
        build(1, 1, n, arr);
    }

    void modify(int l, int r, int k) {
        modify(1, 1, n, l, r, k);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }


};


void solve() {
    map<int, int> mp;
    int n;
    cin >> n;
    vector<PII> arr(n + 1);
    set<int> st;
    st.insert(-1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
        st.insert(arr[i].first);
        st.insert(arr[i].first+1);
        st.insert(arr[i].second);
        st.insert(arr[i].second+1);
    }
//    sort(arr.begin() + 1, arr.end(), [](PII a, PII b) {
//        return (a.second - a.first) < (b.second - b.first);
//    });
    debug(arr);
    vector<int> vec(st.begin(), st.end());
    for (int i = 0; i < vec.size(); i++) {
        mp[vec[i]] = i;
    }
    SegmentTree tree(vec.size());
    for (int i = 1; i <= n; i++) {
        tree.modify(mp[arr[i].first], mp[arr[i].second], 1);
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        int mins = tree.query(mp[arr[i].first], mp[arr[i].second]);
        debug(mins);
        if (mins > 1) {
            ans = i;
            break;

        }
    }
    cout << ans << endl;
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
