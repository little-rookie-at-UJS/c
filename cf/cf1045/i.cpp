#include "bits/stdc++.h"

using namespace std;

#ifndef ONLINE_JUDGE
#include "test.h"
#include "dbg.h"
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

//3
//aa
//bb
//cd

void solve() {
    int n;
    cin >> n;
    map<int,int> mp;
    int sums = 0;
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        string s;
        cin >> s;
        for (auto j: s) {
            ans ^= (1 << (j - 'a'));
        }
        for (int j = 0; j < 26; j++) {
            sums += mp[ans ^ (1 << j)];
        }
        sums += mp[ans];
        debug(sums);
        mp[ans]++;
    }
    cout << sums << endl;
}

signed main() {
    IOS;
    init();
    // debug(1);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
