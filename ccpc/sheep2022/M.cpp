//
// Created by DELLPC on 24-3-31.
//
#include <bits/stdc++.h>

using namespace std;

bool win(char x, char y) {
    if(x == 'S' && y == 'P')
        return 1;
    if(x == 'P' && y == 'R')
        return 1;
    if(x == 'R' && y == 'S')
        return 1;
    return 0;
}


void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int c1 = 0, c2 = 0, c3 = 0;
    vector<int> l(n + 5), r(n + 5);
    vector<bool> vis(n + 5, 0);
    vector<char> node(n + 5);
    int ll = 1;
    int rr= 2;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'S')
            c1++;
        else if(s[i] == 'P')
            c2++;
        else
            c3++;
        node[i + 3] = s[i];
    }
    auto op = [&](char c) {
        if(c == 'S')
            c1--;
        else if(c == 'P')
            c2--;
        else
            c3--;
    };
    auto link = [&](int x, int y) {
        l[y] = x;
        r[x] = y;
    };
    auto ls = [&] (int x) {
        if(l[x] != ll && win(node[x], node[l[x]]))
            return 0;
        if(r[x] != rr && win(node[x], node[r[x]]))
            return 0;
        return 1;
    };
    queue<int> q1, q2;
    for(int i = 0; i < n - 1; i++) {
        link(i + 3, i + 4);
    }
    link(ll, 3);
    link(n + 2, rr);
    for(int i = 0; i < n; i ++) {
        if(ls(i + 3)) {
            q2.push(i + 3);
            //cout << node[i + 3] << i << ' ' <<  endl;
            vis[i + 3] = 1;
        }
    }
    while(1) {
        //cout << c1 << ' ' << c2 << ' ' << c3 << endl;
        if(c1 == 0 && c2 == 0) {
            cout << 'R' << endl;
            return;
        }
        if(c2 == 0 && c3 == 0) {
            cout << 'S' << endl;
            return;
        }
        if(c1 == 0 && c3 == 0) {
            cout << 'P' << endl;
            return;
        }
        while(!q2.empty()) {
            int u = q2.front();
            q2.pop();
            link(l[u], r[u]);
            op(node[u]);
            q1.push(l[u]);
            q1.push(r[u]);
        }
        while(!q1.empty()) {
            int u = q1.front();
            q1.pop();
            if(u == ll || u == rr)
                continue;
            if(vis[u])
                continue;
            if(!ls(u))
                continue;
            vis[u] = 1;
            q2.push(u);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}

