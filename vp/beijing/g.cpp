//
// Created by DELLPC on 24-5-19.
//
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using i32 = unsigned int;


i32 ask(int x) {
    cout << "? " << x << endl;
    i32 res;
    cin >> res;
    return res;
}

void anw(int x) {
    cout << "! " << x << endl;
}


class Tired {
private:
    struct Node {
//        int l, r;
        int pre;
        int id;
        int ch[2];
        int val;

        Node() : pre(0), id(0), val(0) {
            ch[0] = ch[1] = 0;
        }
    };

    vector<Node> tree;
    vector<int> a;
    vector<Node *> v;
    int tot = 0;
    int ans = 0;

    void insert(int x, int id) {
        int p = 0;
        int pre = 0;
        for (int i = 30; i >= 0; i--) {
            int c = (x >> i) & 1;
//            cerr << "c: " << c << endl;
            pre |= (c << i);
//            cerr << "pre: " << pre << endl;
            if (!tree[p].ch[c]) {
                tree[p].ch[c] = ++tot;
                tree[tot].pre = pre;
            }
            if (tree[p].ch[0] && tree[p].ch[1]) {
                if (!v[i]) {
                    v[i] = &tree[p];
                }
            }


            p = tree[p].ch[c];
        }
        tree[p].id = id;
        tree[p].val = x;

    }


    pair<int, int> getmax(int x, int i) {

        if (i < 0) {
            return {tree[x].id, x};
        }

        if (tree[x].ch[!(1 & (ans >> i))]) {
            return getmax(tree[x].ch[!(1 & (ans >> i))], i - 1);
        } else {
            return getmax(tree[x].ch[ (1 & (ans >> i))], i - 1);
        }
    }

public:
    Tired(int n, vector<int> &aa) : tree(n * 31 + 10), a(aa), v(31) {
        for (int i = 1; i <= n; i++) {
//            cerr << "a[i]      " << bitset<32>(a[i]) << endl;
            insert(a[i], i);
        }
    }

    void run() {
//        cerr << bitset<32>(271581184) << endl;
        ans = 0;
        for (int i = 0; i <= 30; i++) {
            if (v[i]) {
                auto [len, x] = getmax(v[i]->ch[0], i - 1);
//                cerr << i << endl;
                int ans1 = ask(len);
//                cerr << "ans1: " << ans1 << endl;
//                cerr << "pre       " << bitset<32>(v[i]->pre) << endl;
//                cerr << "a[len]    " << bitset<32>(a[len]) << endl;
//                cerr << "a[ans1]   " << bitset<32>(a[ans1]) << endl;
//                cerr << "^         " << bitset<32>((a[ans1] ^ v[i]->pre)) << endl;
//                cerr << "1         " << bitset<32>((1 << (i + 1))) << endl;
//                cerr << v[i]->val << endl;
                if (ans1 == -1 || (a[ans1] ^ v[i]->pre) >= (1 << (i + 1))) {
                    ans |= 1 << i;
                }
//                cerr << "ans:      " << bitset<32>(ans) << endl;
//                cerr << "271581184 " << bitset<32>(271581184) << endl << endl;
//

            }
        }
        anw(ans);

    };
//00010000001100000000000000000000
//00000000000100000000000000000000
};

int main() {

    i64 n, m;

    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
//    sort(a.begin(), a.end(), greater<>());
    Tired t(n, a);
    while (m--) {
        t.run();
    }
// 5 1
// 1 2 3 4 5

}

