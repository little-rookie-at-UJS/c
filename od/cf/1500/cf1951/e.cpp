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

}  // namespace strhash
void init() {
}


void solve() {
    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    strhash::StringHash sh(s), th(t);
    int n = s.length();
    auto check = [&](int l, int r) {
        return sh.get(l, r) != th.get(n - r, n - l);
    };
    if (check(0, n)) {
        cout << "Yes\n";
        cout << 1 << "\n" << s << "\n";
        return;
    }
    for (int part = 1; part < n; part++) {
        if (check(0, part) && check(part, n)) {
            cout << "Yes\n";
            cout << 2 << "\n"
                 << s.substr(0, part) << " " << s.substr(part) << "\n";
            return;
        }
    }
    cout << "No\n";
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
