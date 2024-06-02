//
// Created by DELLPC on 24-3-31.
//
#include<bits/stdc++.h>

using namespace std;
#define irep(i, l, r) for(int i = l; i <= r; ++ i)

const int mod = 1000000000 + 7;

#define ll long long
#define LD double
const int N = 100000 + 7;
//ll f[12][12][2], g[12][12][2];

int f[N][12][12][2];

int main() {

    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    irep(i, 0, n - 1)cin >> a[i];
    irep(i, 0, n - 1)cin >> b[i];
    ranges::sort(a);
    ranges::sort(b);
    ranges::reverse(a);
    ranges::reverse(b);
    memset(f, 0x3f, sizeof f);
    int inf = f[0][0][0][0];
    function<int(int, int, int, int, int, int)> dfs = [&](int c, int i, int j, int cur, int ca, int cb)->int{
        // finished rounds, A pick, B pick, cur player
        if(f[c][i][j][cur] != inf)return f[c][i][j][cur];
        if(cur == 0){
            //pick
            int f1 = -mod;
            if(ca < n && i < k){
                dfs(c, i + 1, j, 1, ca + 1, cb);
                f1 = f[c][i + 1][j][1] + a[ca];
            }

            if(cb < n){
                dfs(c, i, j, 1, ca, cb + 1);
                f1 = max(f1, f[c][i][j][1]);
            }
            if(f1 == -mod)f1 = 0;
            f[c][i][j][cur] = f1;
        }
        else{
            int f1 = mod;
            if(cb < n && j < k){
                dfs(c + 1, i, j + 1, 0, ca, cb + 1);
                f1 = f[c + 1][i][j + 1][0] - b[cb];
            }
            if(ca < n){
                dfs(c + 1, i, j, cur ^ 1, ca + 1, cb);
                f1 = min(f1, f[c + 1][i][j][0]);
            }
            if(f1 == mod)f1 = 0;
            f[c][i][j][cur] = f1;
        }
//        cerr << c << ' ' << i << ' ' << j << ' ' << cur << ' ' << f[c][i][j][cur] << '\n';
        return f[c][i][j][cur];
    };
    dfs(0, 0, 0, 0, 0, 0);
    cout << f[0][0][0][0];

//
//    irep(c, 0, n) {
//        irep(i, 0, k) {
//            irep(j, 0, k) {
//                if (c && (j) && i <= c && j <= c && c - i + j - 1 < n) {
//                    if (c == 1 && i == 1 && j == 1) {
//                        cerr << "U";
//                    }
//                    if (i == c && j == c)f[i][j][0] = g[i][j - 1][1] - b[c - i + j - 1];
//                    else f[i][j][0] = min(g[i][j - 1][1] - b[c - i + j - 1], g[i][j][1]);
//                } else f[i][j][0] = g[i][j][1];
//            }
//        }
//
//        irep(i, 0, k) {
//            irep(j, 0, k) {
//                if (i && i <= c + 1 && j <= c && c - j - 1 + i < n) {
//                    if (i == c && j == c) f[i][j][1] = f[i][j][0];
//                    else f[i][j][1] = max(f[i - 1][j][0] + a[c + i - j - 1], f[i][j][0]);
//                } else f[i][j][1] = f[i][j][0];
//            }
//        }
//        irep(i, 0, k) {
//            irep(j, 0, k) {
//                cerr << f[i][j][0] << ' ';
//            }
//            cerr << endl;
//        }
//        cerr << endl;
//        irep(i, 0, k) {
//            irep(j, 0, k) {
//                cerr << f[i][j][1] << ' ';
//            }
//            cerr << endl;
//        }
//        cerr << "--------\n";
//        memset(g, 0, sizeof g);
//        swap(f, g);
//    }
//    ll ans = -mod;
//    irep(i, 0, k) {
//        irep(j, 0, k) {
//            ans = max(ans, g[i][j][0]);
//        }
//    }
//    cout << ans;
    return 0;
}