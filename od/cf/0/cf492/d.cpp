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
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin() + 1, arr.end(), greater<>());
    for (int i = 1; i <= n; i++) {
        arr[i] += arr[i - 1];
    }
    debug(arr);
    map<int, int> ans;
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        if (ans.count(x)) {
            cout << ans[x] << " ";
            continue;
        }
        int from = 1, len = 1, depth = 0;
        int anss = 0;
        while (from <= n) {
            int to = min(n, from + len - 1);
            int sum = arr[to] - arr[from - 1];
            anss += sum * depth;
            depth++;
            from = to + 1;
            len *= x;
        }
        ans[x] = anss;
        cout << anss << " ";
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
