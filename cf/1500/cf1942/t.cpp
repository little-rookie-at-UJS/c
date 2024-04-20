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
const int mod = 998244353;

int qpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        b /= 2;
    }
    return ans;
}

const int maxn = 1e6 + 10;


vector<int> fac(maxn), infac(maxn);

void init() {
    fac[0] = infac[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    infac[maxn - 1] = qpow(fac[maxn - 1], mod - 2);
    for (int i = maxn - 2; i; i--) {
        infac[i] = infac[i + 1] * (i + 1) % mod;
    }
}

int C(int n, int m) {
    if (n - m < 0)return 0;
    if (n == 0 || m == 0 || n == m)return 1;
    return fac[n] * infac[m] % mod * fac[n - m] % mod;
}


void solve() {
//    vector<int>

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
