//
// Created by DELLPC on 24-5-19.
//
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;

#define  endl '\n'

class Point {

private:


public:
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}

    Point() {}

    int operator*(const Point &a) {
        return x * a.x + y * a.y;
    }

    int operator^(const Point &a) {
        return x * a.y - y * a.x;
    }


    Point operator+(const Point &a) {
        return Point(x + a.x, y + a.y);
    }


    Point operator-(const Point &a) {
        return Point(x - a.x, y - a.y);
    }
};


double atan(Point a) {
    return atan2(a.y, a.x);
}

bool cmp(Point a, Point b) {
    return atan(a) < atan(b);
}

void solve() {

    int n;
    Point mid;
    cin >> n >> mid.x >> mid.y;
    int r;
    cin >> r;
    vector<Point> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i] = a[i] - mid;
    }
    sort(a.begin(), a.end(), cmp);





}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}


