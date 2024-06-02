//
// Created by DELLPC on 24-5-19.
//
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;

#define  endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, ha, hb;
        cin >> n >> ha >> hb;
        priority_queue<int> pqa;
        priority_queue<int, vector<int>, greater<>> pqb;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x != -1) {
                pqa.emplace(x);
            }
        }
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x != -1) {
                pqb.emplace(x);
            }
        }
        while (!pqa.empty() && !pqb.empty()) {
            auto a = pqa.top();
            pqa.pop();
            auto b = pqb.top();
            pqb.pop();
            hb -= a;
            ha -= b;
//            cerr << ha << " " << hb << endl;
            if (ha <= 0 || hb <= 0) {
                break;
            }
        }
        if (ha > 0 && hb <= 0) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}

