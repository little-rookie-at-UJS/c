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

    void dfs(int p, int k) {
        if (k <= siz[p])return;
        k -= siz[p];
        for (auto [c, next]: st[p].next) {
            if (k > sums[next]) k -= sums[next];
            else {
                cout << c;
                dfs(next, k);
                return;
            }
        }
    }

    void query_kth(int k) {
        if (k <= sums[1])
            dfs(1, k);
        else cout << -1 << endl;
    }

    void bulid(int k = 0) {
        vector<int> cnt(tot + 1);
        for (int i = 1; i <= tot; i++) {
            cnt[st[i].len]++;
        }
        for (int i = 1; i < tot; i++) {
            cnt[i] += cnt[i - 1];
        }
        vector<int> order(tot + 1);
        for (int i = 1; i < tot; i++) {
            order[cnt[st[i].len]--] = i;
        }
        sums[1] = 0;
        for (int i = tot; i; i--) {
            int node = order[i];
            siz[st[node].link] += siz[node];
            if (!k) siz[node] = 1;
            sums[node] *= siz[node];
            for (auto [_, ne]: st[node].next) {
                sums[node] += sums[ne];
            }
        }
        siz[1] = 0;
    };

    string lcs(string &t) {
        int f = 0;
        int l = 0;
        int best = 0;
        int now = 1;
        for (int i = 0; i < t.size(); i++) {
            while (now != 1 && !(st[now].next.count(t[i]))) {
                now = st[now].link;
                l = st[now].len;
            }
            if (st[now].next.count(t[i])) {
                now = st[now].next[t[i]];
                l++;
            }
            if (l > best) {
                best = l;
                f = i;
            }
        }
        return t.substr(f - best + 1, best);
    }
};


void init() {
}


void solve() {
    string s1;
    cin >> s1;
    int n = s1.size();
    SAM sa(n);
    for (auto i: s1) {
        sa.insert(i);
    }
    string s2;
    cin >> s2;
    string s3 = sa.lcs(s2);
    debug(s3);
    cout << s3.size() << endl;
}

signed main() {
    // IOS;
    init();

    int t = 1;

    while (t--) {
        solve();
    }
}