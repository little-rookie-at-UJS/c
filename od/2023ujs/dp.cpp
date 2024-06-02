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
const int maxn = 1e6 + 7;

int qpow(int a, int b) {
    int ans = 1;
    while (b) {
        // debug(b);
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

int fac[maxn];
int infac[maxn];
int f[maxn][21];
int C(int n, int m) {
    if (n - m < 0) return 0;
    if (m == 0 || n == 0 || m - n == 0)return 1;
    return fac[n] * infac[m] % mod * infac[n - m] % mod;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fac[i] = i * fac[i - 1];
        fac[i] %= mod;
    }
    infac[0] = 1;
    infac[maxn - 1] = qpow(fac[maxn - 1], mod - 2);
    for (int i = maxn - 2; i; i--) {
        infac[i] = (i + 1) * infac[i + 1];
        infac[i] %= mod;
    }
    int k = 21;
    f[0][0] = 1;
    int maxs = 1;
    for (int i = 1; i < maxn; i++) {
        if ((1 << maxs) <= i) {
            maxs++;
        }
        f[i][0] = 1;
        int jj = (i - (1 << (maxs - 1)));
        for (int j = 1; j < k; j++) {
            f[i][j] = C(maxs - 1, j - 1) + f[jj][j];
        }
    }
    for (int i = 1; i < maxn; i++) {
        for (int j = 2; j < k; j++) {
            f[i][j] += f[i][j - 1];

        }
    }
    for (int i = 2; i < maxn; i++) {
        for (int j = 1; j < k; j++) {
            f[i][j] += f[i - 1][j];
            f[i][j] %= mod;
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    cout << f[n][k] << endl;
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