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

// 12 10
// 1 Jessica 5 10
// 1 Sara 4 7
// 1 Peter 7 9
// 2 3 5
// 2 3 7
// 1 Olivia 4 6
// 2 1 3
// 2 8 8
// 2 8 9
// 2 3 11
void solve() {
    vector<int> qpow(20);
    qpow[0] = 1;
    for (int i = 1; i < 20; i++) {
        qpow[i] = qpow[i - 1] * 10;
    }
    int n, mods;
    cin >> n >> mods;
    vector<int> ans1(1 << n, -1);
    ans1[0] = 0;
    for (int i = 0; i < (1 << n); i++) {
        int ansssss = i;
        ansssss = ~ansssss;
        while (ansssss) {
            int k = ansssss & -ansssss;
            ansssss -= k;
            k = __lg(k);
            if (k >= n)break;
            if ((1 << k) & i) continue;
            if (ans1[i] != -1) { ans1[i | (1 << k)] = ans1[i] + 1; }
        }
    }
    debug(ans1);
    vector ans2(1 << n, vector<int>(mods + 1, -1));
    vector<int> arr(n);
    for (auto &i: arr) cin >> i;
    ans2[0][0] = 0;
    for (int i = 0; i < (1 << n); i++) {
        int ansssss = i;
        ansssss = ~ansssss;
        while (ansssss) {
            int k = ansssss & -ansssss;
            ansssss -= k;
            k = __lg(k);
            if (k >= n)break;
            if ((1 << k) & i) continue;
            for (int j = 0; j < mods; j++) {
                if (ans2[i][j] == -1)continue;
                int a = ans2[i][j];
                int b = ans1[i];
                int anss = a + qpow[b] * arr[k];
                ans2[i | (1 << k)][anss % mods] = max(ans2[i | (1 << k)][anss % mods], anss);
            }
        }
    }
    for (int i = mods - 1; i >= 0; i--) {
        if (ans2[(1 << n) - 1][i] != -1) {
            cout << ans2[(1 << n) - 1][i] << endl;
            return;
        }
    }

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
