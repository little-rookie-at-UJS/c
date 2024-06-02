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
#define i128 ll
using VI = vector<int>;
using VII = vector<VI>;
using PII = pair<int, int>;
const int inf = 1e18;
const int mod = 1e9 + 7;

void init() {
}


void solve() {
    int n, k, m, a, b;
    cin >> n >> k >> m >> a >> b;
    if (k == 1) {
        if (n % m != 0)
            cout << (-1) << endl;
        else cout << 0 << endl;
    } else {
        int maxs = inf;
        int ans1 = 0;
        while (n) {
            int k1 = n % m;
            int ans2 = 0;
            int q = 1;
            int t = 60;
            while (t--) {
                int t2 = (m - k1) % m;
                if (t2 < q) {
                    maxs = min(ans1 + ans2, maxs);
                    break;
                }
                k1 *= k;
                k1 %= m;
                q *= k;
                ans2 += a;
            }
            n /= k;
            ans1 += b;
        }
        maxs = min(ans1, maxs);
        cout << maxs << endl;
    }

}

signed main() {
    IOS;
    init();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
