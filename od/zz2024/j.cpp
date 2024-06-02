#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

set<int> prime;
const int maxs = 1e6 + 100;

void solve() {
    int x;
    cin >> x;
    vector<int> arr;
    while (x) {
        arr.emplace_back(x % 10);
        x /= 10;
    }
    sort(arr.begin(), arr.end());
    do {
        int now = 0;
        for (auto i: arr) {
            now *= 10;
            now += i;
        }
//        cerr << now << endl;
        if (now < 1e4)continue;
        if (!prime.count(now)) {
            cout << now << "\n";
            return;
        }
    } while (next_permutation(arr.begin(), arr.end()));
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    vector<int> vis(maxs);
    for (int i = 2; i < maxs; i++) {
        if (!vis[i]) {
            prime.emplace(i);
            for (int j = i; j < maxs; j += i) {
                vis[j] = 1;
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}
//2
//4
//8 3 3 5
//1 2 3 2
//5
//4 3 4 5 6
//3 1 3 1 1