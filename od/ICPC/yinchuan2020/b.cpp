#include "bits/stdc++.h"

using namespace std;

#define endl "\n"
#define debug(x)  cerr <<#x<<" "<<x<<endl;
using ll = long long;

//#define int ll
struct node {
    int len;
    vector<int> arr;

    vector<int> premin, premax, sufmin, sufmax;

    node(int n) : len(n), arr(n + 1), premax(n + 1), premin(n + 1), sufmax(n + 1), sufmin(n + 1) {
    }
};

pair<int, int> check(node n) {
    int maxs = -1e9 - 100;
    int len = 0;
    if (n.len == 1) {
        return make_pair(maxs, 0);
    }
    int lens = n.len;

    int valueall = n.premax[lens] - n.premin[lens];
    for (int i = 1; i < lens; i++) {
        int left = n.premax[i] - n.premin[i];
        int right = n.sufmax[i + 1] - n.sufmin[i + 1];
        if (left + right - valueall > maxs) {
            maxs = left + right - valueall;
            len = i;
        }
    }
    return make_pair(maxs, len);
};

node getnode(vector<int> &v) {
    int len = v.size();
    len--;
    node n(len);
    for (int i = 1; i <= len; i++) {
        n.arr[i] = v[i];
    }
    for (int i = 1; i <= len; i++) {
        if (i == 1) {
            n.premax[1] = n.premin[1] = v[1];
        } else {
            n.premax[i] = max(n.premax[i - 1], v[i]);
            n.premin[i] = min(n.premin[i - 1], v[i]);
        }
    }
    for (int i = len; i; i--) {
        if (i == len) {
            n.sufmax[i] = n.sufmin[i] = v[i];
        } else {
            n.sufmax[i] = max(n.sufmax[i + 1], v[i]);
            n.sufmin[i] = min(n.sufmin[i + 1], v[i]);
        }
    }
    return n;
}

pair<node, node> spilt(int i, node &n) {
    vector<int> l, r;
    vector<int> v = n.arr;
    l.emplace_back(0);
    r.emplace_back(0);
    for (int j = 1; j <= i; j++) {
        l.emplace_back(v[j]);
    }
    for (int j = i + 1; j < v.size(); j++) {
        r.emplace_back(v[j]);
    }
    node ll = getnode(l), rr = getnode(r);
    return make_pair(ll, rr);
}

void getvalue(vector<node> &v) {
    int sums = 0;
    for (auto i: v) {
        int len = i.len;
        sums += i.premax[len] - i.premin[len];
    }
    cout << sums << endl;
}

// 5
// 1 2 3 4 5
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)cin >> arr[i];
    vector<node> v;
    node nn = getnode(arr);
    v.emplace_back(nn);
    for (int i = 1; i < n; i++) {
        getvalue(v);
//        debug(i);
        int maxs = -1e9 - 100;
        int len1 = 0;
        int len2 = 0;
        for (int j = 0; j < v.size(); j++) {
//            debug(j);
            auto [kk, kkk] = check(v[j]);
            if (kk > maxs) {
                maxs = kk;
                len1 = j;
                len2 = kkk;
            }
        }
//        debug(i);
        vector<node> mir;

        for (int j = 0; j < len1; j++) {
            mir.emplace_back(v[j]);
        }
//        debug(i);
        auto [l, r] = spilt(len2, v[len1]);
        mir.emplace_back(l);
        mir.emplace_back(r);
        for (int j = len1 + 1; j < v.size(); j++) {
            mir.emplace_back(v[j]);
        }
        v = mir;
//        debug(i);
    }
    getvalue(v);

}