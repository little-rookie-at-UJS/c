//
// Created by DELLPC on 24-5-19.
//
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;

#define  endl '\n'
#define ll long long
ll qpow(ll base, ll b, ll mod){
    ll ans = 1;
    while(b){
        if(b & 1)ans *= base, ans %= mod;
        base *= base, base %= mod, b >>= 1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    cout << qpow(2, qpow(2, n - 1, 998244352) - n + 998244352, 998244353);
}

