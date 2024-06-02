//
// Created by DELLPC on 24-5-19.
//
/*
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;

#define  endl '\n'
//4 2
//1 3
//2 5
//4 7
//5 9

int main() {
    mt19937_64 rng(random_device{}());
    int n, k;
    cin >> n >> k;
    vector<array<int, 3>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }
    shuffle(v.begin(), v.end(), rng);
    int maxs = max(maxs, n);

    auto check = [&](array<int, 3> a, array<int, 3> b) -> bool {
        int x1 = a[0], y1 = a[1];
        int x2 = b[0], y2 = b[1];
        if (x2 != x1) {

        }
    };
    for (int i = 0; i < maxs; i++) {
        for (int j = 1; j < maxs; j++) {
            if (check(v[i], v[j])) {
                return 0;
            }
        }
    }
}

*/

#include<bits/stdc++.h>

using namespace std;

#define LD double

struct point{
    LD x, y;
    point(LD a = 0, LD b = 0):x(a), y(b){}
    point operator +(const point &a)const{
        return point(x + a.x, y + a.y);
    }
    point operator -(const point & a)const{
        return point(x - a.x, y - a.y);
    }
};

LD det(point &a, point &b){
    return a.x * b.y - a.y * b.x;
}

LD dot(point &a, point &b){
    return a.x * b.y + a.y * b.x;
}

#define irep(i, l, r) for(int i = l; i <= r; ++ i)
#define drep(i, r, l) for(int i = r; i >= l; -- i)

int main(){
    int n, k;
    cin >> n >> k;
    vector<point>a(n);
    irep(i, 0, n - 1){
        LD x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    int lim = k + 1;
    irep(i, 0, lim - 1){
        irep(j, i + 1, lim - 1){
            /*
             润了，剩下的你自己写吧
             */
        }
    }
}