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

//#define endl '\n'
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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if (a < c)swap(a, c);
    if (a < b)swap(a, b);
    if (b < c)swap(b, c);

    int n1 = 0, n2 = 0, n3 = 0;
    int maxs = inf;
    int sums = (a + b + c) * n;
//     n1*(c-a) + n2*(c-b) +  n *c
    auto check = [&](int x, int y, int z) {
        return x * (a - c) + y * (b - c) + z * c;
    };
    for (int i = 0; i <= n; i++) {
        int l = 0, r = n - i;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(i, mid, n) * 3 < sums) l = mid + 1;
            else r = mid;
        }
        if (abs(sums - check(i, l, n) * 3) < maxs) {
            maxs = abs(sums - check(i, l, n) * 3);
            n1 = i;
            n2 = l;
            n3 = n - i - l;
        }
        if (abs(sums - check(i, l + 1, n) * 3) < maxs && (i + l + 1) <= n) {
            maxs = abs(sums - check(i, l + 1, n) * 3);
            n1 = i;
            n2 = l + 1;
            n3 = n - i - l - 1;
        }
        if (abs(sums - check(i, l - 1, n) * 3) < maxs && (l - 1) >= 0) {
            maxs = abs(sums - check(i, l - 1, n) * 3);
            n1 = i;
            n2 = l - 1;
            n3 = n - i - l + 1;
        }
    }
    int x, y, z;
    assert(n1 + n2 + n3 == n);
    assert(n1 >= 0 && n2 >= 0 && n3 >= 0);

    for (int i = 0; i < n1; i++) {
        cout << a << endl;
        cin >> x >> y;
    }
    for (int i = 0; i < n2; i++) {
        cout << b << endl;
        cin >> x >> y;
    }
    for (int i = 0; i < n3; i++) {
        cout << c << endl;
        cin >> x >> y;
    }
}

signed main() {
    IOS;
    init();
    // debug(1);
    debug((47278 + 61415 * 2) * 3 - 598254);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
