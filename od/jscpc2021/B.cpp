//
// Created by DELLPC on 24-4-28.
//
#include<bits/stdc++.h>

#define int long long
using namespace std;

#define irep(i, l, r) for(int i = l; i <= r; ++ i)
#define drep(i, r, l) for(int i = r; i >= l; -- i)
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define ll long long
#define LD double
const int mod = 1000000000 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<array<int, 2>>> adj(n);
    irep(i, 0, m - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int E, TLE;
    cin >> E >> TLE;
    vector<vector<vector<int>>> time_list(k, vector<vector<int>>(n));
    // (people, room) -> time list
    irep(i, 0, E - 1) {
        int p, x, t;
        cin >> p >> x >> t;
        time_list[p - 1][x - 1].push_back(t);
    }
    irep(i, 0, k - 1) {
        irep(j, 0, n - 1) {
            time_list[i][j].push_back(mod);
            ranges::sort(time_list[i][j]);
        }
    }

    int st1, st2;
    cin >> st1 >> st2;
    st1--, st2--;
    vector<vector<int>> F(n, vector<int>(1 << k, mod)), G(n, vector<int>(1 << k, mod));
    vector<int> dis(n);

    auto dijkstra = [&](int s) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        // dis, idx
        vector<int> vis(n);
        irep(i, 0, n - 1)dis[i] = TLE + 1;
        q.push({0, s});
        dis[s] = 0;
        while (q.size()) {
            auto [D, x] = q.top();
            q.pop();
            if (vis[x])continue;
            vis[x] = 1;
            for (auto [y, w]: adj[x]) {
                if (dis[y] > dis[x] + w) {
                    dis[y] = dis[x] + w;
                    q.push({dis[y], y});
                }
            }
        }
        return;
    };
    F[st1][0] = 0, G[st2][0] = 0;
    irep(i, 0, (1 << k) - 1) {
        irep(x, 0, n - 1) {
            if (F[x][i] > TLE)continue;
            dijkstra(x);
            vector<vector<int>> arrival(k, vector<int>(n, TLE + 10));

            irep(pe, 0, k - 1) {
                if((1 << pe) & i)continue;
                irep(r, 0, n - 1) {
                    arrival[pe][r] = min(arrival[pe][r], *lower_bound(time_list[pe][r].begin(), time_list[pe][r].end(),dis[r] + F[x][i]));
                }
            }
            irep(j, 0, k - 1) {
                if (i & (1 << j))continue;
                irep(r, 0, n - 1) {
                    F[r][i ^ (1 << j)] = min(F[r][i ^ (1 << j)], arrival[j][r]);
                }
            }
        }
    }
//    dijkstra(0);
    irep(i, 0, (1 << k) - 1) {
        irep(x, 0, n - 1) {
            if (G[x][i] > TLE)continue;
            dijkstra(x);
            vector<vector<int>> arrival(k, vector<int>(n, TLE + 10));
            irep(pe, 0, k - 1) {
                if((1 << pe) & i)continue;
                irep(r, 0, n - 1) {
                    arrival[pe][r] = min(arrival[pe][r], *lower_bound(time_list[pe][r].begin(), time_list[pe][r].end(),dis[r] + G[x][i]));
                }
            }
            irep(j, 0, k - 1) {
                if (i & (1 << j))continue;
                irep(r, 0, n - 1) {
                    G[r][i ^ (1 << j)] = min(G[r][i | (1 << j)], arrival[j][r]);
                }
            }
        }
    }
    int ans = TLE + 10;

    vector<int>conf(1 << k), cong(1 << k);
    irep(i, 0, (1 << k) - 1){
        conf[i] = F[0][i], cong[i] = G[0][i];
        irep(j, 0, n - 1){
            conf[i] = min(conf[i], F[j][i]);
            cong[i] = min(cong[i], G[j][i]);
        }
    }
    irep(i, 0, (1 << k) - 1) {
        ans = min(ans, max(conf[i], cong[(1 << k) - 1 - i]));
    }
    if (ans > TLE) {
        cout << "-1\n";
    } else cout << ans << '\n';
}

signed main() {
    IOS;
    int T = 0;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}