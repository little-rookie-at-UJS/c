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

//#define endl '\n'
#define int ll

using VI = vector<int>;
using VII = vector<VI>;
using PII = pair<int, int>;
const int inf = 1e18;
const int mod = 1e9 + 7;

void init() {
}
//4 3
//4 9
//4 9
//4 9
//1 2

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 1; i <= k + 1; i++) {
        cout << "? ";
        for (int j = 1; j <= k + 1; j++) {
            if (j == i)continue;
            cout << j << " ";
        }
        cout << endl;
        int x, y;
        cin >> x >> y;
        mp[y]++;
    }
    int maxs = -1;
    for (auto [i, j]: mp) {
        maxs = max(maxs, i);
    }
    cout << "! " << mp[maxs] << endl;
}

signed main() {
//    IOS;
    init();
    // debug(1);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}
