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
    int sums = 0;
    for (int i = 1; i <= n; i++) {
        sums += i * (2 * i - 1);
    }
    cout << sums << " " << 2 * n << endl;
    for (int j = n; j; j--) {
        for (int i = 1; i <= 2; i++) {
            cout << i << " " << j << " ";
            for (int k = 1; k <= n; k++) {
                cout << k << " ";
            }
            cout << endl;
        }
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
