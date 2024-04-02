//
// Created by DELLPC on 2024/3/27.
//
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;

vector<int> e[maxn];
int in[maxn];

void add(int u, int v) {
   e[u].push_back(v);
   in[v]++;
}

bool topo() {
    for(int i = 1; i <= n; i++) {
        if(in[i] == 0) {

        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    return 0;
}