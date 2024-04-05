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
    int n, x;
    cin >> n >> x;
    x++;
    VI arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] ^= arr[i - 1];
    }
    int ans = -1;
    int patten = 0;
    for (int i = 30; i >= 0; i--) {
        // debug(1<<i, x, x & (1 << i));
        if (x & (1 << i)) {
            patten |= 1 << i;
            if (arr[n] & patten) {
                patten ^= 1 << i;
                continue;
            }
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                int k = arr[j] & patten;
                if ((arr[j] & patten) == 0)
                    cnt++;
            }
            ans = max(ans, cnt);
            patten ^= 1 << i;
        }
        else {
            patten |= 1 << i;
        }
    }
    bitset<33> ass(patten);
    debug(ass);
    cout << ans << endl;
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
