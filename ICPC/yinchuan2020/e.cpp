#include "bits/stdc++.h"

using namespace std;

#define endl "\n"
#define debug(x)  cerr <<#x<<" "<<x<<endl;
using ll = long long;
#define int ll
struct node {
    int ma, mi, va;
};
const int inf = -1e18;

//{-F,-Cl,-Br,-I,-CH3,-CH2CH3,-CH2CH2CH3,-H}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    debug(n);
    vector<string> v = {"-F", "-Cl", "-Br", "-I",
                        "-CH3", "-CH2CH3", "-CH2CH2CH3", "-H"};


    map<string, int> mp;
    for (int i = 0; i < v.size(); i++) {
        mp[v[i]] = i + 1;
        debug(v[i]);
    }
    while (n--) {
        string s1, s2, s3, s4;
        cin >> s1 >> s2 >> s3 >> s4;
        set<string> s;
        s.emplace(s1);
        s.emplace(s2);
        s.emplace(s3);
        s.emplace(s4);


        if (s1 == s3
            || s2 == s4)
            cout << "None" << endl;
        else if (s.size() != 4) {
            if (s1 == s2 || s3 == s4)
                cout << "Cis" << endl;
            else
                cout << "Trans" << endl;
        } else {
            if ((mp[s1] > mp[s3]) == (mp[s2] > mp[s4])) {
                cout << "Zasamman" << endl;
            } else {
                cout << "Entgegen" << endl;
            }
        }
    }

}
// 2 -H -H -H -Cl -F -F -Br -Cl
//1 -F -F -Cl -Cl
//1 -F  -Cl -Cl -F

// -F -Cl -Br  -I
// -Br -F -Cl    -I