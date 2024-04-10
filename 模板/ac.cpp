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

class AC {
private:
    struct node {
        vector<int> son;
        // fail 指向的节点 , flag 映射的字符串编号 , 出现的次数 , ans 该节点的答案 , in 该节点的入度
        int fail, flag, cnt, ans, in;

        node() {
            fail = cnt = flag = ans = in = 0;
            son = vector<int>(26, 0);
        }

        int &operator[](int c) {
            if (c <= 'z' && c >= 'a') {
                c -= 'a';
            } else if (c <= 'Z' && c >= 'A') {
                c -= 'A';
            }
            return son[c];
        }

    };

    vector<node> tree;
    int tot, size;
    map<int, int> mp;
    map<int, int> ans;

    void init() {
        tree = vector<node>(10, node());
        tot = 1;
        size = 3;
        mp.clear();
    }

    //扩展空间
    void extend() {
        tree.resize(size * 2, node());
        size *= 2;
    }

    void clear() {
        for (int i = 0; i < tot; i++) {
            tree[i] = node();
        }
        tot = 1;
    }

public:
    AC() {
        init();
        clear();
    }

    void build() {
        for (int i = 0; i < 26; i++) {
            tree[0][i] = 1;
        }
        queue<int> q;
        q.emplace(1);
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            int fail = tree[now].fail;
            for (int i = 0; i < 26; i++) {
                if (tree[now][i]) {
                    tree[tree[now][i]].fail = tree[fail][i];
                    q.push(tree[now][i]);
                } else {
                    tree[now][i] = tree[fail][i];
                }
            }
        }
    }

    void insert(string &s, int id) {
        int now = 1;
        for (auto i: s) {
            if (!tree[now][i]) {
                ++tot;
                if (tot == size) {
                    extend();
                }
                tree[now][i] = tot;
            }
            now = tree[now][i];
        }
        tree[now].cnt++;
        if (!tree[now].flag) {
            tree[now].flag = id;
        }
        mp[id] = tree[now].flag;
    }

    void dfs() {
        queue<int> q;
        for (int i = 1; i <= tot; i++) {
            tree[tree[i].fail].in++;
        }
        for (int i = 1; i <= tot; i++) {
            if (!tree[i].in) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            tree[tree[now].fail].ans += tree[now].ans;
            ans[tree[now].flag] = tree[now].ans;
            if (--tree[tree[now].fail].in == 0) {
                q.push(tree[now].fail);
            }
        }
    }

    void query(string &s) {
        int now = 1;
        for (auto i: s) {
            now = tree[now][i];
            tree[now].ans++;
        }
    }

    void action() {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            insert(s, i);
        }
        build();
        string s;
        cin >> s;
        query(s);
        dfs();
//        debug("\n",tree);
        for (int i = 1; i <= n; i++) {
            cout << ans[mp[i]] << endl;
        }

    }
};


void init() {
}


void solve() {
    AC ac;
    ac.action();

}

signed main() {
    IOS;
    init();
    // debug(1);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}
