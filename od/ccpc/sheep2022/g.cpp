//
// Created by DELLPC on 24-3-31.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    vector<int> arr(n);
    for (auto &i: arr)cin >> i;
    while (arr.size() != 1) {
        vector<int> mir;
        for (int i = 0; i < arr.size(); i++) {
            if (i != 0) {
                if (arr[i] < arr[i - 1])continue;
            }
            if (i != arr.size() - 1) {
                if (arr[i] < arr[i + 1])continue;
            }
            mir.emplace_back(arr[i]);
        }
        arr = mir;
        ans++;
    }
    cout << ans;
    return 0;
}
