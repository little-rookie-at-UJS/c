//
// Created by DELLPC on 24-4-10.
//
//
// Created by DELLPC on 24-4-10.
//
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n), b(n), p1, p2;
    i64 delt = 0;
    for(i64 i = 0; i < n; i++) {
        cin >> a[i];
        delt -= (i + 1) * a[i];
    }
    for(i64 i = 0; i < n; i++) {
        cin >> b[i];
        delt += (i + 1) * b[i];
    }
    for(i64 i = 0; i < n; i++) {
        if(a[i] == 1) {
            p1.push_back(i + 1);
        }
        if(b[i] == 2) {
            p2.push_back(i + 1);
        }
    }
    if(delt == 0) {
        cout << 0 << endl;
        return;
    }
    i64 len = min(p1.size(), p2.size());
    vector<bitset<100002>> f(len + 1) ,g(len +1);
    g[0][0] = f[0][0] = 1;
    for(int i = 0; i < p1.size(); i++) {
        for(int j = len; j >= 1; j--) {
            f[j] |= (f[j - 1] << p1[i]);
        }
    }
    for(int i = 0; i < p2.size(); i++) {
        for(int j = len; j >= 1; j--) {
            g[j] |= (g[j - 1] << p2[i]);
        }
    }
    for(i64 ans = 1; ans <= len; ans++) {
        set<i64> s;
        for(i64 i = 0; i < 100002; i++) {
            if(f[ans][i] == 1) {
                s.insert(delt - i);
            }
        }
        for(i64 i = 0; i < 100002; i++) {
            if(g[ans][i] == 1 && s.count(i)) {
                cout << ans << endl;
                return;
            }
        }
    }
    cout << -1 <<endl;
}

int main() {
    int t;
    cin >>t;
    while(t--) {
        solve();
    }
    return 0;
}
