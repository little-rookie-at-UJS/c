#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int *> pipi;
const int N = 2510;
int n, m, px[N], py[N];
int cnt[N * N], num[N * N];
bool vis[N][4];
vector<pipi> g[N];

inline int GetDir(char c) {
    if (c == 'N') return 0;
    if (c == 'E') return 1;
    if (c == 'S') return 2;
    if (c == 'W') return 3;
    exit(1);
}

inline void Delete(int x, int y, int *pt) {
    auto it = find(g[x].begin(), g[x].end(), pipi(y, pt));
    if (it != g[x].end()) g[x].erase(it);
    it = find(g[y].begin(), g[y].end(), pipi(x, pt));
    if (it != g[y].end()) g[y].erase(it);
}

inline int GetDir(int x, int y) {
    if (px[x] == px[y]) return py[y] > py[x] ? 0 : 2;
    return px[y] > px[x] ? 1 : 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> px[i] >> py[i];
    }
    for (int i = 1, x, y; i <= m; ++i) {
        cin >> x >> y >> cnt[i];
        g[x].push_back({y, cnt + i});
        g[y].push_back({x, cnt + i});
    }
    for (int i = 1; i <= n; ++i) {
        sort(g[i].begin(), g[i].end(), [&](pipi u, pipi v) {
            return GetDir(i, u.first) < GetDir(i, v.first);
        });
    }
    int cur;
    string dir;
    cin >> cur >> dir;
    int d = GetDir(dir[0]), la = -1;
    while (1) {
        bool has_delete = 0;
        for (int i = 1; i <= n; ++i)
            for (int d = 0; d < 4; ++d)
                vis[i][d] = 0;
        vector<tuple<int, int, int *>> pass;
        while (!vis[cur][d]) {
            vis[cur][d] = 1;
            for (auto [nx, pt]: g[cur])
                if (GetDir(cur, nx) == d) {
                    // cerr << cur << ' ' << nx << endl;
                    if (g[nx].size() == 1) {
                        cout << px[nx] << ' ' << py[nx] << endl;
                        return 0;
                    }
                    auto it = find(g[nx].begin(), g[nx].end(), pipi(cur, pt));
                    if (++it == g[nx].end()) it = g[nx].begin();
                    if (g[nx].size() == 4) {
                        if (++it == g[nx].end()) it = g[nx].begin();
                    }
                    d = GetDir(nx, it->first);
                    pass.push_back({cur, nx, pt});
                    la = cur;
                    cur = nx;
                    --*pt;
                    if (*pt == 0) {
                        has_delete = 1;
                        Delete(la, cur, pt);
                        break;
                    }
                    break;
                }
            if (has_delete) break;
        }
        if (has_delete) continue;
        int mn = 1e9;
        for (auto [x, y, pt]: pass) {
            ++num[pt - cnt];
            mn = min(mn, *pt / num[pt - cnt]);
        }
        for (auto [x, y, pt]: pass) {
            num[pt - cnt] = 0;
        }
        // cerr << mn << endl;
        for (auto [x, y, pt]: pass) {
            *pt -= mn;
            if (!*pt) Delete(x, y, pt);
        }
        if (g[cur].size() == 0 || (g[cur].size() == 1 && g[cur].front().first == la)) {
            cout << px[cur] << ' ' << py[cur] << endl;
            return 0;
        }
        while (1) {
            int flag = 0;
            for (auto [y, pt]: g[cur]) if (GetDir(cur, y) == d) flag = 1;
            if (!flag) d = (d + 1) & 3; else break;
        }
    }
}