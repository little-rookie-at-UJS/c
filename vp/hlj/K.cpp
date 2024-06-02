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
    i64 a, b, c, d;
    vector<int> arr(4);
    for (auto &i: arr) {
        cin >> i;
    }
    sort(arr.begin(), arr.end());
    set<int> s;
    do {
        a = arr[0],b = arr[1],c = arr[2], d = arr[3];

        s.emplace(a + b + c + d);
        s.emplace(a + b + c - d);
        s.emplace(a + b + c * d);
        s.emplace(a + b - c + d);
        s.emplace(a + b - c - d);
        s.emplace(a + b - c * d);
        s.emplace(a + b * c + d);
        s.emplace(a + b * c - d);
        s.emplace(a + b * c * d);
        {
            s.emplace(a - b + c + d);
            s.emplace(a - b + c - d);
            s.emplace(a - b + c * d);
            s.emplace(a - b - c + d);
            s.emplace(a - b - c - d);
            s.emplace(a - b - c * d);
            s.emplace(a - b * c + d);
            s.emplace(a - b * c - d);
            s.emplace(a - b * c * d);

            s.emplace(a * b + c + d);
            s.emplace(a * b + c - d);
            s.emplace(a * b + c * d);
            s.emplace(a * b - c + d);
            s.emplace(a * b - c - d);
            s.emplace(a * b - c * d);
            s.emplace(a * b * c + d);
            s.emplace(a * b * c - d);
            s.emplace(a * b * c * d);
        }
    } while (next_permutation(arr.begin(), arr.end()));
//
//    cin >> a >> b >> c >> d;


    cout << s.size() << endl;


}

