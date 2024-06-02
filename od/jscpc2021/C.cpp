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
#define vv vector

//#define int long long

void solve() {
    vv<int> cnt(10);
    int sum = 0;
//    irep(i, 0, 9){
//        cin >> cnt[i];
//        sum += cnt[i];
//    }
//    int P = max_element(cnt.begin(), cnt.end()) - cnt.begin();
//    if(P == 0){
//        if(sum < P * 2){
//            cout << "-1\n";
//            return;
//        }
//    }
//    else{
//        if(sum < P * 2 + 1){
//            cout << "-1\n";
//            return;
//        }
//    }
//    int flag = 0;
//    while(1){
//
//        -- sum;
//        if(sum == 0)return;
//    }

    for (int i = 0; i <= 9; i++) cin >> cnt[i], sum += cnt[i];
    if(cnt[0] == 1 && sum == 1)
    {
        cout << 0 << endl;
        return;
    }
    if (cnt[0] > sum - cnt[0]) {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= 9; i++)
        if (cnt[i] > sum - cnt[i] + 1) {
            cout << -1 << endl;
            return;
        }
    string s = "";
    int la = 0;
    for (int i = 1; i <= sum; i++) {
        int t = -1;
        for (int j = 0; j <= 9; j++)
            if (j != la && 2 * cnt[j] == sum - i + 2) {
                t = j;
                break;
            }
//        cout << t << endl;
        if (t == -1) {
            for (int j = 0; j <= 9; j++)
            {
//                if(la == -1)
//                {
//                    if(j == 0) continue;
//                }
                if (cnt[j] && j != la)
                {
                    t = j;
                    break;
                }
            }
        }
//        cout << t << endl;
        s += (t + '0');
        la = t;
        cnt[t]--;
    }
    cout << s << endl;

}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}