//
// Created by DELLPC on 24-5-19.
//
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;

#define  endl '\n'


void solve() {
    int n;
    cin >> n;
    if (n == 1 || n % 4 == 0) {
        cout << "impossible" << endl;
        return;
    }
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    swap(a[0], a[1]);
    for (int i = 3; i < n; i += 4) {
        swap(a[i], a[i + 1]);
    }
    for (auto i: a) {
        cout << i << " ";
    }
    cout << endl;

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}


