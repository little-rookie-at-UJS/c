//
// Created by DELLPC on 24-4-10.
//
//
// Created by DELLPC on 24-4-10.
//
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    int s, f, r;
    vector<vector<int>> a(n + 2, vector<int>(m + 2));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m ;j++) {
            cin >> a[i][j];
        }
    }
    cin >> s >> f >> r;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m ;j++) {
            for(int k = 0; k < 4 ;k++) {
                int t1x = dx[k] + i, t1y = dy[k] + j;
                int t2x = dx[(k + 1) % 4] + i, t2y = dy[(k + 1) % 4] + j;
                if(a[i][j] == s && a[t1x][t1y] == f && a[t2x][t2y] == r) {
                    cout << i - 1 << ' ' << j - 1 << endl;
                    break;
                }
            }
        }
    }
 }

int main() {
    int t = 1;

    while(t--) {
        solve();
    }
    return 0;
}
