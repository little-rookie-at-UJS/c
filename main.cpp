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
#define int ll
#define endl '\n'
using VI = vector<int>;
using VII = vector<VI>;
using PII = pair<int, int>;
const int mod = 1e9 + 7;

struct node {
    int link, len;
    map<char, int> next;

    node() {
        next.clear();
        link = len = 0;
    }
};

struct SAM {
    int las, tot;
    vector<node> st;
    int cnt = 0;
    vector<int> sums, siz;

    SAM(int n) {
        st.resize(2 * n + 10);
        sums.resize(2 * n + 10, 1);
        // len.resize(2 * n + 10, 0);
        siz.resize(2 * n + 10, 0);
        las = 1, tot = 2;
    }

    string getmin() {
        string s;
        int lass = 1;

        while (1) {
            if (st[lass].next.empty())return s;
            for (auto [i, j]: st[lass].next) {
                s.push_back(i);
                lass = j;
                break;
            }
        }
        return s;
    }

    void insert(char c) {
        int p = las;
        int newnode = tot++;
        siz[newnode] = 1;
        las = newnode;
        st[newnode].len = st[p].len + 1;
        while (p && !(st[p].next.count(c))) {
            st[p].next[c] = newnode;
            p = st[p].link;
        }
        if (!p) {
            st[newnode].link = 1;
        } else {
            int q = st[p].next[c];
            if (st[q].len == st[p].len + 1) {
                st[newnode].link = q;
            } else {
                int nq = tot++;
                st[nq] = st[q];
                st[nq].len = st[p].len + 1;
                while (p && st[p].next[c] == q) {
                    st[p].next[c] = nq;
                    p = st[p].link;
                }
                st[q].link = st[newnode].link = nq;
            }
        }
        cnt += st[las].len - st[st[las].link].len;
    }


};


void init() {
}


void solve() {
    string s;
    cin >> s;
    int n = s.length();
    s = " " + s + " ";
    SAM sam(s.length() + 3);
    vector<char> mins(s.length() + 3, 'z' + 1);
    for (int i = s.length() - 2; i; i--) {
        mins[i] = min(s[i], mins[i + 1]);
    };
    int las = n + 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] > mins[i])las = min(las, i);
    }
    string s1 = s.substr(1, las - 1);
    string s2 = s.substr(las, n + 2 - las);
    string s3 = s2;
    reverse(s3.begin(), s3.end());
    for (auto i: s3) {
        if (i != ' ') {
            sam.insert(i);
        }
    }

    string s4 = sam.getmin();
    string s5 = s2.substr(s4.size(), s2.size() - s4.size() - 1);
//    debug(s1, s4, s5);
    cout << s1 << s4 << s5 << endl;
}

signed main() {
    // IOS;
    init();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}

