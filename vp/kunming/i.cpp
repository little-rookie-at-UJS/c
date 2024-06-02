//
// Created by DELLPC on 24-5-19.
//
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;

#define  endl '\n'
struct node {
    char c;
    int cnt;
};


void solve() {
    string s;
    cin >> s;

    deque<node> v;
    for (auto j: s) {
        if (v.empty() || j != v.back().c) {
            v.emplace_back(j, 1);
        } else {
            v.back().cnt++;
        }
    }
    int cnt = 0;
    for (auto i: v) {
        cnt += i.cnt / 2;
    }
    int maxs = cnt;
    int n = s.length();
    while (n--) {
        if (v.front().cnt % 2 == 0) {
            cnt--;
        }
        v.front().cnt--;
        if (v.front().c == v.back().c) {
            cnt -= v.back().cnt / 2;
            v.back().cnt++;
            cnt += v.back().cnt / 2;
        } else {
            v.emplace_back(v.front().c, 1);
        }
        if (v.front().cnt == 0) v.pop_front();

        maxs = min(maxs, cnt);
    }
    cout << maxs << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}


