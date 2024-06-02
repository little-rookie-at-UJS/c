//
// Created by DELLPC on 24-4-28.
//
#include<bits/stdc++.h>

using namespace std;

#define irep(i, l, r) for(int i = l; i <= r; ++ i)
#define drep(i, r, l) for(int i = r; i >= l; -- i)

#define ll long long
#define LD double
const int mod =1000000000 + 7;
int n, m;
const int N = 2 * 1000000 + 8;
int arr[1000000 * 2 + 8];
int res, base[N] = {1};
void dfs(int cur, int x2, int x3, int inv){
    if(n + m > 2000 && inv > 3){
        return;
    }
    if(cur == -1){
        if(res == 0){
            drep(i, m + n - 1, 0)
                cout << arr[i];
            exit(0);
        }
    }
    int RE = res, in = inv;
    if(x3){
        if(n + m > 2000 && cur && arr[cur - 1] == 2){
            if(cur <= n + 4 && cur >= n - 820)
                ++ inv;
            else goto lab;
        }
        res += base[cur] * 3;
        res %= 2023;
        arr[cur] = 3;
        dfs(cur - 1, x2, x3 - 1, inv);
        res = RE;
        inv = in;
    }
    lab:
    if(x2){
        if(n + m > 2000 && x3 > 2)return;
        res += base[cur] * 2;
        res %= 2023;
        arr[cur] = 2;
        dfs(cur - 1, x2 - 1, x3, inv);
        res = RE;
    }
}

void solve(){
    base[0] = 1;
    cin >> n >> m;
    irep(i, 1, m + n){
        base[i] = (base[i - 1] * 10) % 2023;
    }

    dfs(n + m - 1, n, m, 0);
    cout << -1;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T = 1;
    while(T --){
        solve();
    }
    return 0;
}