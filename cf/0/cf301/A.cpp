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
    vector<int> arr(2 * n - 1);
    for (auto &i: arr) {
        cin >> i;
    }
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
        sum1 += arr[i];
    }
    int absmax = inf;
    for (int i = 0; i < 2 * n - 1; i++) {
        sum2 += abs(arr[i]);
        absmax = min(absmax, abs(arr[i]));

    }
    if (n % 2 == 0) {
        sum2 -= absmax * 2;
    }
    int sums3 = 0;
    sums3 = sum1;
    ranges::sort(arr);
    for (int i = 0; i < 2 * n - 1; i += 2) {
        sums3 = max(sums3, sums3 - 2 * (arr[i] + arr[i + 1]));
    }
    debug(sum1, sum2, absmax, sums3);
    cout << max({sum1, sum2, sums3}) << endl;
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
