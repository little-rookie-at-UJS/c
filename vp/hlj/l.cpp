//
// Created by DELLPC on 24-5-19.
//
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;

#define  endl '\n'


class Graph {
private:
    vector<int> a;
    vector<int> b;
    vector<vector<int>> _adj;
    int n, m;
    vector<int> scc;
    vector<vector<int>> sccnode;
    vector<vector<int>> sccadj;
    vector<int> dfn;
    vector<int> low;
    vector<int> du;
    stack<int> s;
    int tot = 1;
    int sccs = 0;
public:
    void tarjan(int x) {
        scc[x] = -1;
        dfn[x] = low[x] = tot++;
        s.emplace(x);
        for (auto i: _adj[x]) {
            if (!dfn[i]) {
                tarjan(i);
                low[x] = min(low[x], low[i]);
            } else if (scc[i] == -1) {
                low[x] = min(low[x], dfn[i]);
            }
        }
        if (dfn[x] == low[x]) {
            sccs++;
            while (s.top() != x) {
                scc[s.top()] = sccs;
                sccnode[sccs].emplace_back(s.top());
                s.pop();
            }
            scc[s.top()] = sccs;
            sccnode[sccs].emplace_back(s.top());
            s.pop();
        }
    }

    Graph(int n, int m) : n(n), m(m), a(n + 1), b(n + 1),
                          _adj(n + 1), scc(n + 1), sccnode(n + 1),
                          sccadj(n + 1), dfn(n + 1, 0), low(n + 1), du(n + 1) {

        {
            for (int i = 1; i <= n; i++) {
                cin >> a[i];
            }
            for (int i = 1; i <= n; i++) {
                cin >> b[i];
            }
            for (int i = 1; i <= m; i++) {
                int u, v;
                cin >> u >> v;
                _adj[u].emplace_back(v);
            }
            for (int i = 1; i <= n; i++) {
                if (!dfn[i]) {
                    tarjan(i);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (auto j: _adj[i]) {
                if (scc[i] == scc[j]) continue;
                sccadj[scc[i]].emplace_back(scc[j]);
                du[scc[j]]++;
            }
        }

        i64 l = 0, r = 1e9 + 7;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (l >= 1e9) l = 1e9;
        cout << l << endl;
    }

    bool check(int x) {
        if (x == 0) return true;
        vector<int> md = du;
        stack<int> st;
        for (int i = 1; i <= n; i++) {
            if (md[i] == 0) {
                st.emplace(i);
            }
        }
        vector<i64> val(n + 1, 0);
        while (!st.empty()) {
            auto xa = st.top();
            st.pop();
            for (auto i: sccnode[xa]) {
                if (a[i] <= x)val[xa] += a[i];
            }
            for (auto i: sccnode[xa]) {
//                if (a[i] <= x)val[scc[i]] += a[i];
                if (val[xa] > b[i]) return false;
            }
            for (auto i: sccadj[xa]) {
                val[i] = max(val[i], val[xa]);
                md[i]--;
                if (md[i] == 0)st.emplace(i);
            }
        }
        return true;
    }
};


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    Graph g(n, m);
}

