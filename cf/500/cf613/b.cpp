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
    int n, A, c1, c2, m;
    cin >> n >> A >> c1 >> c2 >> m;
    vector<PII> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin() + 1, arr.end(), [](PII a, PII b) {
        return a.first < b.first;
    });

    vector<int> sum(n + 1);

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + arr[i].first;
    }
    array<int, 3> ans = {0, 0, 0};

    int maxnumber = 0;
    int cost1 = 0;
    int maxs = -1;

    debug(arr);
    auto check = [&](int cost, int to, int rr) {
        //第一个二分找到 1 -rr 中 小于等于to的最大坐标
        int l = 1, r = rr;
        if (arr[1].first > to) return make_pair(true, 0ll);
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (arr[mid].first <= to) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        int sums = -sum[l] + l * to;
//        return sums <= cost;
        return make_pair(sums <= cost, l);
    };

    while (maxnumber <= n && cost1 <= m) {
        int left = m - cost1;
        int rr = n - maxnumber;
        int l = 0, r = A;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            debug("Check", left, mid, rr);
            if (check(left, mid, rr).first) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (maxs < maxnumber * c1 + l * c2) {
            auto [_, ll] = check(left, l, rr);
            maxs = maxnumber * c1 + l * c2;
            ans = {maxnumber, l, ll};
        }
        cost1 += max(0ll, A - arr[n - maxnumber].first);
        maxnumber++;
    }
    cout << maxs << endl;
    debug(ans);
    for (int i = 1; i <= ans[2]; i++) {
        arr[i].first = ans[1];
    }
    for (int i = 0; i < ans[0]; i++) {
        arr[n - i].first = A;
    }
    debug(arr);
    sort(arr.begin() + 1, arr.end(), [](PII a, PII b) {
        return a.second < b.second;
    });
    for (int i = 1; i <= n; i++) {
        cout << arr[i].first << " ";
    }




//    vector<int> arr(n + 1);
//    for (int i = 1; i <= n; i++) {
//        cin >> arr[i];
//    }
//    sort(arr.begin() + 1, arr.end());
//    vector<int> sum(n + 1);
//    for (int i = 1; i <= n; i++) {
//        sum[i] = sum[i - 1] + arr[i];
//    }
//    int maxnumber = 0;
//    int cost1 = 0;
//    int maxs = -1;
//    debug(arr);
//    int nl, nr, nm;
//    auto check = [&](int cost, int to, int rr) {
//        //第一个二分找到 1 -rr 中 小于等于to的最大坐标
//        int l = 1, r = rr;
//        if (arr[1] > to) return true;
//        while (l < r) {
//            int mid = (l + r + 1) >> 1;
//            if (arr[mid] <= to) {
//                l = mid;
//            } else {
//                r = mid - 1;
//            }
//        }
//        int sums = -sum[l] + l * to;
//        return sums <= cost;
//    };
//    while (maxnumber <= n && cost1 <= m) {
//        int left = m - cost1;
//        int rr = n - maxnumber;
//        int l = 0, r = A;
//        while (l < r) {
//            int mid = (l + r + 1) >> 1;
//            debug("Check", left, mid, rr);
//            if (check(left, mid, rr)) {
//                l = mid;
//            } else {
//                r = mid - 1;
//            }
//        }
//
//        maxs = max(maxs, maxnumber * c1 + l * c2);
//        cost1 += max(0ll, A - arr[n - maxnumber]);
//        maxnumber++;
//        debug(maxnumber, cost1, maxs);
//    }
//    cout << maxs << endl;
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
