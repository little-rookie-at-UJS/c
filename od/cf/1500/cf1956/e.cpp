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
    vector<int> arr(n);
    int maxs = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxs = max(maxs, arr[i]);
    }
    vector<int> hit(n);
    for (int i = 0; i < n; i++) {
        hit[i] = 1 + i;
    }
    hit[n - 1] = 0;
    int k = -1;
    vector<int> q;
    for (int i = 0; i < n; i++) {
        q.push_back(i);
    }
    while (k < 2000) {
        k++;
        for (int i = 0; i < n; i++) {
            arr[hit[i]] = max(0LL, arr[hit[i]] - arr[i]);
        }
    }
    vector<int> p;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            p.push_back(i);
        }
    }
    assert(!p.empty());
    for (int i = 0; i < p.size(); i++) {
        int l = p[i] + 1, r = p[(i + 1) % p.size()];
        int len = (r - l + n) % n;
        assert(len <= 3);
        if (len == 2) {
            arr[(l + 1) % n] = 0;
        } else if (len == 3) {
            int &x = arr[l % n];
            int &y = arr[(l + 1) % n];
            int &z = arr[(l + 2) % n];
            int d = y / x;
            int tot = 1LL * (y - x + y - x * d) * d / 2;
            if (l == n - 1) {
                tot += y;
            }
            if (tot >= z) {
                z = 0;
            }
            y = 0;
        }
    }
//    for (int i = 0; i < n; i++) {
//        if (arr[i] > 0 && arr[hit[i]] > 0 && arr[hit[hit[i]]] > 0) {
//            assert(arr[hit[hit[hit[i]]]] == 0);
//            int a = arr[i];
//            int b = arr[hit[i]];
//            int c = arr[hit[hit[i]]];
//            int t = (b + a - 1) / a;
//            int sums = 0;
////            if (b > a)
//            sums = (2 * b - (t + 1) * a) * (t) / 2;
//            if (i == n - 1) {
//                sums += b;
//            }
//            arr[hit[i]] = 0;
//            if (sums >= c) {
//                arr[hit[hit[i]]] = 0;
//            }
//        }else if (arr[i] > 0 && arr[hit[i]] > 0) {
//            arr[hit[i]] = 0;
//        }
//    }
    int alive = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
//        cout<<arr[i]<<" ";
        if (arr[i] > 0) {
            alive++;
            ans.push_back(i + 1);
        }
    }

    cout << alive << endl;
    for (auto i: ans) {
        cout << i << " ";
    }
    cout << endl;
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
