#include <bits/stdc++.h>

#define MODE 1

#if MODE
#define debug(x) cout << #x << ": " << (x) << endl
#define log(x) cout << (x) << endl
#define test(x) x
#else
#define debug(x)
#define log(x)
#define test(x)
#endif

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fi first
#define se second
#define X real()
#define Y imag()

using namespace std;
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using P = complex<ll>;

template<typename S, typename T = S>
void chmin(S &s, T t) { s = s < t ? s : t; }

template<typename S, typename T = S>
void chmax(S &s, T t) { s = s > t ? s : t; }

const ll M = 1000000007; // 998244353

ll isqrt(ll v, ll g = 1e9) {
    while (true) {
        if (g * g <= v && (g + 1) * (g + 1) > v)
            return g;
        g = (g + v / g) / 2;
    }
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for (ll &i: a) cin >> i;

    vector<ll> v(n), f(n);
    v[0] = a[0];
    f[0] = isqrt(v[0]);
    for (int i = 1; i < n; ++i) {
        v[i] = f[i - 1] + a[i];
        f[i] = isqrt(v[i]);
    }

    map<int, ll> mp;
    for (int i = 0; i < n; ++i) {
        if (f[i] * f[i] != v[i]) mp[i] = v[i] - f[i] * f[i];
    }

    while (q--) {
        ll i, x;
        cin >> i >> x;
        --i;

        a[i] = x;

        for (; i < n; ++i) {
            bool stop = false;
            v[i] = (i == 0 ? 0 : f[i - 1]) + a[i];
            if (v[i] >= (f[i] + 1) * (f[i] + 1)) {
                f[i] = isqrt(v[i]);
            } else if (v[i] <= (f[i] - 1) * (f[i] - 1) && (f[i] > 1)) {
                f[i] = isqrt(v[i]);
            } else stop = 1;
            if (f[i] * f[i] != v[i]) mp[i] = v[i] - f[i] * f[i];
            else mp.erase(i);
            if (stop) break;
        }

        ll ans = f[n - 1];
        auto it = mp.end();
        if (it != mp.begin()) {
            --it;
            ans -= it->se < 0;
        }
        cout << ans << '\n';
    }
}

int main() {
    int t = 1;
    while (t--) solve();

    return 0;
}