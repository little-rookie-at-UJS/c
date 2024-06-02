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
    string s1, s2;
    cin >> s1 >> s2;
    int maxs = max(s1.size(), s2.size()) + 10;
    auto count = [&](string &s) {
        reverse(s.begin(), s.end());
        s.resize(maxs, '0');
        int k = maxs - 2;
        while (k >= 0) {
            debug(k < maxs - 1, s[k] == '1', s[k - 1] == '1', k, s, s[k], s[k - 1]);
            while (k < maxs - 1 && s[k] == '1' && s[k - 1] == '1') {
                s[k + 1] = '1';
                s[k] = s[k - 1] = '0';
                k += 2;
            }
            k--;
        }
        reverse(s.begin(), s.end());
    };

    count(s1);
    count(s2);
    debug(s1, s2);
    if (s1 > s2)cout << ">" << endl;
    else if (s1 < s2)cout << "<" << endl;
    else cout << "=" << endl;
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
