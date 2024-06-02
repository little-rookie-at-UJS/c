#include "bits/stdc++.h"

using namespace std;

#ifndef ONLINE_JUDGE
#include "test.h"
#include "dbg.h"
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
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    double sums = 0;
    for (int i = 1; i < n; i++) {
        double nn = n, ii = i;
        sums += (1.0 * (ii) * (nn - ii + 1.0) * (nn - ii) / (2.0 * nn * (nn + 1)));
    }
    vector<int> fiw1(n + 1), fiw2(n + 1);
    auto add = [&](vector<int>&fiw, int len,int k) {
        while (len <= n) {
            fiw[len] += k;
            len += len & -len;
        }
    };
    auto query = [&](vector<int>&fiw,int len) {
        int ans = 0;
        while (len) {
            ans += fiw[len];
            len -= len & -len;
        }
        return ans;
    };
    double ans1 = 0, ans2 = 0;
    for (int i = n; i; i--) {
        ans1 += query(fiw1, arr[i]);
        add(fiw1, arr[i], 1);
        double t = query(fiw2, arr[i]);
        t *= double(i);
        ans2 += t;
        add(fiw2, arr[i], n - i + 1);
    }
    debug(sums, ans1, ans2);
    debug(ans2*2.0 / (double(n) * double(n + 1) ));
    sums = sums + ans1 - (ans2 * 2.0 / (double(n) * double(n + 1)));
    printf("%.10lf", sums);
}

signed main() {
    // IOS;
    init();
    // debug(1);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
