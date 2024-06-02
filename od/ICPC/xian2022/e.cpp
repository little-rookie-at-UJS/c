#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int ll

#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define per(i, a, b) for(int i = (a); i >= (b); --i)

vector<string> mp;
#define PRINT(x) cout<<#x<<':';print(x);

void print(map<int, set<int>> mp) {
    cout << '{';
    for (auto [x, y]: mp) {
        cout << x << ':';
        cout << '{';
        for (auto i: y) {
            cout << i << ",";
        }
        cout << '}';
    }
    cout << '}' << endl;
}

void print(map<int, set<pair<int, int>>> mp) {
    cout << '{';
    for (auto [x, y]: mp) {
        cout << x << ':';
        cout << '{';
        for (auto [i, j]: y) {
            cout << '{' << i << "," << j << "},";
        }
        cout << '}';
    }
    cout << '}' << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, c, d;
    cin >> n >> m >> c >> d;
    unordered_map<int, unordered_set<int>> row, col;
    unordered_map<int, set<pair<int, int>>> prow, pcol, pboth;
    std::unordered_set<int>::size_type maxk = 0;
    rep(i, 0, n - 1) {
        string s;
        cin >> s;
        mp.emplace_back(s);
    }
    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) {
            if (mp[i][j] == '.') {
                row[i].emplace(j);
            }
        }
        maxk = max(maxk, row[i].size());
        rep(j, 0, m - 1) {
            if (mp[i][j] == '.') {
                prow[row[i].size()].emplace(i, j);
            }
        }
    }
    rep(j, 0, m - 1) {
        rep(i, 0, n - 1) {
            if (mp[i][j] == '.') {
                col[j].emplace(i);
            }
        }
        maxk = max(maxk, col[j].size());
        rep(i, 0, n - 1) {
            if (mp[i][j] == '.') {
                pcol[col[j].size()].emplace(i, j);
                if (prow[col[j].size()].contains({i, j})) {
                    pboth[col[j].size()].emplace(i, j);
                }
            }
        }
    }

    int ans = c * maxk;
    int z = 0;
    per(k, maxk, 1) {
        auto tpboth = pboth[k];
        for (auto &&[x, y]: tpboth) {
            if (!pboth[k].contains({x, y}))continue;
            prow[row[x].size()].erase({x, y});
            pcol[col[y].size()].erase({x, y});
            pboth[k].erase({x, y});
            row[x].erase(y);
            col[y].erase(x);
            for (auto &&j: row[x]) {
                prow[row[x].size() + 1].erase({x, j});
                pboth[row[x].size() + 1].erase({x, j});
                prow[row[x].size()].emplace(x, j);
                if (pcol[row[x].size()].contains({x, j})) {
                    pboth[row[x].size()].emplace(x, j);
                }
            }
            for (auto &&i: col[y]) {
                pcol[col[y].size() + 1].erase({i, y});
                pboth[col[y].size() + 1].erase({i, y});
                pcol[col[y].size()].emplace(i, y);
                if (prow[col[y].size()].contains({i, y})) {
                    pboth[col[y].size()].emplace(i, y);
                }
            }
            z++;
        }

        auto tprow = prow[k];
        for (auto &&[x, y]: tprow) {
            if (!prow[k].contains({x, y}))continue;
            prow[row[x].size()].erase({x, y});
            pcol[col[y].size()].erase({x, y});
            pboth[k].erase({x, y});
            row[x].erase(y);
            col[y].erase(x);
            for (auto &&j: row[x]) {
                prow[row[x].size() + 1].erase({x, j});
                pboth[row[x].size() + 1].erase({x, j});
                prow[row[x].size()].emplace(x, j);
                if (pcol[row[x].size()].contains({x, j})) {
                    pboth[row[x].size()].emplace(x, j);
                }
            }
            for (auto &&i: col[y]) {
                pcol[col[y].size() + 1].erase({i, y});
                pboth[col[y].size() + 1].erase({i, y});
                pcol[col[y].size()].emplace(i, y);
                if (prow[col[y].size()].contains({i, y})) {
                    pboth[col[y].size()].emplace(i, y);
                }
            }
            z++;
        }
        auto tpcol = pcol[k];
        for (auto &&[x, y]: tpcol) {
            if (!pcol[k].contains({x, y}))continue;
            prow[row[x].size()].erase({x, y});
            pcol[col[y].size()].erase({x, y});
            pboth[k].erase({x, y});
            row[x].erase(y);
            col[y].erase(x);
            for (auto &&j: row[x]) {
                prow[row[x].size() + 1].erase({x, j});
                pboth[row[x].size() + 1].erase({x, j});
                prow[row[x].size()].emplace(x, j);
                if (pcol[row[x].size()].contains({x, j})) {
                    pboth[row[x].size()].emplace(x, j);
                }
            }
            for (auto &&i: col[y]) {
                pcol[col[y].size() + 1].erase({i, y});
                pboth[col[y].size() + 1].erase({i, y});
                pcol[col[y].size()].emplace(i, y);
                if (prow[col[y].size()].contains({i, y})) {
                    pboth[col[y].size()].emplace(i, y);
                }
            }
            z++;
        }
        ans = min(ans, c * (k - 1) + d * z);
    }
    cout << ans;
}
//3 4 2 1
//.***
//*..*
//**..
//
//3 4 1 2
//.***
//*..*
//**..