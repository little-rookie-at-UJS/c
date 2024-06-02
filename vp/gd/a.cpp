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
    long double a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << fixed << setprecision(10) << min(a, d * b) - min(a, (c - 1) * b) << endl;
    cout << fixed << setprecision(10) << b * (d - c + 1) << endl;
}
