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
    int a, b;
    cin >> a >> b;
    int sums = a + b;
    int sums1 = 0;
    int i = 1;
    while (1) {
        if (sums1 + i > sums) break;
        sums1 += i;
        i++;
    }
    i;
    int left = a;
    int z = 0;
    vector<int> arr(i);
    for (int k = i - 1; k; k--) {
        if (k <= left) {
            arr[k] = 1;
            left -= k;
            z++;
        }
    }
    cout << z << endl;
    for (int k = 1; k < i; k++) {
        if (arr[k]) {
            cout << k << " ";
        }
    }
    cout << endl;
    cout << i - 1 - z << endl;
    for (int k = 1; k < i; k++) {
        if (!arr[k]) {
            cout << k << " ";
        }
    }
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
