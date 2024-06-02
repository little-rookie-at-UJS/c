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
//#define int ll

using VI = vector<int>;
using VII = vector<VI>;
using PII = pair<int, int>;
const int inf = 1e18;
const int mod = 1e9 + 7;


void init() {

}

//2 4
//ab
//#d
//ab 1
//a 2
//d 3
//bd 4
//2 4
struct node {
    array<int, 27> child;
    ll val;

    node() {
        ranges::fill(child, 0);
        val = 0;
    }

};


node tree[4000000];
char sss[100000];
int nows = 0;
int tot = 0;

void insert(string s, int k) {
    int now = 0;
    for (auto i: s) {
        if (!tree[now].child[i - 'a']) {
            tot++;
            tree[tot] = node();
            tree[now].child[i - 'a'] = tot;
        }
        now = tree[now].child[i - 'a'];
    }
    tree[now].val += k;
}

ll query() {
    int now = 0;
    int i = 0;
    while (i < nows) {
        if (!tree[now].child[sss[i] - 'a']) {
            tot++;
            tree[tot] = node();
            tree[now].child[sss[i] - 'a'] = tot;
        }
        now = tree[now].child[sss[i] - 'a'];
        i++;
    }
    return tree[now].val;
}


void solve() {


    tot = 0;
    tree[0] = node();
    int n, m;
    cin >> n >> m;
    vector<string> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    string s;
    int t;
    for (int i = 1; i <= m; i++) {
        cin >> s >> t;
        insert(s, t);
    }
    ll ans = 0;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        int now = 0;
        while (now < n) {
            if (arr[i][now] == '#') {
                now++;
                continue;
            }
//            string ss;
            nows = 0;
            while (now < n && arr[i][now] != '#') {
                sss[nows] = arr[i][now];
                nows++;
                now++;
            }
            debug(sss);
            ll aa = query();
//            debug(aa);
            if (aa == 0) {
                flag = false;
            }
            ans += aa;
//            now++;
        }
    }

    for (int j = 0; j < n; j++) {
        int i = 1;
        while (i <= n) {
            if (arr[i][j] == '#') {
                i++;
                continue;
            }
            nows = 0;
            while (i <= n && arr[i][j] != '#') {
                sss[nows++] = arr[i][j];
                i++;
            }
            ll aa = query();
            if (aa == 0) {
                flag = false;
            }
            ans += aa;
        }
    }
    if (flag) {
        cout << ans << endl;
    } else cout << -1 << endl;
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
