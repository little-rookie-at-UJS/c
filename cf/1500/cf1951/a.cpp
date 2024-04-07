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
    string s;
    int n;
    cin >> n;
    cin >> s;
//    int n = s.size();
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') ans.emplace_back(i);
    }
    if (ans.size() % 2) cout << "NO" << endl;
    else {
        if(!ans.empty() && ans[0] - ans[ans.size()/2] ==-1) {
            cout << "NO" << endl;
        }else {
            cout << "YES" << endl;
        }
    }
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
