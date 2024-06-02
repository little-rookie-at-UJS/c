#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void pushup(vector<int> &stg, int q) {
    stg[q] = max(stg[q << 1], stg[q << 1 | 1]);
}

void add(vector<int> &stg, int q, int l, int r, int to, int f, int len) {
    if (l == r) {
        stg[q] = f;
        return;
    }
    int mid = (l + r) / 2;
    if (mid >= to)
        add(stg, q << 1, l, mid, to, f, len);
    else
        add(stg, q << 1 | 1, mid + 1, r, to, f, len);
    pushup(stg, q);

}

int query(vector<int> &stg, int q, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
        return stg[q];
    }
    if (r < L || R < l) {
        return 0;
    }
    int mins = 0;
    int mid = (l + r) / 2;
    if (mid >= L) {
        auto ans = query(stg, q << 1, l, mid, L, R);
        mins = max(mins, ans);
    }
    if (mid < R) {
        auto ans = query(stg, q << 1 | 1, mid + 1, r, L, R);
        mins = max(mins, ans);
    }
    return mins;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<i64, i64>> len(n + 1, {
            n + 1, 0
    });
    for (i64 i = 1; i <= n; i++) {
        int x;
        cin >> x;
        len[x].second = i;
        len[x].first = min(len[x].first, i);
    }
    vector<pair<pair<int, int>, int>> arr;
    for (i64 i = 1; i <= n; i++) {
        if (len[i].first != n + 1) arr.emplace_back(len[i], i);
    }
    sort(arr.begin(), arr.end());
    vector<pair<int, int>> merge;
    vector<int> bel(n + 1, -1);
    pair<int, int> me = arr[0].first;
    for (auto [pa, len]: arr) {
        if (pa.first <= me.second) {
            me.second = max(me.second, pa.second);
            bel[len] = merge.size();
        } else {
            merge.emplace_back(me);
            me = pa;
            bel[len] = merge.size();
        }
    }
    merge.emplace_back(me);
    int k = 0;

    vector<int> stg(4 * n);
    vector<int> pre(n + 1);
    int maxss = 0;
    for (int i = 1; i <= n; i++) {
        if (bel[i] == -1) {
            k++;
        } else {
            auto be = bel[i];
            auto line = merge[be];
            int f = query(stg, 1, 1, n, 1, line.first - 1);
            auto maxs = f;
            maxss = max(maxs + 1, maxss);
            add(stg, 1, 1, n, line.second, maxs + 1, i);
        }
    }
//    cerr << k << endl;
    cout << n - maxss - k << endl;


}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }

}

//1 2 3 2
//5
//4 3 4 5 6
//3 1 3 1 1