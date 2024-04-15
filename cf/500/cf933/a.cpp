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
//4
//1 2 1 2

void solve() {
    int sums, k;
    cin >> sums >> k;
    vector<vector<pair<int, int>>> ans(k + 1);
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= k; i++) {
        int n;
        cin >> n;
        int su = 0;
        int mi = 0;
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            su += x;
            mi = min(mi, su);
            if (su > 0) {
                ans[i].push_back({mi, su});
//                pq.push({mi, su});
                su = 0;
                mi = 0;
            }
        }
        reverse(ans[i].begin(), ans[i].end());
        if (!ans[i].empty()) pq.push({ans[i].back().first, i});
    }
    while (!pq.empty() && sums + pq.top().first >= 0) {
        auto [mi, su] = pq.top();
        pq.pop();
        sums += ans[su].back().second;
        ans[su].pop_back();
        if (!ans[su].empty()) pq.push({ans[su].back().first, su});
    }
    cout << sums << endl;
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

//    vector<int> last(n + 2, 0);
//    for (int i = n; i; i--) {
//        if (arr[i] == arr[i + 1]) last[i] = last[i + 1];
//        else last[i] = i;
//    }

//    auto count = [&](int i) {
//        int ans = 0;
//        // 1
//        if (arr[i] == 1) {
//            ans += last[i] - i + 1;
//            if (last[i] == n) return ans;
//            i = last[i] + 1;
//        }
//        ans += last[i] - i + 1;
//        if (last[i] == n) return ans;
//        i = last[i] + 1;
//        ans += last[i] - i + 1;
//        if (last[i] == n) return ans;
//        i = last[i] + 1;
//        ans += last[i] - i + 1;
//        if (last[i] == n) return ans;
//        i = last[i] + 1;
//        return ans;
//    };