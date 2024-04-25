#include "bits/stdc++.h"

using namespace std;

#ifndef ONLINE_JUDGE

#include "test.h"

#else
#define debug(...) 42
#define debug_assert(...) 42
#endif


#define IOS ios::sync_with_stdio(0),cin.tie(0)


namespace test {
    using ll = long long;
    using ull = unsigned long long;

#define endl '\n'
#define int ll
    const int inf = 1e18;
    const int mod = 1e9 + 7;
    template<typename T, typename Compare =less<>>
    using pqinit = priority_queue<T, vector<T>, Compare>;

    // 全局变量

    void init() {

    }

    class solution {
    private:
        struct node {
            int s, h;

            node() {
                s = h = 0;
            }

            bool operator<(const node &n1) {
                return s * n1.h < n1.s * h;
            }

            bool operator>(const node &n1) {
                return s * n1.h > n1.s * h;
            }


            friend ostream &operator<<(ostream &os, const node &n1) {
                os << n1.s << " " << n1.h;
                return os;
            }
        };

    public:
        void run() {
            int n;
            cin >> n;
            vector<node> v(n);
            int ans = 0;
            for (int i = 0; i < n; i++) {
                string s;
                cin >> s;
                for (auto j: s) {
                    if (j == 's') {
                        v[i].s++;
                    } else if (j == 'h') {
                        ans += v[i].s;
                        v[i].h++;
                    }
                }
            }
            sort(v.begin(), v.end(), greater<>());
            int pre = 0;
            int sums2 = 0;
            for (int i = 0; i < n; i++) {
                sums2 += pre * v[i].h;
                pre += v[i].s;
            }
            cout << sums2 + ans << endl;

        }
    };

#undef int
#undef endl
};// namespace test


signed main() {
    IOS;
    test::init();
    // debug(1);
    int t = 1;
//    cin >> t;
    while (t--) {
        test::solution s;
        s.run();
    }
}
