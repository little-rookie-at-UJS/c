#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

const i64 mod = 998244353;

const i64 maxn = 1e6 + 10;

vector<i64> fact(maxn, 1);
vector<i64> infact(maxn, 1);

i64 comb(int x, int y) {
    if (x == 0 || x - y < 0) return 0;
    return (infact[x] * fact[y]) % mod * fact[x - y] % mod;
}
i64 qpow(i64 x, i64 y) {
    i64 ans = 1;
    while (y) {
        if (y & 1) {
            ans *= x;
            ans %= mod;
        }
        y /= 2;
        x *= x;
        x %= mod;
    }
    return ans;
}

i64 inv(i64 x) {
    return qpow(x, mod - 2);
}

void solve() {
//    2
//    1 2 -1 -1
    int n;
    cin >> n;
    vector<int> op(2 * n);
    priority_queue<int, vector<int>, greater<>> pq;
    map<int, int> mp;
    for (int i = 0; i < 2 * n; i++) {
        cin >> op[i];
        if (op[i] != -1) {
            pq.emplace(op[i]);
        }
    }
    i64 ans = 1;
    int left = 0;
    for (auto i: op) {

        if (i == -1) {
            auto x = pq.top();
            pq.pop();
            if (mp[x]) {

                ans *= mp[x];
                ans %= mod;
                ans *= inv(left);
                ans %= mod;
//                ans *= comb(left, mp[x]);
                mp[x]--;
                left--;
            } else {
                ans = 0;
                break;
            }
        } else {
            mp[i]++;
            left++;
        }
    }
    cout << ans << endl;
}



int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (i64 i = 1; i < maxn; i++) {
        fact[i] = (i * fact[i - 1] % mod);
    }
    infact[maxn - 1] = inv(fact[maxn - 1]);
    for (int i = maxn - 2; i; i--) {
        infact[i] = ((i + 1) * infact[i + 1]) % mod;
    }


    int t = 1;
//    cin >> t;
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