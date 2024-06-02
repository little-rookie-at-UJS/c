//
// Created by DELLPC on 24-5-14.
//
#include<bits/stdc++.h>

using namespace std;

#define LD double

struct point{
    LD x, y;
    point(LD z = 0, LD w = 0){
        x = z, y = w;
    }
};

#define irep(i, l, r) for(int i = l; i <= r; ++ i)
const LD pi = acos(-1);
const LD eps = 1e-12;
void solve(){
    int n;
    cin >> n;
    vector<point>a(n);
    irep(i, 0, n - 1){
        int x, y;
        cin >> x >> y;
        a[i] = point(x, y);
    }
    LD ans = 1e18;
    auto fun = [&](){
        sort(a.begin(), a.end(), [&](auto p, auto q){
            return p.y - p.x > q.y - q.x;
        });

        LD l = 1, r = 1e11;
        vector<LD>Que(n);
        while(r - l > eps){
            LD mid = (l + r) * 0.5;
            LD k = mid;
            bool ok = 0;
            LD last = 0;
            irep(i, 0, n - 1){
                LD cur = - a[i].y + k * a[i].x;
                if(i && cur + eps < last){
                    ok = 1;
                    break;
                }
                last = cur;
            }
            if(ok)r = mid;
            else l = mid;
        }
        ans = min(ans, l);
    };
    fun();
    irep(i, 0, n - 1){
        a[i].x *= -1;
    }
    fun();
    irep(i, 0, n - 1){
        swap(a[i].x, a[i].y);
    }
    fun();
    irep(i, 0, n - 1){
        a[i].x *= -1;
    }
    fun();

    cout << (1 + ans) / sqrt( 1 + ans * ans) << '\n';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cout << fixed << setprecision(12);
    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}