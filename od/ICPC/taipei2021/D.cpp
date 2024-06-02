//
// Created by DELLPC on 24-4-10.
//
#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define irep(i, l, r) for(int i = l; i <= r; ++ i)
#define drep(i, r, l) for(int i = r; i >= l; -- i)
//map<array<int, 10>, pair<int, int>>f;
int a[100];
map<array<int, 10>, ll>f;
int main(){
    int d, k;
    cin >> d >> k;
    irep(i, 1, d){
        int x;
        cin >> x;
        a[x] ++;
    }

    ll ans = 0;
    deque<pair<array<int, 10>, ll>>S;

    S.push_front(make_pair((array<int, 10>){0,0,0,0,0,0,0,0,0,0}, 0));
    while(S.size()){
        auto [arr, x] = S.front();
        S.pop_front();
        x = f[arr];
        int fl = 0, res = arr[0];
        irep(i, 1, 9){
            if(arr[i] < a[i]){
                fl = 1;
                ll y = x * 10 + i;
                arr[0] = (res * 10 + i) % k;
                arr[i] ++;
                if(!f.contains(arr)){
                    S.push_back(make_pair(arr, y));
                }
                if(f[arr] < y){
                    f[arr] = y;
                }


                arr[0] = res;
                arr[i] --;
            }
        }
        if(fl == 0){
            if(ans % k < x % k || ans % k == x % k && x > ans){
                ans = x;
            }
        }
    }
    cout << ans;
}
/*
 16 100
 9 7 5 4 7 3 1 6 5 4 2 3 7 8 9 8
 */