#include "bits/stdc++.h"

using namespace std;

using i64 = long long;


const int maxs = 1e6 + 100;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<i64> arr(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> arr[i];
    }

    vector<i64> f(m + 2, 1e18);
    f[m + 1] = 0;
    for (i64 i = m; i; i--) {
        for (i64 j = 0; j <= 110; j++) {
            if (i + j > m)break;
            i64 ned = (j + 1) * (j + 1) * (j + 1) * (j + 1);
            i64 tim = arr[i + j];
            f[i] = min(f[i], tim + ned + f[i + j + 1]);
        }
    }
    cout << f[1] << endl;

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }

}
