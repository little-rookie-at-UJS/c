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

// g[h[x]]  =x  h[g[x]] = f[x]
void solve() {
    int n;
    cin >> n;
    int tot = 0;
    vector<int> g(n + 1), h(n + 1);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (!g[x]) g[x] = ++tot, h[tot] = x, g[i] = tot;
        else if (h[g[x]] == x) g[i] = g[x];
        else {
            cout << -1;
            return;
        }
    }
    cout << tot << endl;
    for (int i = 1; i <= n; i++) {
        cout << g[i] << " \n"[i == n];
    }
    for(int i = 1;i<=tot;i++)  cout << h[i] << " \n"[i == tot];
}

signed main() {
    IOS;
    init();
    // debug(1);
    int t = 1;
//    cin >> t;/**/
    while (t--) {
        solve();
    }
}
