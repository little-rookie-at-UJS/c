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
    vector<int> arr(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[x]++;
    }
    int mexs = 0;
    int nes = 1;
    for (int i = 0; i <= n; i++) {
        if (arr[i] > 1 || nes && arr[i] == 1) {
            mexs++;
            if (arr[i]==1)nes =0;
        } else break;
    }
    cout << mexs << endl;

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
