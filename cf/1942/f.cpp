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

ll isqrt(ll v, ll g = 1e18) {
    while (true) {
        if (g * g <= v && (g + 1) * (g + 1) > v)
            return g;
        g = (g + v / g) / 2;
    }
}
void init() {
}


void solve() {
    int n, q;
    cin >> n >> q;
    map<int, int> mp;
    vector<int> arr(n + 1), f(n + 1), ans(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        f[i] = arr[i] + ans[i - 1];
        ans[i] = sqrt(f[i]);
        if (ans[i] * ans[i] != f[i]) {
            mp[i] = (f[i] - ans[i] * ans[i]);
        }
    }
    for (int i = 1; i <= q; i++) {
        int len, value;
        cin >> len >> value;
        arr[len] = value;
        while (len <= n) {
            bool flag = false;
            f[len] = ans[len - 1] + arr[len];
            int k = isqrt(f[len]);
//            assert(f[len] >= 0);
            if (k != ans[len]) {
                if (f[len] == 0 && ans[len] == 1) {
                    flag = true;
                } else {
                    ans[len] = k;
                }
            } else flag = true;
            if (ans[len] * ans[len] != f[len]) {
                mp[len] = (f[len] - ans[len] * ans[len]);
            } else mp.erase(len);
            if (flag)break;
            len++;
        }
        auto a = ans[n];
        if (!mp.empty()) {
            auto it = mp.end();
            it--;
            if (it->second < 0) {
                a--;
            }
        }
        cout << a << endl;
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
// 两种情况
// 1 所有的数都>=1
// 很容易发现这种数影响的范围很小 可能最多存在10格
// 2 存在<0
//    全部为0
//    已知sqrt最小为 1、0
//    我们只需要注意最后能不能变成0
//    我们记录一个东西为 le 为当前的数，取sqrt后余几
//    特别的我们记录 如果一个数如果原来是1 变成0的话 计数为-1
//    在每次修改过后我们之间查询最后的不为0的余数
//    正的话，即使后面-1 对这个的数也没有影响
//    负的话，就只有整个数列是全0的情况 ,把所以结果输出为 0；
//    这样我们只需要维护很少的区间就可以
