//
// Created by DELLPC on 24-5-19.
//
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;

#define  endl '\n'

//2 1
//1 0
//1 2
//1
class Graph {
private:
    vector<vector<int>> adj;
    vector<int> dfn;
    vector<int> top;
    vector<int> fa;
    vector<int> dep;
    vector<int> siz;
    vector<int> son;
    vector<int> mir;
    vector<int> col;
    vector<int> sons;
    int tot = 0;
    int root;
    int sizs;
    int n;
    int n2 = 0;
    // 线段树
    vector<int> stg1;
    vector<int> stg2;

    /*
     *  需要功能 单点修改 区间查询
     * */

    void pushup(vector<int> &_stg, int q) {
        _stg[q] = max(_stg[q << 1], _stg[q << 1 | 1]);
    }

    void modify(vector<int> &_stg, int q, int l, int r, int x, int k) {
        if (l == r) {
            _stg[q] = k;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            modify(_stg, q << 1, l, mid, x, k);
        } else {
            modify(_stg, q << 1, mid + 1, r, x, k);
        }
        pushup(_stg, q);
    }

    int query(vector<int> &_stg, int q, int l, int r, int L, int R) {
        int mid = (l + r) / 2;
        if (L <= l && r <= R) {
            if (!_stg[q])return 0;
            if (l == r) return l;
            if (_stg[q << 1 | 1]) {
                return query(_stg, q << 1, l, mid, L, R);
            } else {
                return query(_stg, q << 1 | 1, mid + 1, r, L, R);
            }
        }
        if (r < L || l > R) {
            return 0;
        }
        int ans = 0;
        if (L <= mid) {
            ans = max(ans, query(_stg, q << 1, l, mid, L, R));
        }
        if (mid < R) {
            ans = max(ans, query(_stg, q << 1 | 1, mid + 1, r, L, R));
        }
        return ans;
    }

    void modify(vector<int> &_stg, int x, int k) {
        modify(_stg, 1, 1, n, x, k);
    }

    int query(vector<int> &_stg, int l, int r) {
        return query(_stg, 1, 1, n, l, r);
    }

public:
    void dfs1(int u, int v) {
        for (auto i: adj[v]) {
            if (u == i) {
                continue;
            }
            fa[i] = v;
            dep[i] = dep[v] + 1;
            dfs1(v, i);
            siz[v] += siz[i];
            if (siz[i] > siz[son[v]]) {
                son[v] = i;
            }
        }
    }

    void dfs2(int t, int v) {
        top[v] = t;
        dfn[v] = ++tot;
        mir[tot] = t;
        if (!son[v])return;
        dfs2(t, v);
        for (auto i: adj[v]) {
            if (i == son[v] || i == fa[v])continue;
            dfs2(i, i);
        }

    }

    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            u = fa[top[u]];
//            assert(u);
        }
        return dep[u] < dep[v] ? u : v;
    }

    Graph(int n) : adj(n + 1), dfn(n + 1), top(n + 1), fa(n + 1), dep(n + 1),
                   siz(n + 1, 1), son(n + 1),
                   mir(n + 1), col(n + 1), stg1(n * 4 + 1), stg2(n * 4 + 1), n(n), sons(n + 1) {
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        dfs1(0, 1);
        dfs2(1, 1);
    }

//  vector<int> col;
//    vector<int> sons;
//    int tot = 0;
//    int root;
//    int sizs;
//    int n;
//    int n2 = 0;
//    // 线段树
//    vector<int> stg1;
//    vector<int> stg2;
    int change(int x) {
        if (sizs == 0) {
            x = root;
            col[x] = 1;
            modify(stg1, x, 1);
        } else {

        }
    };


};


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;

}

