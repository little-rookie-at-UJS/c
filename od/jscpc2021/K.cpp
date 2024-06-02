//
// Created by DELLPC on 24-4-28.
//
#include<bits/stdc++.h>

using namespace std;

#define irep(i, l, r) for(int i = l; i <= r; ++ i)
#define drep(i, r, l) for(int i = r; i >= l; -- i)

#define ll long long
#define LD double
const int mod = 1000000000 + 7;

bitset<1000000000 + 7>a;

void solve(){
    int n = 1000000000;
    int num = 1, tot = 1;
    while(tot < n){
        int B = __lg(num);
        while(1){
            a[tot ++] = (num & (1 << B));
            -- B;
            if(B == -1)break;
        }
        ++ num;
    }
    int maxlen = 0, sufmax = 0;
    irep(i, 0, n - 1){
        if(a[i] == 0)sufmax = 0;
        else{
            sufmax ++;
            if(sufmax > maxlen){
                maxlen = sufmax;
                cout << '{' <<i + 1 << ',' << sufmax << "},"<< endl;
            }
        }
    }
}
map<int, int>F = {
        {2,1},
        {3,2},
        {7,3},
        {19,4},
        {51,5},
        {131,6},
        {323,7},
        {771,8},
        {1795,9},
        {4099,10},
        {9219,11},
        {20483,12},
        {45059,13},
        {98307,14},
        {212995,15},
        {458755,16},
        {983043,17},
        {2097155,18},
        {4456451,19},
        {9437187,20},
        {19922947,21},
        {41943043,22},
        {88080387,23},
        {184549379,24},
        {385875971,25},
        {805306371,26}
};
int main(){
    int T;
    cin >> T;
    while(T --){
        ll x;
        cin >> x;
        cout << (-- F.upper_bound(x)) -> second << '\n';
    }
    return 0;
}