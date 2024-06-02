#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n + 1);
    vector<i64> b(n + 1);
    i64 l = 0, r = 2e9;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    auto check = [&](i64 x) -> bool {

        pair<i64, i64> be = {-2e19, 2e18};
        for (i64 i = 1; i <= n; i++) {
            i64 rr = a[i] + x * b[i];
            i64 ll = a[i] - x * b[i];

            rr = min(rr, be.second);

            ll = max(ll, be.first);
            be = {ll, rr};
            if (ll > rr) {
                return false;
            }
        }
        return true;
    };

    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid) ) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << r << endl;

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}
//2
//4
//8 3 3 5
//1 2 3 2
//5
//4 3 4 5 6
//3 1 3 1 1