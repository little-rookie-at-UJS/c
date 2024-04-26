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
    int k, n;
    cin >> k >> n;
    vector<pair<int, int>> p;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            p.emplace_back(i, cnt);
        }
    }
    if (n != 1) {
        p.emplace_back(n, 1);
    }

    int mins = inf;

    for (auto [i, j]: p) {
        debug(i, j);
        int mk = k;
        int aa = 0;
        while (mk) {
            mk /= i;
            aa += mk;
        }
//        int b = 0;
//        debug(aa);
//        while (aa >= j) {
//            b++;
//            j *= j;
//        }
        mins = min(mins,aa/j);
    }
    cout << mins << endl;

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

