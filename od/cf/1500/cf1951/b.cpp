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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int maxs = 0;
    for (int i = 1; i <= 2; i++) {
        swap(arr[i], arr[k]);
        debug(arr);
        if (arr[i] < arr[3 - i]) {
            swap(arr[i], arr[k]);
            continue;
        } else {
            int ans = 1;
            for (int j = 3; j <= n; j++) {
                if (arr[i] > arr[j]) ans++;
                else break;
            }
            maxs = max(maxs, ans);
        }
        swap(arr[i], arr[k]);

    }
    for (int i = 1; i <= n; i++) {
        if (arr[i] > arr[k]) {
            swap(arr[i], arr[k]);
            debug(arr);
            int nowwin = 1;
            int ans = 0;
            for (int j = 2; j <= n; j++) {
                if (arr[j] > arr[nowwin]) {
                    nowwin = j;
                }
                if (nowwin == i) ans++;
            }
            maxs = max(maxs, ans);
            break;
        }
    }
    cout << maxs << endl;

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
