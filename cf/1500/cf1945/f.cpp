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
    //3
    // 9 8 14
    // 3 2 1
    int n;
    cin >> n;
    multiset<pair<int,int>> s;
    priority_queue<PII> pq;
    set<int> e;
    VI ans(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ans[i] = x;
        pq.emplace(x, i);
    }
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)cin >> arr[i];
    int now = 0;
    int maxs = 0, mins = 0;
    while (!pq.empty()) {
        now++;
        e.emplace(arr[now - 1]);
        s.erase(make_pair(ans[arr[now - 1]], arr[now - 1]));

        while (!pq.empty() && s.size() != now) {
            auto t = pq.top();
            pq.pop();
            if (!e.count(t.second))
                s.emplace(t);
        }
        auto f = *(s.begin());
        if (maxs < s.size() * f.first) {
            maxs = s.size() * f.first;
            mins = s.size();
        }
    }
    cout << maxs << " " << mins << endl;
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
