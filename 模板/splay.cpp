struct SplayTree {
    int n;
    vector<int> val, fa, siz, cnt;
    vector<vector<int>> ch;
    int root, tot;

    explicit SplayTree(int _n = N) : n(_n) {
        val.resize(n + 1);
        fa.resize(n + 1);
        ch.resize(n + 1, vector<int>(2,0));
        siz.resize(n + 1);
        cnt.resize(n + 1);
        root = tot = 0;
    }


    void init(int _n) {
        n += 10;
        n = _n;
        val.resize(n + 1);
        fa.resize(n + 1);
        ch.resize(n + 1, vector<int>(2));
        siz.resize(n + 1);
        cnt.resize(n + 1);
        root = tot = 0;
    }

    void push_up(int x) {
//        debug(x)
//        debug(ch[x][0])
//        debug(ch[x][1])
//        debug( cnt[x])
        siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + cnt[x];
    }

    bool get(int x) {
        return x == ch[fa[x]][1];
    }

    void clear(int x) {
        ch[x][0] = ch[x][1] = fa[x] = val[x] = siz[x] = cnt[x] = 0;
    }

#define l(x) ch[x][0]
#define r(x) ch[x][1]
#define vl(x) val[l(x)]
#define vr(x) val[r(x)]

    void rotate(int x) {
        int y = fa[x];
        int z = fa[y];
        int k = get(x);
        ch[y][k] = ch[x][k ^ 1];
        if (ch[x][k ^ 1]) fa[ch[x][k ^ 1]] = y;
        ch[x][k ^ 1] = y;
        fa[y] = x;
        fa[x] = z;
        if (z) ch[z][y == ch[z][1]] = x;
        push_up(y);
        push_up(x);
    }

    void splay(int x) {
        for (int f = fa[x]; f = fa[x], f; rotate(x)) {
            if (fa[f])rotate(get(x) == get(f) ? f : x);
        }
        root = x;
    }

    void ins(int x, int k = 1) {
        if (!root) {
            val[++tot] = x;
            cnt[tot] += k;
            root = tot;
            push_up(root);
            return;
        }
        int now = root, f = 0;
        while (true) {
            if (val[now] == x) {
                cnt[now] += k;
                push_up(now);
                push_up(f);
                splay(now);
                break;
            }
            f = now;
            now = ch[now][val[now] < x];
//            debug(now)
            if (!now) {
                val[++tot] = x;
                cnt[tot] += k;
                fa[tot] = f;
                ch[f][val[f] < x] = tot;
                push_up(tot);
                push_up(f);
                splay(tot);
                break;
            }
        }
    }

    // 删除一个数
    void del(int x) {
        ins(x, -1);
        if (cnt[root] > 0) return;
        if (!l(root) && !r(root)) {
            clear(root);
            root = 0;
            return;
        }
        if (!l(root)) {
            int now = root;
            root = r(root);
            fa[root] = 0;
            clear(now);
            return;
        }
        if (!r(root)) {
            int now = root;
            root = l(root);
            fa[root] = 0;
            clear(now);
            return;
        }
        int now = root;
        int xx = l(root);
        xx = getmax(xx);
        fa[ch[now][1]] = xx;
        ch[xx][1] = ch[now][1];
        push_up(root);
        clear(now);
        splay(xx);
    }

    int getmin(int x) {
//        debug(x);
        while (l(x)) {
            debug(x);
            x = l(x);
        }
//        debug(x);
        splay(x);
        return x;

    }

    int getmax(int x) {
        while (r(x)) x = r(x);
        splay(x);
        return x;
    }


    int get_rank(int x) {
        ins(x);
        int ans = siz[l(root)] + 1;
        del(x);
        return ans;
    }

    int kth(int x) {
        int now = root;
        while (true) {
            if (l(now) && x <= siz[l(now)]) {
                now = l(now);
            } else {
                if (l(now)) x -= siz[l(now)];
                if (x <= cnt[now]) return now;
                x -= cnt[now];
                now = r(now);
            }
        }
    }

    int pre(int x) {
        ins(x);
        int ans = val[getmax(l(root))];
        del(x);
        return ans;
    }

    int nxt(int x) {
        ins(x);
        int ans = val[getmin(r(root))];
        del(x);
        return ans;
    }

#undef l
#undef r
#undef vl
#undef rl
};