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

void init() {
}

struct p {
    int id;
    vector<int> arr;

    p() {
        arr.emplace_back(0);
    }

    bool operator<(const p &p1) {
        return arr.back() < p1.arr.back();
    }

    bool operator>(const p &p1) {
        return arr.back() > p1.arr.back();
    }

    void emplace(int x) {
        arr.emplace_back(x);
    }

    int search(int x) {
        auto ans = ranges::upper_bound(arr, x);
        if (ans == arr.end()) ans--;
        debug(*ans);
        return *ans;
    }
};


void solve() {
    int n;
    cin >> n;

    vector<p> arr(n + 1);
    for (int i = 0; i <= n; i++) {
        arr[i].id = i;
    }
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        arr[x].emplace(y);
    }
    vector<p> m = arr;
    sort(arr.begin(), arr.end(), greater<>());
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        set<int> s;
        for (int i = 1; i <= x; i++) {
            int y;
            cin >> y;
            s.emplace(y);
        }

        int first_id = -1;
        int second_id = -1;
        for (int i = 0; i <= n; i++) {
            int id = arr[i].id;
            if (!s.count(id)) {
                first_id = id;
                i++;

                for (; i <= n; i++) {
                    id = arr[i].id;
                    if (!s.count(id)) {
                        second_id = id;
                        i++;
                        break;
                    }

                }
                break;
            }
        }
        debug(first_id, second_id);
        if (second_id == -1) {
//            int ans = m[first_id].arr.back();
            int ans = ((m[first_id].arr.size() > 1) ? m[first_id].arr[1] : m[first_id].arr[0]);
            if (ans) {
                cout << first_id << " " << ans << endl;
            } else {
                cout << 0 << " " << 0 << endl;
            }
        } else {
//            int b1 = m[first_id].arr.back();
            int b2 = m[second_id].arr.back();
            int ans = m[first_id].search(b2);
            if (ans) {
                cout << first_id << " " << ans << endl;
            } else {
                cout << 0 << " " << 0 << endl;
            }
        }
    }


}

signed main() {
    // IOS;
    init();
    // debug(1);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
