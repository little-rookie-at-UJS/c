#include "bits/stdc++.h"
#include <windows.h>
#include <psapi.h> // 添加这行

using namespace std::chrono;
using namespace std;

using i64 = long long;
const int maxn = 1e6;

class stg {
private:
    struct node {
        int l, r;
        i64 val, sum;
        node() {
            l = r = val = sum = 0;
        }
    };

    int tot;
    vector<node> v;
    vector<int> ys;

#define rc(i) v[i].r
#define lc(i) v[i].l

    void pushup(int q) {
        v[q].val = v[rc(q)].val + v[lc(q)].val;
        v[q].sum = v[rc(q)].sum + v[lc(q)].sum;
    }

    int add(int j, int l, int r, int q) {
        int len = tot;
        tot++;
        if (tot == v.size()) {
            v.resize(tot * 2);
        }
        v[len] = v[j];
        if (l == r) {
            v[len].val++;
            v[len].sum += l;
            return len;
        }
        int mid = (l + r) / 2;
        if (mid >= q) {
            v[len].l = add(lc(len), l, mid, q);
        } else {
            v[len].r = add(rc(len), mid + 1, r, q);
        }
        pushup(len);
        return len;
    }


    i64 query(int i, int j, int l, int r, int k) {
        if (l == r) {
            return l * k;
        }
        int mid = (l + r) / 2;
        i64 ans = 0;
        if (rc(i)) {
            int nums = v[rc(i)].val - v[rc(j)].val;
            if (nums >= k) {
                return query(rc(i), rc(j), mid + 1, r, k);
            }
            ans += v[rc(i)].sum - v[rc(j)].sum;
            k -= nums;
        }
        return ans + query(lc(i), lc(j), l, mid, k);
    };

public:

    stg() {
        v.resize(10);
        ys.resize(10);
        tot = 1;
    }

    void copy(int x, int y) {
        ys[x] = ys[y];
    }


    void add(int i, int j, int q) {
        if (i == ys.size()) {
            ys.resize(2 * ys.size());
        }
        ys[i] = add(ys[j], 1, maxn, q);
    }

    i64 query(int r, int l, int k) {
        r = ys[r];
        l = ys[l];

        return query(r, l, 1, maxn, k);
    }


};

// 1
// 5
// 1 2 3 4 5
// 3
// 1 3 2
// 1 5 5
// 3 3 1
void solve() {
    int n;
    cin >> n;
    stg s;
    vector<i64> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + i * i;
    }

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.add(i, i - 1, a[i]);
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        i64 ans = s.query(r, l - 1, k);
        cout << ans + pre[r - l + 1] << endl;

    }

}


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    auto st = high_resolution_clock::now();


    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    auto ed = high_resolution_clock::now();
    auto ttime = duration_cast<milliseconds>(ed - st).count();
    cerr << "Main Time used: " << ttime << " ms" << endl;
    PROCESS_MEMORY_COUNTERS_EX pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *) &pmc, sizeof(pmc));

    SIZE_T virtualMemUsedByMe = pmc.PrivateUsage;
    cerr << "Main Virtual memory used by the process: " << virtualMemUsedByMe / (1024 * 1024) << " MB" << endl;

    return 0;

}

