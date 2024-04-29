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


namespace modint {

    using i64 = int64_t;

    template<int P>
    struct Mint {
    private:
        constexpr Mint power(Mint x, i64 p) const {
            Mint res = 1;
            while (p > 0) {
                if (p & 1) {
                    res *= x;
                }
                x *= x;
                p >>= 1;
            }
            return res;
        }

        constexpr int norm(int x) const {
            if (x < 0) {
                x += getMod();
            }
            if (x >= getMod()) {
                x -= getMod();
            }
            return x;
        }

    public:
        int x;

        constexpr Mint() : x{} {}

        constexpr Mint(i64 x) : x{norm(x % getMod())} {}

        static int mod;

        constexpr static int getMod() {
            if (P > 0) {
                return P;
            } else {
                return mod;
            }
        }

        constexpr static void setMod(int Mod_) { mod = Mod_; }

        constexpr int val() const { return x; }

        explicit constexpr operator int() const { return x; }

        constexpr Mint operator-() const {
            Mint res;
            res.x = norm(getMod() - x);
            return res;
        }

        constexpr Mint inv() const {
            assert(x != 0);
            return power(*this, getMod() - 2);
        }

        constexpr Mint pow(i64 r) const { return power(*this, r); }

        constexpr Mint &operator*=(Mint rhs) &{
            x = 1LL * x * rhs.x % getMod();
            return *this;
        }

        constexpr Mint &operator+=(Mint rhs) &{
            x = norm(x + rhs.x);
            return *this;
        }

        constexpr Mint &operator-=(Mint rhs) &{
            x = norm(x - rhs.x);
            return *this;
        }

        constexpr Mint &operator/=(Mint rhs) &{ return *this *= rhs.inv(); }

        friend constexpr Mint operator*(Mint lhs, Mint rhs) {
            Mint res = lhs;
            res *= rhs;
            return res;
        }

        friend constexpr Mint operator+(Mint lhs, Mint rhs) {
            Mint res = lhs;
            res += rhs;
            return res;
        }

        friend constexpr Mint operator-(Mint lhs, Mint rhs) {
            Mint res = lhs;
            res -= rhs;
            return res;
        }

        friend constexpr Mint operator/(Mint lhs, Mint rhs) {
            Mint res = lhs;
            res /= rhs;
            return res;
        }

        friend constexpr std::istream &operator>>(std::istream &is, Mint &a) {
            i64 v;
            is >> v;
            a = Mint(v);
            return is;
        }

        friend constexpr std::ostream &operator<<(std::ostream &os, const Mint &a) {
            return os << a.val();
        }

        friend constexpr bool operator==(Mint lhs, Mint rhs) {
            return lhs.val() == rhs.val();
        }

        friend constexpr bool operator!=(Mint lhs, Mint rhs) {
            return lhs.val() != rhs.val();
        }


    };

    template<int P> int Mint<P>::mod{0};

    template<typename Z>
    struct Comb {
        std::vector<Z> fact, inv_fact;

        Comb(int n) {
            fact.resize(n + 1, Z(1));
            inv_fact.resize(n + 1, Z(1));
            for (int i = 1; i <= n; i++) {
                fact[i] = fact[i - 1] * i;
            }
            inv_fact[n] = Z{1} / fact[n];
            for (int i = n - 1; i >= 0; i--) {
                inv_fact[i] = inv_fact[i + 1] * (i + 1);
            }
        }

        Z get(int n, int m) const {
            if (n < m || m < 0)
                return 0;
            return fact[n] * inv_fact[m] * inv_fact[n - m];
        }
    };


} // namespace modint

// check the modulus!!!
constexpr int MOD = 1e9 + 7;

using Z = modint::Mint<MOD>;


int qpow(int a, int b, int m) {

    int ans = 1;
    while (b) {
        if (b & 1) {
            ans *= a;
            ans %= m;
        }
        a *= a;
        a %= m;
        b /= 2;
    }
    return ans;
}
int inv()

vector<int> Prime(int n) {
    vector<int> p;
    vector<int> vis(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            p.emplace_back(i);
            for (int j = i + i; i <= n; i += i) {
                vis[j] = 1;
            }
        }
    }
    return p;
}

int maxn = 3e6;
vector<Z> ans;

void init() {
    ans.resize(maxn);
    vector<int> p = Prime(maxn);
    for (int i = 1; i < maxn; i++) {

    }
}

//using C = modint::Comb<Z>;
//C comb(3e5 + 7);

void solve() {

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
