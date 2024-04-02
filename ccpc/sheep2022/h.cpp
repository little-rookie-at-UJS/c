//
// Created by DELLPC on 24-3-31.
//
#include <bits/stdc++.h>

using namespace std;


void solve() {
    int x = 150, y = 150;
    int n;
    cin >> n;
    cout << 2 * n - 1 << endl;
    for (int i = 1; i < n; i++) {
        cout << x - i << " " << x - i << endl;
        cout << x + i << " " << x + i << endl;
    }
    cout << x << " " << x << endl;
}

int main() {
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}

000000000000000