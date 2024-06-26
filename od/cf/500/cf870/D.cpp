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
    // va p0^bi
    // vb b0^pi
    vector<int> va(n), vb(n), p, b;
    for (int i = 0; i < n; i++) {
        cout << "? 0 " << i << endl;
        cin >> va[i];
    }
    for (int i = 0; i < n; i++) {
        cout << "? " << i << " 0" << endl;
        cin >> vb[i];
    }
    int ans = 0;
    auto check = [&](int p0) {
        vector<int> tp(n), tb(n), ysp(n), ysb(n);
        for (int i = 0; i < n; i++) {
            // pi = pi^b0 ^ b0 ^p0 ^p0;
            tp[i] = vb[i] ^ vb[0] ^ p0;
            if (tp[i] > n) return;
            if (!ysp[tp[i]])ysp[tp[i]] = 1;
            else return;
        }
        for (int i = 0; i < n; i++) {
            tb[i] = va[i] ^ p0;
            if (tb[i] > n) return;
            if (!ysb[tb[i]])ysb[tb[i]] = 1;
            else return;
        }
        for (int i = 0; i < n; i++) {
            if (tp[tb[i]] != i) {
                return;
            }
        }
        ans++;
        p = tp;

    };
    for (int i = 0; i < n; i++) {
        check(i);
    }
    cout << "!" << endl;
    cout << ans << endl;
    for (auto i: p) {
        cout << i << " ";
    }
}

signed main() {

    init();
    int t = 1;
    while (t--) {
        solve();
    }
}
