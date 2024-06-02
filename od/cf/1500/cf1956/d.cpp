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

// build (l+1,r)
// build (l+2,r)
vector<pair<int, int>> op;

void build(int l, int r) {
    for (int i = l; i < r; i++) {
        build(i, r - 1);
        if (i + 1 <= r - 1) {
            op.push_back({i + 1, r - 1});
        }
    }
    op.push_back({l, r});

}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int maxs = 0;
    int ans = 0;
    auto count = [&](int x) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if ((1 << i) & x) {
                cnt += arr[i];
            } else {
                int len = 0;
                while (!((1 << i) & x) && i < n) {
                    len++;
                    i++;
                }
                cnt += len * len;
                i--;
            }
        }
        return cnt;
    };
    for (int i = 0; i < (1 << n); i++) {
        int cnt = count(i);
        if (cnt > maxs) {
            maxs = cnt;
            ans = i;
        }
    }
    debug(maxs, ans);

    for (int i = 0; i < n; i++) {
        if (!((1 << i) & ans)) {
            int n0 = 0;
            int l = i;
            int r = i;
            while (!((1 << r) & ans) && r < n) {
                if (arr[r] == 0) n0++;
                r++;
            }
            r--;
            if (n0) {
                op.emplace_back(l, r);
            }
            op.emplace_back(l, r);
            build(l, r);
            i = r;
        }
    }
    cout << maxs << " " << op.size() << endl;
    for (auto [x, y]: op) {
        cout << x + 1 << " " << y + 1 << endl;
    }



//    build(1, 5);
//    for (auto [x, y]: op) {
//        cout << x << " " << y << endl;
//    }

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
