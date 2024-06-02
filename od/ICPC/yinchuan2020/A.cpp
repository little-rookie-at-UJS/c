//
// Created by DELLPC on 24-4-21.
//
#include<bits/stdc++.h>
using namespace std;
#define irep(i, l, r) for(int i = l; i <= r; ++ i)
#define drep(i, r, l) for(int i = r; i >= l; -- i)
const int N = 500000 +7;
const int mod = 1000000000 + 7;
#define ll long long
#define LD double

void solve(){
    int n;
    cin >> n;
    vector<array<int, 3>>a(n);
    vector<array<int, 2>>t(n);
    vector<pair<int, char>>ans(3);
    irep(i, 0, n - 1){
        int x, y, z;
        cin >> x >>y >>z;
        a[i] = {x, y, z};
    }
    irep(i, 0, n - 1){
        auto [x, y, z] = a[i];
        t[i] = {y, z};
    }
    ranges::sort(t);
    t.erase(unique(t.begin(), t.end()), t.end());
    ans[0] = make_pair( t.size(), 'X');

    t.resize(n);
    irep(i, 0, n - 1){
        auto [x, y, z] = a[i];
        t[i] = {x, z};
    }
    ranges::sort(t);
    t.erase(unique(t.begin(), t.end()), t.end());
    ans[1] = make_pair( t.size(), 'Y');



    t.resize(n);
    irep(i, 0, n - 1){
        auto [x, y, z] = a[i];
        t[i] = {x, y};
    }
    ranges::sort(t);
    t.erase(unique(t.begin(), t.end()), t.end());
    ans[2] = make_pair( t.size(), 'Z');

    ranges::sort(ans, [&](auto p, auto q){
        return make_pair(p.first, q.second) < make_pair(q.first, p.second);
    });
    cout << ans.back().second;
//    sort(a.begin(), a)
}
int main(){
    int T = 1;
//    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}
