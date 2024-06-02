#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void solve() {
    i64 n, d;
    cin >> n >> d;
    i64 k = 1234567890 + d;
    int t0 = 0;
    int mn = n;
    while (mn) {
        t0++;
        mn /= 10;
    }
    i64 to = k * pow(10, t0);
    i64 ans = (to + n - 1) / n;
//    cerr << ans * n << endl;
    cout << ans << endl;


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