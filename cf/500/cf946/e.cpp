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

void init() {
}

//4 5
//1 3 4
//1 2 5
//5 6 1
//1 2 4
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if (s.size() % 2 == 0) {
        // 将最低位变成小于他的可能最大的数
        array<int, 10> a;
        a.fill(0);
        for (auto i: s) {
            a[i - '0']++;
        }
        std::reverse(s.begin(), s.end());
        // 对于最低位，我们尝试每一个比他小的数
        auto check = [&](int x) {
            stack<int> st;
            for (int i = 0; i < 10; i++) {
                if (a[i] % 2) {
                    st.push(i);
                }
            }
            while (st.size() < x) {
                st.emplace(9);
            }
            if (st.size() > x) return false;
            while (!st.empty()) {
                auto i = st.top();
                st.pop();
                s[st.size()] = i + '0';
            }
            return true;
        };
        for (int i = 0; i < n; i++) {
            char c = s[i];
            for (char j = c - 1; j >= '0'; j--) {
                if (i == n - 1 && j == '0')continue;
                s[i] = j;
                a[c - '0']--;
                a[j - '0']++;
                if (check(i)) {
                    reverse(s.begin(), s.end());
                    cout << s << endl;
                    return;
                }
                a[c - '0']++;
                a[j - '0']--;
                s[i] = c;
            }
            a[c - '0']--;
        }
    }
    n -= 1;
    n = (n / 2) * 2;
    if (n == 0) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << 9;
    }
    cout << endl;

}

signed main() {
    IOS;
    init();
    // debug(1);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
