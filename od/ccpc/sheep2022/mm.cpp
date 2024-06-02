#include<bits/stdc++.h>

using namespace std;

bool check(char lhs, char rhs) {
    return lhs == 'P' && rhs == 'S'
           || lhs == 'R' && rhs == 'P'
           || lhs == 'S' && rhs == 'R';
}

void solve() {
    string s;
    cin >> s;
    deque<char> st;
    for (auto c: s) {
        while (!st.empty() && !check(c, st.back()))st.pop_back();
        st.push_back(c);
    }
    cout << st.front() << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}