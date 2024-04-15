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

template<typename T, typename _Compare = less<>>
struct MySet {
    priority_queue<T, vector<T>, _Compare> p{};
    priority_queue<T, vector<T>, _Compare> ep{};
    int sum;

    MySet() {
        sum = 0;
    }

    void insert(int x) {
        p.emplace(x);
        sum += x;
    }

    void erase(int x) {
        if (x == -1)return;
        ep.emplace(x);
        sum -= x;
    }

    bool empty() {
        return size() == 0;
    }

    int top() {
        while (!p.empty() && !ep.empty() && p.top() == ep.top()) {
            p.pop();
            ep.pop();
        }
        if (p.empty())return -1;
        return p.top();
    }

    void pop() {
        erase(p.top());
    }

    int size() {
        return p.size() - ep.size();
    }
};

template<typename T>
struct MidNum {
    MySet<T, greater<>> r{};
    MySet<T> l{};

    void adjust(int limit = inf) {
        while (r.size() > limit) {
            l.insert(r.top());
            r.pop();
        }
    }

    void insert(T x, int limit = inf) {
        if (l.empty() && r.empty()) {
            r.insert(x);
            return;
        } else {
            if (l.top() >= x) {
                l.insert(x);
                r.insert(l.top());
                l.pop();
            } else {
                r.insert(x);
            }
        }
        adjust(limit);
    }

    void erase(T x ) {
        if(!l.empty() && l.top() >= x){
            l.erase(x);
        }else{
            r.erase(x);
        }
//        while (!l.empty() && l.top() > x) {
//            r.insert(l.top());
//            l.pop();
//        }
//        while (!r.empty() && r.top() < x) {
//            l.insert(r.top());
//            r.pop();
//        }
//        if (l.top() == x) l.pop();
//        else r.pop();
    }

    int change(int x) {
        while (l.size() < x) {
            l.insert(r.top());
            r.pop();
        }
        while (l.size() > x) {
            r.insert(l.top());
            l.pop();
        }
        return l.sum;
    }

    int size() {
        return l.size() + r.size();
    }
};

void init() {
}


void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n + m + 1);
    vector<int> b(n + m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    // 1-n 值得是人 n+1 -m 是机器
    vector<int> fa(n + m + 1);
    vector<vector<MidNum<int>>> pq(m + 1, vector<MidNum<int>>(2));
    vector<int> last(m + 1, 0);
    vector<int> sizes(m + 1, 0);
    int sums = 0;
    for (int i = 1; i <= m; i++) {
        int l;
        cin >> l;
        sizes[i] = l / 2;
        vector<int> t;
        for (int j = 1; j <= l; j++) {
            int x;
            cin >> x;
            if (x < 0) {
                x = last[-x];
            }
            t.emplace_back(x);
            last[i] = max(last[i], x);
            pq[i][a[x]].insert(b[x], sizes[i]);
        }
        sort(t.begin(), t.end());
        for (int j = 0; j < t.size(); j++) {
            fa[t[j]] = i;
        }
        pq[i][a[last[i]]].erase(b[last[i]]);
        if (pq[i][0].size() < pq[i][1].size()) {
            sums += pq[i][1].change(pq[i][1].size() - sizes[i]);
        } else if (pq[i][0].size() > pq[i][1].size()) {
            sums += pq[i][0].change(pq[i][0].size() - sizes[i]);
        }

    }
    debug(sums);

    for (int i = 1; i <= q; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        int f = fa[x];
        if (last[f] != x) {
            if (pq[f][0].size() < pq[f][1].size()) {
                sums -= pq[f][1].change(pq[f][1].size() - sizes[f]);
            } else if (pq[f][0].size() > pq[f][1].size()) {
                sums -= pq[f][0].change(pq[f][0].size() - sizes[f]);
            }
            pq[f][a[x]].erase(b[x]);

            a[x] = y;
            b[x] = z;

            pq[f][a[x]].insert(b[x], sizes[f]);
            if (pq[f][0].size() < pq[f][1].size()) {
                sums += pq[f][1].change(pq[f][1].size() - sizes[f]);
            } else if (pq[f][0].size() > pq[f][1].size()) {
                sums += pq[f][0].change(pq[f][0].size() - sizes[f]);
            }
        }
        cout << sums << endl;
    }

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
// 3 1 5
// 0 2
// 1 3
// 0 2
// 3 1 2 3
// 2 0 3
// 2 0 3
// 2 1 3
// 1 1 1
// 3 1 1

// 9 4 9
// 0 1
// 1 2
// 0 3
// 1 4
// 0 5
// 1 6
// 0 7
// 1 8
// 0 9
// 3 1 3 2
// 3 6 4 5
// 3 9 8 7
// 3 -1 -2 -3
// 9 1 4
// 8 0 6
// 7 0 3
// 6 0 8
// 5 1 5
// 4 0 7
// 3 1 2
// 2 0 9
// 1 1 1