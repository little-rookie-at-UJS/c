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


struct vec {
    vector<int> v;
    vec(int m) : v(m) {}
    vec operator*(const vec &a) {
        vec ans(v.size());
        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < v.size(); j++)
                ans.v[(i + j) % v.size()] += v[i] * a.v[j], ans.v[(i + j) % v.size()] %= mod;
        return ans;
    }
    int &operator[](int i) {
        return v[i];
    }
    friend ostream &operator<<(ostream &os, const vec &v) {
        for (int i = 0; i < v.v.size(); i++)os << v.v[i] << " ";
        return os;
    }
    int size() {
        return v.size();
    }
};

vec qpow(vec a, int b) {
    vec ans(a.size());
    ans[0] = 1;
    for (; b; b >>= 1, a = a * a)
        if (b & 1) ans = ans * a;
    return ans;
}
void init() {
}


void solve() {
    int n, l, m;
    cin >> n >> l >> m;
    vec a(m), b(m), c(m);
    vector<int> v(n);
    for (int i = 0, x; i < n; i++)cin >> x, a.v[x % m]++;
    for (int i = 0, x; i < n; i++)cin >> x, v[i] = x, b.v[x % m]++;
    for (int i = 0, x; i < n; i++)cin >> x, x += v[i], c.v[x % m]++;
    b = a * qpow(b, l - 2) * c;
    cout << b.v[0] << endl;

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
