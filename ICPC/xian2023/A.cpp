//
// Created by DELLPC on 2024/3/27.
//
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 mod = 998244353;

i64 qpow(i64 x, i64 k) {
    i64 ans = 1;
    while(k) {
        if(k & 1) {
            ans *= x;
            ans %= mod;
        }
        k >>= 1;
        x *= x;
        x %= mod;
    }
    return ans;
}
#define ll long long
const int N = 10000000 + 4;
int inv[N] = {1, 1};

int main() {
    i64 ans = 0;
    i64 n = 0;
    cin >> n;
    if(n == 1) {
        cout << 1;
        return 0;
    }
    // v[0] = 1;
    ll fr = 1;
    for(int i = 2; i <= n; ++ i) {
        inv[i] = (ll)(mod - mod / i) * inv[mod %i] % mod;
    }
    // for(i64 i = 1; i <= n; i++) {
    //     v[i] = (1ll * v[i - 1] * i) % mod;
    //     fr[i] = (1ll * fr[i - 1] * inv[i]) % mod;
    // }
    fr = 1;//F[n + 1 - ((n + 1) / 2) * 2];
    ll V = 1;
    for(int i = 1; i < (n - ((n + 1) / 2)); ++ i) {
        V *= i;
        V %= mod;
    }
    for(int i = (n + 1) / 2; i >= 1; -- i) {
        V *= (n - i), V %= mod;
        ans += fr * V % mod * V %  mod;
        fr *= (1ll * inv[n - (i * 2) + 3] * inv[n - (i * 2) + 2]) % mod;
        fr %= mod;
        ans %= mod;
    }
    cout << ans;
    // return;
    // for(int i = 1; i <= (n + 1) / 2  ; ++ i) {
    //     ans += (fr[n - i - i + 1] * v[n - i] % mod) * ( v[n - i] % mod) % mod;
    //     // cerr << ans << endl;
    //     ans %= mod;
    // }
    // cout << ans;

    // for(i64 i = 1; i <= n; i++) {
    //     ans += qpow(n - i, i - 1) * v[n - i] % mod;
    //     ans %= mod;
    // }
    // ans = (ans + mod) % mod;
    // cout << ans;
}
