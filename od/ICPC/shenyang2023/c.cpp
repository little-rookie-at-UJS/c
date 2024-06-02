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
    int x, y;
    cin >> x >> y;
    if (x == 0) {
        if (y == 0) {
            cout << 4 << endl;
        } else if (y == 1) {
            cout << 4 << endl;
        } else {
            cout << 6 << endl;
        }
    } else if (x == 1) {
        if (y == 0) {
            cout << 3 << endl;
        }else if(y == 1){
            cout << 3 << endl;
        } else{
            cout << 4 << endl;
        }
    }else{
        if (y == 0) {
            cout << 2 << endl;
        }else if(y == 1){
            cout << 2 << endl;
        } else{
            cout << 2 << endl;
        }
    }
}

signed main() {
    IOS;
    init();
    // debug(1);
    int t = 1;

    while (t--) {
        solve();
    }
}
