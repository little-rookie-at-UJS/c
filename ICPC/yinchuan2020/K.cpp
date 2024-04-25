//
// Created by DELLPC on 24-4-21.
#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e4 + 5;

string s[maxn];

int en(char c) {
    if (c == '/')
        return 0;
    if (c == '.')
        return 1;
    return c - 'a' + 2;
}

map<int, int> nex[maxn * 50];
int cn[maxn], ab[maxn], f[maxn];
int cnt = 1;

void insert(string ss) {
    int p = 1;
    int n = ss.size();
    vector<int> v;
    for (int i = 0; i < n; i++) {
        if (!nex[p][en(ss[i])])
            nex[p][en(ss[i])] = ++cnt;
        p = nex[p][en(ss[i])];
        v.push_back(p);
        cn[p]++;
    }
}

int sol(string ss) {
    vector<int> v;
    int p = 1;
    int n = ss.size();
    v.push_back(1);
    for (int i = 0; i < n; i++) {
        p = nex[p][en(ss[i])];
        cn[p]--;
        ab[p]++;
        f[p] = 0;
        v.push_back(p);
    }
    for(int i = n; i >= 1; i--) {
        p = v[i];
        for (auto [_, x]: nex[p]) {
            f[p] += f[x];
        }
        if (cn[p] == 0) {
            f[p] = 1;
        }
    }

    f[1] = 0;
    for(auto [_, x]:nex[1]) {
        f[1] += f[x];
    }
    return f[1];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        insert(s[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << sol(s[i]) << endl;
    }
    return 0;
}