//
// Created by DELLPC on 24-5-19.
//
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;

#define  endl '\n'


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<pair<i64, i64>> arr;


    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        x -= i;
        y -= i;
        arr.emplace_back(x, y);

    }
    sort(arr.begin(), arr.end(), [](auto a, auto b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });

    stack<int> st;
    for (auto [i, j]: arr) {
//        cerr<<i<<" "<<j<<endl;
        int misn = j;
        while (!st.empty() && j >= st.top()) {

            misn = min(st.top(),misn);
            st.pop();

        }
        st.emplace(misn);
    }
    cout << st.size() << endl;

}

