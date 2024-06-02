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
    vector<int> arr(n + 1), ans(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int mins = -1;

    ans[1] = 1;
    for (int i = 2; i <= n; i++) {
        ans[i] = min(arr[i], ans[i - 1] + 1);

    }
    ans[n] = 1;
    for (int i = n - 1; i; i--) {
        ans[i] = min({ans[i], ans[i + 1] + 1});
    }
    for (int i = 1; i <= n; i++) {
        mins = max(mins, ans[i]);
    }
    debug(ans);
    cout << mins << endl;
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
