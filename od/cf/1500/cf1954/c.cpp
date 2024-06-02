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
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int i = 0;
    while (i < n && s1[i] == s2[i]) {
        i++;
    }
    if (i < n && s1[i] > s2[i]) {
        swap(s1[i], s2[i]);
    }
    i++;
    while (i < n) {
        if (s1[i] < s2[i]) {
            swap(s1[i], s2[i]);
        }
        i++;
    }
    cout << s1 << endl;
    cout << s2 << endl;

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
