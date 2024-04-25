//
// Created by DELLPC on 24-4-21.
//
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define irep(i, l, r) for(int i = l; i <= r; ++ i)
#define drep(i, r, l) for(int i = r; i >= l; -- i)
const int N = 500000 +7;
const int mod = 1000000000 + 7;
#define ll long long
#define LD double

int n, q, st;

ll p[N], h[N];
int fa[N], nxt[N], fs[N];

int find(int x){
    if(fa[x] == x)return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int x, int y){
    if(x < 0 || y < 0)return;
    x = find(x), y = find(y);
    if(fs[x] > fs[y])swap(x, y);
    nxt[x] = nxt[y];
    fa[y] = x;
}

ll val(int x){
    x = find(x);
    if(nxt[x] == n)return 0;
    return (h[fs[x]] - h[nxt[x]]) * (h[fs[x]] - h[nxt[x]]);
}

void solve(){
    //n, q;
    cin >> n >> q;
    ll base = 0, lastans = 0, sum = 0;

    irep(i, 0, n - 1){
        cin >> h[i];

    }

    irep(i, 0, n - 1){
        cin >> p[i];
        p[i] --;
    }
    irep(i, 0, n - 2){
        base += (h[i] - h[i + 1]) * (h[i] - h[i + 1]);
    }
//    lastans = base;
    sum = base;

    irep(i, 0, n - 1){
        fa[i] = i;
        nxt[i] = i + 1, fs[i] = i;
    }

    for(int i = st - 1;;){
        if(i == -1)i += n;
        lastans += sum;
//        cerr << sum << ' ';
        sum -= val(p[i]);
        if(p[i])sum -= val(p[i] - 1);
        if(p[i])merge(p[i] - 1, p[i]);

        if(p[i])sum += val(p[i]);

        i = (i - 1 + n) % n;
        if((i + 1) % n == (st))break;
    }
//    cerr << endl;

    cout << lastans << '\n';

    while(q --){
        irep(i, 0, n - 1){
            fa[i] = i;
            nxt[i] = i + 1, fs[i] = i;
        }
//        sum = base;
        int k0;
        cin >> k0;
        k0 += lastans;
        st = (st + k0) % n;
        lastans = 0;
        sum = base;
        cerr << st << endl;
        for(int i = st - 1;;){
            lastans += sum;
            if(i == -1)i += n;

            sum -= val(p[i]);
            if(p[i])sum -= val(p[i] - 1);
            if(p[i])merge(p[i] - 1, p[i]);
            sum += val(p[i]);
            i = (i - 1 + n) % n;
            if((i + 1) % n == (st))break;
        }
        cout << lastans << '\n';
    }
}

signed main(){
    int T = 1;
//    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}
