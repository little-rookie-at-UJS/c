#include "bits/stdc++.h"

using namespace std;



int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    //6
    //3 2 5 3 4 3
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    stack<pair<int, int>> st;
    for (int i = n; i; i--) {
        if (st.empty() || arr[i] < st.top().first) {
            st.emplace(arr[i], i);
        }
    }
    int now = 0;
    int cnt = 0;
    int ans = 0;
    while (!st.empty()) {
        auto [x, y] = st.top();
        st.pop();
        cnt += y - now;
        now = y;
//        cerr << cnt << " " << now << endl;
        ans += cnt / x;
        cnt %= x;
    }
    cout << ans << endl;
}