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

void init() {
}

struct node {
    int l, r;
};

node ands(node &n1, node &n2) {
    int l = max(n1.l, n2.l);
    int r = min(n1.r, n2.r);
    if (l > r) l = r;
    node n;
    n.l = l;
    n.r = r;
    return n;
}

void solve() {
    int n;
    cin >> n;
    vector<node> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].l >> arr[i].r;
    }
    vector<node> pre(n + 1);
    vector<node> end(n + 1);
    pre[1] = arr[1];
    for (int i = 2; i <= n; i++) {
        pre[i] = ands(pre[i - 1], arr[i]);
    }
    end[n] = arr[n];
    for (int i = n - 1; i; i--) {
        end[i] = ands(end[i + 1], arr[i]);
    }
    int ans1 = max(pre[n - 1].r - pre[n - 1].l, end[2].r - end[2].l);
    for (int i = 2; i < n; i++) {
        node nn = ands(pre[i - 1], end[i + 1]);
        ans1 = max(ans1, nn.r - nn.l);
    }
    cout << ans1 << endl;
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
