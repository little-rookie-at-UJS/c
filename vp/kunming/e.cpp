#include "bits/stdc++.h"

using namespace std;

using i64 = unsigned long long;
using i32 = unsigned int;

#define  endl '\n'

void build(vector<i64> &stg, int q, int l, int r, vector<i64> &v) {
    if (l == r) {
        stg[q] = v[l];
        return;
    }
    int mid = (l + r) / 2;
    build(stg, q << 1, l, mid, v);
    build(stg, q << 1 | 1, mid + 1, r, v);
    stg[q] = __gcd(stg[q << 1], stg[q << 1 | 1]);
}

i64 querys(vector<i64> &stg, int q, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
        return stg[q];
    }
    if (l > r || l > R || r < L) {
        return 0;
    }
    int mid = (l + r) / 2;
    i64 ll = querys(stg, q << 1, l, mid, L, R);
    i64 rr = querys(stg, q << 1 | 1, mid + 1, r, L, R);
    i64 ans = __gcd(ll,
                    rr);
    return ans;
}

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64> stg1(n * 4);
    vector<i64> stg2(n * 4);
    vector<i64> a(n + 1);
    vector<i64> b(n + 1);
    set<int> query;
    i64 pregcd1 = 0;
    i64 pregcd2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] + k;
        i64 gcd1 = __gcd(a[i], pregcd1);
        if (gcd1 != pregcd1) {
//            query.emplace(i - 2);
//            query.emplace(i - 1);
            query.emplace(i);
//            query.emplace(i + 1);
//            query.emplace(i + 2);
        }
        
    }
    query.erase(0);
    query.erase(n + 1);
    build(stg1, 1, 1, n, a);
    build(stg2, 1, 1, n, b);
    i64 maxx = stg1[1];
    
    
    for (int i = n; i; i--) {
        for (auto j: query) {
            
            if (j <= 0) continue;
            if (j > i) break;
            
            i64 pp = querys(stg1, 1, 1, n, 1, j - 1);
            if (j == 1) pp = 0;
            i64 m = querys(stg2, 1, 1, n, j, i);
            i64 bb = querys(stg1, 1, 1, n, i + 1, n);
            if (i == n) bb = 0;
            i64 gg = __gcd(__gcd(pp, m), bb);
            maxx = max(maxx, gg);
        }
    }
    cout << maxx << endl;
    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}