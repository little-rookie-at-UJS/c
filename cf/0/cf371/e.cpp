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
    //3
    //1 100 101
    //2
    cin >> n;
    vector<pair<int, int>> arr(n + 1);
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin()+1, arr.end());

    debug(arr);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + arr[i].first;
    }
    debug(sum);
    int k;
    cin >> k;
    int ans = 0;

    for (int i = 1; i < k; i++) {
        ans += (sum[k] - sum[i]) - arr[i].first * (k - i);
    }
    debug(ans);

    int maxx = ans;
    int lls = 1, rrs = k;
    int l = 1, r = k;
    while (r <  n) {
        r++;
        l++;
        debug(l, r);
        ans = ans + (k - 1) * (arr[r].first + arr[l - 1].first) - (sum[r - 1] - sum[l - 1]) * 2;
//        ans
        debug(ans);
        if (ans < maxx) {
            maxx = ans;
            lls = l;
            rrs = r;
        }

    }
    for (int i = lls; i <= rrs  ; i++) {
        cout << arr[i].second << " ";
    }
    debug(lls, rrs);

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
