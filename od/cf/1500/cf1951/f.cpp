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

struct fenwick_tree {
    vector<int> bit;
    int n;

    fenwick_tree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    fenwick_tree(vector<int> a) : fenwick_tree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void init() {
}


void solve() {
    int n, k;
    cin >> n >> k;
    fenwick_tree fenwick(n);
    vector<int> a(n + 1), cnt(n + 1), ip(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ip[a[i]] = i;
        cnt[i] = fenwick.sum(a[i]);
        sum += (i - cnt[i] - 1);
        fenwick.add(a[i], 1);
    }
    if (k < sum || k > n * (n - 1) - sum || (k - sum) % 2) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<int> ans(n + 1);
    k -= sum;
    k /= 2;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] < k) {
            k -= cnt[i];
        } else {
            if(i==1){
                for (int j = 1; j <= n; j++) ans[j] = j;
                break;
            }
            for (int j = 1, v = i; j < i; j++) {
                ans[j] = v--;
                if (a[j] < a[i] && --k == 0) {
                    ans[i] = v--;
                }
            }
            for (int j = i + 1; j <= n; j++) ans[j] = j;
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[ip[i]] << " ";
    }
    cout << endl;
//    int left =
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
