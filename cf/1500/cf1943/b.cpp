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

void init() {
}


namespace strhash {
    using u64 = uint64_t;
    mt19937_64 rng(random_device{}());
    const int base = 135 + rng() % 114514;
    constexpr int p1 = 1'0000'0000'7, p2 = 1'0000'0000'9;
    constexpr unsigned msk32 = ~(0u);

    vector<u64> pw1{1}, pw2{1};

    class StringHash {
        vector<u64> h;
        int n;
    public:
        StringHash(const string &s) : n(s.length()) {
            int old_size = pw1.size();
            if (old_size < n + 1) {
                pw1.resize(2 * n + 1, 1), pw2.resize(2 * n + 1, 1);
                for (int i = old_size; i <= 2 * n; i++) {
                    pw1[i] = pw1[i - 1] * base % p1;
                    pw2[i] = pw2[i - 1] * base % p2;
                }
            }
            u64 now1 = 0, now2 = 0;
            h.resize(n + 1, 0);
            for (int i = n - 1; i >= 0; i--) {
                now1 = (now1 * base + s[i]) % p1;
                now2 = (now2 * base + s[i]) % p2;
                h[i] = (now1 << 32) | now2;
            }
        }

        u64 get(int l, int r) {
            int len = r - l;
            u64 l1 = h[l] >> 32, r1 = h[r] >> 32;
            u64 l2 = h[l] & msk32, r2 = h[r] & msk32;
            u64 res1 = (l1 - r1 * pw1[len] % p1 + p1) % p1;
            u64 res2 = (l2 - r2 * pw2[len] % p2 + p2) % p2;
            return (res1 << 32) | res2;
        }
    };

}

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = "#" + s + "#";
    string s2 = s;
    reverse(s2.begin(), s2.end());
    strhash::StringHash sh(s);
    strhash::StringHash sh2(s2);

    vector<int> pre1(n + 1), pre2(n + 1);
    for (int i = 1; i <= n; i++) {
        pre1[i] = (s[i] == s[i - 1]) ? pre1[i - 1] : i;
        pre2[i] = (i - 2 > 0 && s2[i] == s2[i - 2]) ? pre2[i - 2] : i;
    }
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        if (sh.get(l, r) != sh2.get(n - r + 1, n - l + 1)) {
            ans += r - l + 1;
        }

    }

}

signed main() {
    IOS;
    init();
    // debug(1);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
