//
// Created by DELLPC on 24-5-19.
//
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;

#define  endl '\n'
//2
//7
//4 6 1
//12 14 2
//5 11 3
//1 6 4
//11 13 4
//4 7 5
//3 5 6
//4 7
//1
//2 4 2
//2 5

void solve() {
    int n;
    cin >> n;
    map<int, vector<pair<int, int>>> arr;
    for (int i = 1; i <= n; i++) {
        int l, r, h;
        cin >> l >> r >> h;
        arr[h].emplace_back(l, r);
    }
    for (auto &[i, v]: arr) {
        sort(v.begin(), v.end());
        vector<pair<int, int>> tmp;
        pair<int, int> now = v[0];
        for (auto [l, r]: v) {
            auto [nl, nr] = now;
            if (nr < l) {
                tmp.emplace_back(now);
                now = {l, r};
            } else {
                now = {min(l, nl), max(r, nr)};
            }
        }
        tmp.emplace_back(now);
        arr[i] = tmp;
    }
    int nx, ny;
    cin >> nx >> ny;
    for (auto i = arr.rbegin(); i != arr.rend(); i++) {
        auto [h, v] = *i;
        if (h > ny) {
            continue;
        } else {
            for (auto [l, r]: v) {
                if (l <  nx && nx <  r) {
                    nx = r;
                }
            }
        }
    }
    cout << nx << endl;
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

