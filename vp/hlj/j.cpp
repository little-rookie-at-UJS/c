//
// Created by DELLPC on 24-5-19.
//
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;

#define  endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int m, n;
    cin >> n >> m;
    vector<vector<i64>> a(n + 2, vector<i64>(m + 2, 0));
    vector<vector<i64>> b(n + 2, vector<i64>(m + 2, 0));
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            cerr << a[i][j] << " ";
//        }
//        cerr << endl;
//    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            cerr << b[i][j] << " ";
//        }
//        cerr << endl;
//    }
    const i64 inf = 1e18;
    vector<vector<i64>> dis(n + 2, vector<i64>(m + 2, inf));
    dis[n][m] = b[n][m];
    for (int i = n; i; i--) {
        for (int j = m; j; j--) {
            dis[i][j - 1] = min(dis[i][j - 1], dis[i][j] + b[i][j - 1]);
            dis[i - 1][j] = min(dis[i - 1][j], dis[i][j] + b[i - 1][j]);
        }
    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            cerr << dis[i][j] << " ";
//        }
//        cerr << endl;
//    }
    vector<vector<i64>> cost(n + 2, vector<i64>(m + 2, inf));
    cost[1][1] = a[1][1] + b[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i < n) {
                i64 cost1 = cost[i][j] + b[i + 1][j];
                if (a[i + 1][j] >= cost1) {
                    cost[i + 1][j] = min(cost[i + 1][j], cost1);
                }
            }
            if (j < m) {
                i64 cost1 = cost[i][j] + b[i][j + 1];
                if (a[i][j + 1] >= cost1) {
                    cost[i][j + 1] = min(cost[i][j + 1], cost1);
                }
            }
        }
    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            if (left[i][j] == -1)continue;
//            if (i < n) {
//                int t1 = left[i][j] - dis[i + 1][j];
//                if (t1 >= 0) {
//                    left[i + 1][j] = max(left[i + 1][j], left[i][j] - b[i + 1][j]);
//                }
//            }
//            if (j < m) {
//                int t1 = left[i][j] - dis[i][j + 1];
//                if (t1 >= 0) {
//                    left[i][j + 1] = max(left[i][j + 1], left[i][j] - b[i][j + 1]);
//                }
//            }
//        }
//    }
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == n || j == m) {
                if (cost[i][j] != inf) {
                    flag = true;
                }
            }
//            cerr << cost[i][j] << " ";
        }
//        cerr << endl;
    }
    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}

