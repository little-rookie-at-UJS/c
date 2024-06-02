//
// Created by DELLPC on 24-5-19.
//
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;

#define  endl '\n'

struct node {
    i64 c;
    vector<i64> grade;
    i64 id;

    node(int n) {
        c = 0;
        grade.resize(n);
    }

    bool operator<(const node n) {
        return c < n.c;
    }
};


void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<node> arr(n, node(m));
    i64 id = 0;
    for (auto &i: arr) {
        cin >> i.c;
        i.id = id++;
        for (auto &j: i.grade) {
            cin >> j;
        }
    }
    sort(arr.begin(), arr.end());
    i64 maxs, nextmaxs, nows;

    nows = -1;
    maxs = -1;
    nextmaxs = -1;
    nows = arr[0].c;
    for (auto &i: arr) {
        if (i.c != nows) {
            nows = i.c;
            maxs = nextmaxs;
            nextmaxs = -1;
        }

        i64 ned = 0;
        i64 sums = 0;
        for (auto &j: i.grade) {
            if (j == -1) ned++;
            else sums += j;
        }
        if (sums <= maxs) {
            if (ned == 0) {
                cout << "No" << endl;
                return;
            }
            i64 av = (maxs + 1 - sums) / ned;
            i64 mo = (maxs + 1 - sums) % ned;
            if (av + (mo != 0) > k) {
                cout << "No" << endl;
                return;
            }
            for (auto &j: i.grade) {
                if (j == -1) {
                    if (mo) {
                        j = av + 1;
                        mo--;
                    } else j = av;

                }

            }
        } else {
            for (auto &j: i.grade) {
                if (j == -1) {
                    j = 0;
                }
            }
        }
        i64 sumss = 0;
        for (auto &j: i.grade) {
            sumss += j;
        }
        nextmaxs = max(nextmaxs, sumss);

    }
    sort(arr.begin(), arr.end(), [&](auto a, auto b) {
        return a.id < b.id;
    });
    cout << "Yes" << endl;
    for (auto i: arr) {
        for (auto j: i.grade) {
            cout << j << " ";
        }
        cout << endl;
    }

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}


