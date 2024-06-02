//
// Created by DELLPC on 24-4-10.
//
//
// Created by DELLPC on 24-4-10.
//
#include <bits/stdc++.h>

using namespace std;
using i64 = int;

struct op {
    i64 x1, x2, y1, y2, c, t;
    bool operator < (op xx) const {
        return y1 < xx.y1;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<op> ops(n);
    vector<i64> xx, yy;
    for(int i = 0; i < n; i++) {
        cin >> ops[i].x1 >> ops[i].y2 >> ops[i].x2 >> ops[i].y1 >> ops[i].c;
        ops[i].t = i;
        ops[i].x1++;
        ops[i].y1++;
        xx.push_back(ops[i].x1);
        xx.push_back(ops[i].x2);
        yy.push_back(ops[i].y1);
        yy.push_back(ops[i].y2);
        xx.push_back(ops[i].x1 + 1);
        xx.push_back(ops[i].x2 + 1);
        yy.push_back(ops[i].y1 + 1);
        yy.push_back(ops[i].y2 + 1);
    }
    sort(xx.begin(),xx.end());
    sort(yy.begin(),yy.end());
    int cnt1 = 0, cnt2 = 0;
    map<i64, i64> m1, m2;
    for(auto x : xx) {
        if(!m1[x]) {
            m1[x] = ++cnt1;
        }
    }
    for(auto y : yy) {
        if(!m2[y]) {
            m2[y] = ++cnt2;
        }
    }
    for(int i = 0; i < n; i++) {
        ops[i].x1 = m1[ops[i].x1];
        ops[i].y2 = m2[ops[i].y2];
        ops[i].x2 = m1[ops[i].x2];
        ops[i].y1 = m2[ops[i].y1];
    }
    auto cmp = [&](int x, int y) {
        return ops[x].y1 < ops[y].y1;
    };
    sort(ops.begin(), ops.end());
    set<int> col;
    for(int i = 1; i <= cnt1; i++) {
        vector<int> qwq;
        for(int j = 0 ; j < n; j++) {
            auto oop = ops[j];
            if(oop.x1 <= i && oop.x2 >= i) {
                qwq.push_back(j);
            }
        }
        deque<int> ss;
        sort(qwq.begin(), qwq.end(), cmp);
        int cur = 0;
        for(int j = 1; j <= cnt2; j++) {
            bool flag = 0;
            while(cur != qwq.size() && ops[qwq[cur]].y1 <= j) {
                while(!ss.empty()) {

                }
                cur++;
                flag = 1;
            }
            if(!flag)
                continue;
            while(!s.empty() && ops[ss.front()].y2 < j) {
                ss.pop_front();
            }
            if(!ss.empty()) {
                if(!col.count(ops[ss.front()].c))
                    col.insert(ops[ss.front()].c);
            }
        }
    }
    cout << col.size() << endl;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
