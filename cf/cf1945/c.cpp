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
    string s;
    cin >> s;
    s = " " + s;
    vector<int> c0(n + 2), c1(n + 2);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            c0[i]++;
        }
        else {
            c1[i]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        c0[i] += c0[i - 1];
    }
    for (int i = n - 1; i > 0; i--) {
        c1[i] += c1[i + 1];
    }
    int mins = n + 1000;
    for (int i = 0; i <= n; i++) {
        if (c0[i] * 2 >= i && c1[i + 1] * 2 >= (n - i)) {
            if (abs(n - i * 2) < abs(n - mins * 2)) {
                mins = i;
            }
        }
    }
    cout << mins << endl;
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
