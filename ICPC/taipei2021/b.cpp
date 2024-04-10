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
    string s1, s2;
    cin >> n >> s1 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += s1[i] == s2[i];
    }
    priority_queue<tuple<int, int, int, int>> a;
    a.emplace(ans, -1, -1, -1);
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++) {
        l = r = i;
        int k = ans;
        while (l > 1 && r < n) {
            l--;
            r++;
            k -= s1[l] == s2[l];
            k -= s1[r] == s2[r];
            k += s1[r] == s2[l];
            k += s1[l] == s2[r];
            a.emplace(k, -(r - l + 1), -l, -r);
        }
    }
    for (int i = 1; i <= n; i++) {
        l = i + 1;
        r = i;
        int k = ans;
        while (l > 1 && r < n) {
            l--;
            r++;
            k -= s1[l] == s2[l];
            k -= s1[r] == s2[r];
            k += s1[r] == s2[l];
            k += s1[l] == s2[r];
            a.emplace(k, -(r - l + 1), -l, -r);
        }
    }
    auto [t1, t2, t3, t4] = a.top();
    cout << ans << " " << t1 << " " << -t3 << " " << -t4 << endl;
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
