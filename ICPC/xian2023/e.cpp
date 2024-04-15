#include "bits/stdc++.h"

using namespace std;

#ifndef ONLINE_JUDGE

#include "test.h"

#else
#define debug(...) 42
#define debug_assert(...) 42
#endif


#define IOS ios::sync_with_stdio(0),cin.tie(0)

using ll = long long;
using ull = unsigned long long;

#define endl '\n'
#define int ll

using VI = vector<int>;
using VII = vector<VI>;
using PII = pair<int, int>;
const int inf = 1e18;
const int mod = 1e9 + 7;
template<typename T, typename Compare =less<>>
using pqinit = priority_queue<T, vector<T>, Compare>;

void init() {
}

// 3 4
// 0000
// 0111
// 101
// 101
// 110
void solve() {
    int n, m;
    cin >> n >> m;
    //第i行前j列有多少个1
    vector<vector<int>> rows(n + 2, vector<int>(m + 2, 0));
    //第j列前i行有多少个1
    vector<vector<int>> cols(m + 2, vector<int>(n + 2, 0));

    for (int i = 2; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 2; j <= m + 1; j++) {
            rows[i][j] = rows[i][j - 1] + (s[j - 2] == '1');
        }
    }
    for (int i = 2; i <= n + 1; i++) {
        string s;
        cin >> s;
        for (int j = 2; j <= m; j++) {
            cols[j][i] = cols[j][i - 1] + (s[j - 2] == '1');
        }
    }
    debug(rows);
    debug(cols);
    // 整个矩形能否拼成大矩形
    function<bool(int, int, int, int)> dfs = [&](int x1, int y1, int x2, int y2) {
        debug(x1, y1, x2, y2);
        int cnt = 0;
        // 第y1+1列到y2-1列
        for (int i = y1 + 1; i < y2; i++) {
            cnt += cols[i][x2] - cols[i][x1  ];
            if (cols[i][x2] - cols[i][x1 ] == x2 - x1  ) {
                return dfs(x1, y1, x2, i) && dfs(x1, i, x2, y2);
            }
        }
        // 第x1 + 1行到x2-1行
        for (int i = x1 + 1; i < x2; i++) {
            cnt += rows[i][y2] - rows[i][y1  ];
            if (rows[i][y2] - rows[i][y1  ] == y2 - y1  ) {
                return dfs(x1, y1, i, y2) && dfs(i, y1, x2, y2);
            }
        }
        return cnt == 0;
    };
    cout << (dfs(1, 1, n + 1, m + 1) ? "YES" : "NO") << endl;

}

signed main() {
    IOS;
    init();
    // debug(1);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}
