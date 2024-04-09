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
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    string s;
    cin >> s;
    s = " " + s;
    vector<int> red;
    vector<int> blue;

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'R') {
            red.push_back(arr[i]);
        } else {
            blue.push_back(arr[i]);
        }
    }
    sort(red.begin(), red.end(), greater<>());
    sort(blue.begin(), blue.end());
    for (int i = 0; i < red.size(); i++) {
        if (red[i] > (n - i)) {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i = 0; i < blue.size(); i++) {
        if (blue[i] < (i + 1)) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
