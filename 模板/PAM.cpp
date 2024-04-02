
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

// PAM
struct node {
    int son[26], fail, flag, cnt, ans, in, len;
    char c;

    node() {
        memset(son, 0, sizeof son);
        fail = cnt = flag = ans = in = len = 0;
    }
};

int l = 0;

struct PAM {
    vector<node> tree;
    string s;
    int len = 0;
    int tot = 0;
    int last = 0;

// int ;
    PAM() {
        clear();
    }

    void clear() {
        tree.clear();
        tot = 0;
        last = 0;
        s = "#";
        createnode(0);
        createnode(-1);
        tree[0].fail = 1;
    }

    int getfail(int x) {
        tot = s.size() - 1;
        while (s[tot - tree[x].len - 1] != s[tot]) x = tree[x].fail;
        return x;
    }

// 创建节点
    int createnode(int len, char cc = '#') {
        node n = node();
        n.len = len;
        n.c = cc;
        tree.emplace_back(n);

        return tree.size() - 1;
    }

    void insert(char c) {
        s.push_back(c);
        debug(c);
        // 接着上次最后的结果查找回文
        int now = getfail(last);
        // 不存在
        if (!tree[now].son[c - 'a']) {
            int x = createnode(tree[now].len + 2, c);
            tree[x].fail = tree[getfail(tree[now].fail)].son[c - 'a'];
            tree[now].son[c - 'a'] = x;
            tree[x].ans = tree[tree[x].fail].ans + 1;
        }
        last = tree[now].son[c - 'a'];
        tree[last].cnt++;
        l = tree[last].ans;
        cout << l << " ";
    }
};


void solve() {
    PAM pam;
    string s;
    cin >> s;
    // s = change(s);
    // pam.input(s);
    for (auto i: s) {
        pam.insert((i + l - 97) % 26 + 97);
    }
    debug(1);
}


signed main() {
    IOS;
    init();
    // debug(1);
    int t = 1;
    // cin >> t;/**/
    while (t--) {
        solve();
    }
}
