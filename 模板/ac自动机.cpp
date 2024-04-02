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

// ac ？
struct node {
    int son[26], fail, flag, cnt, ans, in;

    node() {
        memset(son, 0, sizeof son);
        fail = cnt = flag = ans = in = 0;
    }
};

const int maxn = 2e5 + 10;

struct AC {
    vector<node> tree;
    vector<string> s;
    vector<int> mp;
    int tot;
    // queue<int>
    AC() {
        tree = vector<node>(maxn, node());
        s = vector<string>(maxn);
        mp = vector<int>(maxn);
        tot = 1;
    }

    AC(int n) {
        tree = vector<node>(maxn, node());
        s = vector<string>(n + 1);
        mp = vector<int>(n + 1);
        tot = 1;
    }

    void input(int n) {
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            insert(i);
        }
    }

    void insert(int n) {
        int now = 1;
        for (auto i: s[n]) {
            int v = i - 'a';
            if (!tree[now].son[v]) {
                tree[now].son[v] = ++tot;
            }
            now = tree[now].son[v];
            tree[now].cnt++;
        }
        if (!tree[now].flag) {
            tree[now].flag = n;
        }
        mp[n] = tree[now].flag;
    }

    void build() {
        // memset(tree[0].son, 1, sizeof tree[0].son);
        for (int i = 0; i < 26; i++) {
            tree[0].son[i] = 1;
        }
        queue<int> q;
        q.emplace(1);
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            int ff = tree[f].fail;
            for (int i = 0; i < 26; i++) {
                int next = tree[f].son[i];
                if (!next) {
                    tree[f].son[i] = tree[ff].son[i];
                }
                else {
                    tree[next].fail = tree[ff].son[i];
                    tree[tree[next].fail].in++;
                    q.emplace(next);
                }
            }
        }
    }

    void query() {
        string s;
        cin >> s;
        int u = 1;
        for (auto i: s) {
            u = tree[u].son[i - 'a'];
            tree[u].ans++;
        }
    }

    void tp(int n) {
        vector<int> ans(n + 1);
        queue<int> q;
        for (int i = 1; i <= tot; i++) {
            if (tree[i].in == 0) q.emplace(i);
        }
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            ans[tree[f].flag] = tree[f].ans;
            int ff = tree[f].fail;
            tree[ff].in--;
            tree[ff].ans += tree[f].ans;
            if (tree[ff].in == 0) {
                q.emplace(ff);
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[mp[i]] << endl;
        }
    }

    void clear() {
        for (int i = 0; i <= tot; i++) {
            tree[i] = node();
        }
        tot = 1;
    }

    void run() {
        int n;
        cin >> n;
        input(n);
        debug(mp);
        build();
        query();
        tp(n);
        // clear();
    }
};

AC ac;

void solve() {
    // AC a(10);
    ac.run();
    // for (int i = 1; i < 101; i++)cout << i << endl;
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