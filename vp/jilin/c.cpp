//
// Created by DELLPC on 24-5-19.
//
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;

#define  endl '\n'

const int mod = 1e9 + 7;


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    i64 res = 0, fres = 0, a = 0, fa = 1;
//    i64 res = 0, fres = 0, a = 1, fa = 1;
    for (auto i: s) {
        i64 b = (res + fres) % mod;
        i64 c = (b + fres) % mod;
//        cerr << b << " " << c << endl;
        res = b, fres = c;
        if (i == '1') {
            res = (res + a) % mod;
            fres = (fres + fa) % mod;
//            cerr << res << " " << fres << endl;
            c = (a + fa) % mod;
            a = fa;
            fa = c;
        }
    }
//    cerr << a << " " << fa << endl;
    res = (res + a) % mod;
    cout << res << endl;


}
