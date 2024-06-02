#include "bits/stdc++.h"

using namespace std;


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
//    cerr << t << endl;
    string s;
    int cnt = 0;
    for (int i = 1; i <= t; i++) {
        cin >> s;
        cerr << s << endl;
        if (s.size() == 5) {
            if (s[2] == s[4]) {
                set<char> se;

                for (int j = 0; j < 4; j++) {
                    se.emplace(s[j]);
                }
//                cerr << se.size() << endl;
                if (se.size() == 4) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;


}