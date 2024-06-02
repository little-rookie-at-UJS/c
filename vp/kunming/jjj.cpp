//
// Created by DELLPC on 24-5-19.
//
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;

#define  endl '\n'

struct cmp {
    int pos;
    int left;

    bool operator<(const cmp &a) const {
        if (pos == a.pos) {
            return left > a.left;
        }
        return pos < a.pos;
    }

    cmp(int pos, int left) : pos(pos), left(left) {}

};

// 线段树

class STG {
private:


    vector<int> stg;
    vector<int> ys;
    vector<int> v;
    int n;


    void pushup(int q) {
        stg[q] = max(stg[q << 1], stg[q << 1 | 1]);
    }

    void build(int q, int l, int r) {
        if (l == r) {
            stg[q] = v[l];
            return;
        }
        int mid = (l + r) / 2;
        build(q << 1, l, mid);
        build(q << 1 | 1, mid + 1, r);
        pushup(q);
    }

    cmp query(int q, int l, int r, int L, int R, int K) {
        int mid = (l + r) / 2;
        if (L <= l && r <= R) {
            if (stg[q] < K) return cmp(1e9, -1);
            if (l == r) {
                return {l, stg[q]};
            }
            if (stg[q << 1] >= K) return query(q << 1, l, mid, L, R, K);
            else return query(q << 1 | 1, mid + 1, r, L, R, K);
        }
        if (l > R || r < L) return cmp(1e9, -1);
        cmp ans = cmp(1e9, -1);

        if (L <= mid) {
            ans = min(query(q << 1, l, mid, L, R, K), ans);
        }
        if (R > mid) {
            ans = min(query(q << 1 | 1, mid + 1, r, L, R, K), ans);
        }
        return ans;
    }

public:
    STG() {
        n = 0;
        ys.emplace_back(0);
        v.emplace_back(0);
    }

    void emplace(int x, int va) {
//        cerr << x << " " << va << endl;
        ys.push_back(x);
        v.push_back(va);
        n++;
    }

    void build() {
        stg.resize(n * 4);
        build(1, 1, n);
    }

    auto query(int x, int k) {
        auto r = std::lower_bound(ys.begin(), ys.end(), x);
        if (r == ys.end())return cmp(1e9, -1);
        auto ans = query(1, 1, n, r - ys.begin(), n, k);
        if (ans.pos != 1e9)
            ans.pos = ys[ans.pos];
        return ans;
    }


};

struct node {
    // 位置
    int pos;
    int left;
    int goal;

    bool operator<(const node &a) const {
        if (pos == a.pos) {
            return left > a.left;
        }
        return pos < a.pos;
    }

    bool operator>(const node &a) const {
        if (pos == a.pos) {
            return left < a.left;
        }
        return pos > a.pos;
    }

};


void solve() {
    int n, m, k;
    cin >> n >> m >> k;
//    cerr << n << " " << m << " " << k << endl;
    vector<vector<tuple<int, int, int >>> adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, kk, a;
        cin >> u >> v >> kk >> a;
        adj[u].emplace_back(v, kk, a);
        adj[v].emplace_back(u, kk, a);
    }
    map<int, STG *> mp;
    vector<int> col(k + 1);
    for (int i = 1; i <= k; i++) {
        int c, l;
        cin >> c >> l;
        col[i] = c;
        if (!mp.count(c)) {
            mp[c] = new STG();
        }
//        cerr << c << " " << l << endl;
        mp[c]->emplace(i, l);
    }

    for (auto &i: mp) {
        i.second->build();
    }
    priority_queue<node, vector<node>, greater<>> pq;
    pq.emplace(0, 0, 1);

    vector<cmp> dis(n + 1, cmp(1e9, 1e9));
    vector<int> vis(n + 1);


    dis[1] = {0, 0};
    while (!pq.empty()) {
        auto [pos, left, now] = pq.top();
//        cerr << pos << " " << left << " " << now << endl;
        pq.pop();
        if (vis[now])continue;
        vis[now] = 1;
        for (auto [to, colorned, cost]: adj[now]) {

            if (colorned == col[pos] && cost <= left) {
                cmp ans = {dis[now].pos, left - cost};
                if (ans < dis[to]) {
//                    cerr << "update " << now << " " << to << " " << ans.pos << " " << ans.left << endl;
                    dis[to] = ans;
                    pq.emplace(pos, left - cost, to);
                }
            } else {
                if (mp.count(colorned)) {
                    auto ans = mp[colorned]->query(pos + 1, cost);
                    if (ans.pos != 1e9) {
                        ans.left -= cost;
                        if (ans < dis[to]) {

                            dis[to] = ans;
                            pq.emplace(ans.pos, ans.left, to);
                        }
                    }

                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i])cout << 1;
        else cout << 0;
    }
    cout << endl;


}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}


//1
//9 27 3
//9 4 2 8
//1 2 2 1
//4 3 2 8
//6 4 3 10
//1 7 3 9
//9 5 3 1
//5 3 1 4
//6 9 2 3
//6 6 3 2
//5 3 2 2
//1 4 1 1
//3 5 1 9
//6 1 2 6
//5 5 3 2
//7 7 2 5
//9 5 2 3
//8 6 3 2
//6 9 3 8
//1 2 3 10
//2 9 2 8
//2 7 1 7
//2 8 1 10
//7 4 1 4
//5 3 3 5
//9 3 1 4
//4 2 1 5
//6 9 1 8
//1 10
//2 8
//3 3

//1  - > 2 4
// 2  2  6 3 3
// 4  1 9 2 8 3 3

// 4 -> 3
// 3 3 3