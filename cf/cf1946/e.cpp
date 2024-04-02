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
const int maxn = 1e6 + 10;

vector<int> fact, infac;
int qpow(int a,int b) {
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

void init() {
    fact.resize(maxn);
    infac.resize(maxn);
    fact[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }
    infac[maxn - 1] = qpow(fact[maxn - 1], mod - 2);
    for (int i = maxn - 2; i >= 0; i--) {
        infac[i] = infac[i + 1] * (i + 1);
        infac[i] %= mod;
    }
}

int C(int n,int m) {
    if (n < m || m < 0 || n < 0)return 0;
    return fact[n] * infac[m] % mod * infac[n - m] % mod;
}


void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<int> arr1(m1 + 1), arr2(m2 + 1);
    for (int i = 1; i <= m1; i++)cin >> arr1[i];
    for (int i = 1; i <= m2; i++)cin >> arr2[i];
    if (arr1[1] != 1 || arr2[m2] != n || arr1[m1] != arr2[1]) {
        cout << 0 << endl;
        return;
    }
    int ans = C(n - 1, arr2[1] - 1);
    // debug(ans);
    for (int i = m1 - 1; i >= 1; i--) {
        ans = ans * C(arr1[i + 1] - 2, arr1[i] - 1) %
              mod * fact[arr1[i + 1] - arr1[i] - 1] % mod;
        // debug(ans);
    }
    for (int i = 2; i <= m2; i++) {
        ans = ans * C((n - arr2[i - 1] -1), arr2[i] - arr2[i - 1] - 1) % mod
              * fact[arr2[i] - arr2[i - 1] - 1] % mod;
        // debug(ans);
    }
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
