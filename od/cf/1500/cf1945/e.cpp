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


void solve() {
    // 6 3
    // 1 2 3 4 5 6
    int n, q;
    cin >> n >> q;
    VI arr(n + 1);
    int len = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] == q) {
            len = i;
        }
    }
    int l = 1, r = n + 1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (arr[mid] <= q) {
            l = mid;
        }
        else r = mid;
    }
    if (arr[l] == q) {
        cout << 0 << endl;
    }
    else {
        cout << 1 << endl << len << " " << l << endl;
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
