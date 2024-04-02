#include "bits/stdc++.h"

using namespace std;

#ifndef ONLINE_JUDGE
#include "test.h"
#include "dbg.h"
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

//3 3
// 2 2
// 3 1
// 2 3
void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    vector<int> sufmax(n + 1);
    sufmax[n] = arr[n].first;
    set<int> s;
    for (int i = n - 1; i >= 0; i--)
        sufmax[i] = max(sufmax[i + 1], arr[i].first);
    priority_queue<PII, vector<PII>, greater<>> time;
    priority_queue<tuple<int, int,int>, vector<tuple<int, int,int>>, greater<>> pq;
    int now = 1;
    // 到第几个人了
    int cnt = 1;
    while (now <= k) {
        int i = cnt;
        if (!pq.empty()) {
            auto [k,_ , id] = pq.top();
            if (-k > sufmax[cnt]) {
                pq.pop();
                i = id;
            }
            else {
                cnt++;
            }
        }
        else cnt++;
        s.insert(i);
        if (s.size() == n) {
            cout << now << endl;
            return;
        }
        time.emplace(now + arr[i].second, i);

        // time
        while (!time.empty() && time.top().first <= now) {
            auto [_,id] = time.top();
            pq.emplace(-arr[id].first, now, id);
            time.pop();
        }
        now++;
    }
    cout << -1 << endl;
}

signed main() {
    IOS;
    init();
    int t = 1;
    // debug(t);
    // dbg(t);
    cin >> t;

    while (t--) {
        solve();
    }
}
