//
// Created by DELLPC on 24-5-19.
//
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;

#define  endl '\n'

// 线段树
const int N = 1e6 + 10;

i64 stg[N << 2];

void modify(int q, int l, int r, int x, i64 k) {
    if (l == r) {
        stg[q] = k;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid) {
        modify(q << 1, l, mid, x, k);
    } else {
        modify(q << 1 | 1, mid + 1, r, x, k);
    }
    stg[q] = max(stg[q << 1], stg[q << 1 | 1]);
}

// 查询前缀最大值
i64 query(int q, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
        return stg[q];
    }
    if (l > r || l > R || r < L) {
        return 0;
    }
    int mid = (l + r) / 2;
    int ll = query(q << 1, l, mid, L, R);
    int rr = query(q << 1 | 1, mid + 1, r, L, R);
    return max(ll, rr);
}

// 线段数二分，找到最小的x，使得query(1, 1, n, 1, x) >= p
i64 binary_searchs(int q, int l, int r, int p) {
    if (l == r) {
        if (stg[q] >= p)
            return l;
        else return r + 1;

    }
    int mid = (l + r) / 2;
    if (stg[q << 1] >= p) {
        return binary_searchs(q << 1, l, mid, p);
    } else if (stg[q << 1 | 1] >= p) {
        return binary_searchs(q << 1 | 1, mid + 1, r, p);
    }
    return r + 1;
}

void solve() {
    set<int> ss;
    i64 n, p, q;
    cin >> n >> p >> q;
    map<i64, vector<i64>> mp;
    mp[p].emplace_back(1000000000);
    i64 sums = 0;
    i64 k = q * (q + 1) / 2;
    for (i64 i = 1; i <= n; i++) {
        i64 x, y;
        cin >> x >> y;
        mp[x].emplace_back(y);
    }
    sums += (q + 1) * (0 + p) * (p + 1) / 2;
    i64 preh = -1;
    for (auto &it: mp) {
        auto arr = it.second;
        sort(arr.begin(), arr.end(), greater<i64>());
        int nowh = it.first;
        if (nowh > p) {
            nowh = p;
        }
        sums += i64(nowh - preh) * k;

        for (auto &i: arr) {
            if (i >= q)continue;
            // 查询1 - i的最大值
            int x = query(1, 1, q, 1, i);
            int ans = x + 1;
            // 查询 1
            int r = binary_searchs(1, 1, q, ans);

            if (i + 1 < r) {

                modify(1, 1, q, i + 1, ans);
                ss.emplace(i + 1);
                k -= (r - i - 1);

            }
        }
        preh = nowh;
        if (nowh == p)break;
    }

    cout << sums << endl;
    for (auto i: ss) {
        modify(1, 1, q, i, 0);
//        cout << i << " ";
    }

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    memset(stg, 0, sizeof(stg));
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}



