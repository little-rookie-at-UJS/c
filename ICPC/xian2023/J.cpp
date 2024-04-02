//
// Created by DELLPC on 2024/3/27.
//
#include<bits/stdc++.h>
using namespace std;
#define irep(i, l, r) for(int i = l; i <= r; ++ i)
#define drep(i, r, l) for(int i = r; i >= l; -- i)

const int N = 500000 + 7;
const int mod = 998244353;
#define ll long long
#define LD double

int main() {
    LD a, b;
    cin >> a >> b;
    cout << "1111111111111111111111111";
    vector<int>ans(25);
    irep(i, 0, 19 + 5) {
        b *= 2;
        if(b >= 1) {
            b -= 1;
            ans[i] = 2;
        }
        else ans[i] = 1;
    }
    reverse(ans.begin(), ans.end());
    ranges::for_each(ans, [&](int x) {
        cout << x;
    });
    return 0;
}

/*
 *
//
// Created by DELLPC on 2024/3/27.
//
#include<bits/stdc++.h>
using namespace std;
#define irep(i, l, r) for(int i = l; i <= r; ++ i)
#define drep(i, r, l) for(int i = r; i >= l; -- i)

const int N = 500000 + 7;
const int mod = 998244353;
#define ll long long

int main() {

return 0;
}
*/