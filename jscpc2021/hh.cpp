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
    int end;
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

    vector<string> getmin() {
        vector<string> list;
        string s;
        int lass = 1;
        while (1) {
            if (st[lass].next.empty())break;
            for (auto [i, j]: st[lass].next) {
                if (st[lass].next.count('z' + 1)) {
                    list.push_back(s);
                    s = "";
                }
                s.push_back(i);
                lass = j;
                break;
            }
        }
        return list;
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

using sv = string_view;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<char> mins(n);
    for (int i = 0; i < n; i++) {
        mins[i] = s[i];
    }
    for (int i = n - 2; i >= 0; i--) {
        mins[i] = min(mins[i + 1], mins[i]);
    }
    int las = n - 1;
    for (int i = 0; i < n; i++) {
        if (s[i] > mins[i])las = min(las, i);
    }
    sv pre(s.begin(), s.begin() + las);
    sv back(s.begin() + las, s.end());
    cerr << pre << endl;
    string s2 = s.substr(las, s.size() - las + 1);
    debug(s2);
    reverse(s2.begin(), s2.end());
//    string s;
//    cin >> s;
//    int n = s.length();
//    s = " " + s + " ";
//    string_view ss(s);
//    SAM sam(s.length() + 3);
//    vector<char> mins(s.length() + 3, 'z' + 1);
//    for (int i = s.length() - 2; i; i--) {
//        mins[i] = min(s[i], mins[i + 1]);
//    };
//    int las = n + 1;
//    for (int i = 1; i <= n; i++) {
//        if (s[i] > mins[i])las = min(las, i);
//    }
//    string_view s1 = ss.substr(1, las - 1);
//    string s2 = s.substr(las, n + 2 - las);
//
//    string s3 = s2;
//    reverse(s3.begin(), s3.end());
//
//
//    for (auto i: s3) {
//        if (i != ' ') {
//            sam.insert(i);
//        }
//    }
//    sam.insert('z' + 1);
//    vector<string> backs = sam.getmin();
//    string ss = s2.substr(0, s2.length() - 1);
//    s2 = ss;
//    string res = s1;
//    for (auto i: backs) {
//        string s5 = s2.substr(0, i.length());
//        string s6 = s2.substr(i.length(), s2.length() - s5.size() + 1);
//        if (i <= s5) {
//            res += i;
//        } else {
//            res += s2;
//            cout << res << endl;
//            return;
//        }
//        s2 = s6;
//    }
//
//    res += s2;
//    cout << res << endl;
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

//aaaaabbbaabbbbbbbbabaaaabbaabababbaaabaaabaababbbb
//aaaaabbabbbbbbbbaabbbaaaabaabababbaaabaaabaababbbb
//aaaaabbabbbbbbbbaabbbaaaabaabababbaaabaaabaababbbb