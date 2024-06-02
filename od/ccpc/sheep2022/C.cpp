//
// Created by DELLPC on 24-3-31.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> e(n + 1);
    auto add = [&](int u, int v) {
        e[u].push_back(v);
        e[v].push_back(u);
    };
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >>v;
        add(u, v);
    }
    function<int(int,int,int)>dfs =[&] (int u, int fa, int dep){
        int now = dep;
        for(auto v : e[u]) {
            if(v == fa) {
                continue;
            }
            now = max(dfs(v, u, dep + 1), now);
        }
        return now;
    };

    long long ans = 0;
    for(auto u : e[1]) {
        ans += dfs( u, 1, 1);
    }
    cout << ans;
    return 0;
}
