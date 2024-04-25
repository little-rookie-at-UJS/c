//
// Created by DELLPC on 24-4-21.
//
#include<bits/stdc++.h>

using namespace std;
struct op {
    int n, s, w, e;
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int m;
    cin >> m;
    vector<op> ops(m * m + 1);
    int st, num;
    vector<int> nn(m * m + 1), ww(m * m + 1), cnt(m * m + 1);
    for (int i = 1; i <= m * m; i++) {
        cin >> ops[i].n >> ops[i].s >> ops[i].w >> ops[i].e;
        if (ops[i].s != -1)
            cnt[ops[i].s]++;
        if (ops[i].e != -1)
            cnt[ops[i].e]++;
        if (ops[i].n == -1 && ops[i].w == -1)
            st = i;
        if (ops[i].n != -1)
            nn[ops[i].n] = i;
        if (ops[i].w != -1)
            ww[ops[i].w] = i;
    }
    for (int i = 1; i <= m * m; i++) {
        if (cnt[i] == 0) {
            num = i;
        }
    }
    while (1) {
        int now1 = num, now2 = st;
        while (1) {
            int t = ops[now2].e;

            cout << now1;

            if (t == -1) {
                break;
            } else {
                cout << ' ';
            }
            now2 = ww[now1];
            now1 = t;
        }
        cout << "\n";
        int t = ops[st].s;
        if (t == -1) {
            break;
        }
        st = nn[num];
        num = t;
    }
    return 0;
}