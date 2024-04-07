#include<bits/stdc++.h>

using namespace std;
int nxt[500005], p[500005];
bool flag;
vector<int> to[500005];

void dfs(int l, int r, int x) {
    if (l > r)return;
    if (nxt[r] != r + 1) {
        flag = 1;
        return;
    }
    if (flag || l == r) {
        if (to[l].size())flag = 1;
        p[l] = x;
        return;
    }
    int las = l - 1;
    for (auto i: to[r + 1]) {
        if (i < l || (to[i].size() && to[i].front() < las)) {
            flag = 1;
            return;
        }
        p[i] = x, dfs(las + 1, i - 1, x - 1), x -= i - las, las = i;
    }
}

int main() {
    int _;
    scanf("%d", &_);
    while (_--) {
        int n;
        scanf("%d", &n);
        flag = 0;
        for (int i = 1; i <= n + 1; i++)to[i].clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &nxt[i]);
            if (nxt[i] == -1)nxt[i] = i + 1;
            to[nxt[i]].push_back(i);
        }
        dfs(1, n, n);
        if (flag)puts("-1");
        else {
            for (int i = 1; i <= n; i++)printf("%d ", p[i]);
            puts("");
        }
    }
    return 0;
}