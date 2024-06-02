#include "bits/stdc++.h"

using namespace std;

#ifndef ONLINE_JUDGE

#include "test.h"

#else
#define debug(...) 42
#define debug_assert(...) 42
#endif


#define IOS ios::sync_with_stdio(0),cin.tie(0)

using ll = long long;
using ull = unsigned long long;

#define endl '\n'
#define int ll

using VI = vector<int>;
using VII = vector<VI>;
using PII = pair<int, int>;
const int inf = 1e18;
const int mod = 1e9 + 7;
template<typename T, typename Compare =less<>>
using pqinit = priority_queue<T, vector<T>, Compare>;


vector<int> prime;

void init() {
    auto isprime = [&](int x) {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    };
    debug(isprime(999983), 999983);
//    VI isprime(1e6);
//    for (int i = 2; i < 1e6; i++) {
//        if (isprime[i] == 0) {
//            prime.push_back(i);
//            for (int j = i; j < 1e6; j += i) {
//                isprime[j] = i;
//            }
//        }
//    }
}


void solve() {
    int n, m;
    cin >> n >> m;
    //999983
    vector<set<int>> mp(n + 1);
    int as = 1000000000;
//    cout << 999983 << " " << (m - n + 1) * 1e9 + 999983 << endl;
    printf("999983 999983\n" );
    for (int i = 1; i < n - 1; i++) {
        cout << i << " " << i + 1 << " " << 1 << endl;
    }
    cout << n - 1 << " " << n << " " << 999983 - n + 2 << endl;
    m -= n - 1;
    int i = 1;
    int j = i + 1;
    while (m) {
        j++;
        if (j == n + 1) {
            i++;
            j = i + 2;
        }
        printf("%lld %lld %lld\n", i, j, as);
        m--;
    }


}

signed main() {
//    IOS;
    init();
    // debug(1);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}