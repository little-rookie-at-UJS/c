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


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int las = -1;
    int ans = n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != a[0]) {
            ans = min(ans, i - 1 - las);
            las = i;
        }
    }
    ans = min(ans, n - 1 - las);
    if (ans == n) {
        cout << "-1" << endl;
    } else {
        cout << ans << endl;
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
