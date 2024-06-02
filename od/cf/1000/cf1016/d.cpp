
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
    int n;
    cin >> n;
    vector<int> tong(64), res(n + 1), arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        int x = arr[i];
        int len = 0;
        while (!(x & 1)) {
            len++;
            x >>= 1;
        }
        res[i] = len;
        tong[len]++;
    }
    int mx = 0, len = -1;
    for (int i = 0; i < 64; i++) {
        if (tong[i] > mx) {
            mx = tong[i];
            len = i;
        }
    }
    cout << n - mx << endl;
    for (int i = 1; i <= n; i++) {
        if (res[i] != len)cout << arr[i] << " ";
    }
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
