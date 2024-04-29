//
// Created by DELLPC on 24-4-28.
//
#include<bits/stdc++.h>

using namespace std;
#define ll long long
void solve(){
    ll m, n;
    cin >> m >> n;
    if(m == 1){
        if(n == 0)cout << "1\n";
        else cout << "2\n";
        return;
    }
    if(n == 0){
        cout << (1ll << m) << '\n';
    }
    else cout << (1ll << m) - 1 << '\n';
}

int main(){
    int T;
    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}