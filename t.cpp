#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
#define For(i, x, y, ...) for(int i=x,##__VA_ARGS__;i<=y;++i)
#define rFor(i, x, y, ...) for(int i=x,##__VA_ARGS__;i>=y;--i)
#define Rep(i, x, y, ...) for(int i=x,##__VA_ARGS__;i!=y;++i)
#define mem(a, x, n) memset(a,x,sizeof(a[0])*(n+1))
#define all(a) a.begin(),a.end()
#define MT make_tuple
#define pb emplace_back
#define MP make_pair
#define fi first
#define se second
#define priority_queue __gnu_pbds::priority_queue
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef vector<int> VI;
char buf[1 << 22], *p1 = buf, *p2 = buf, pbuf[1 << 22], *pp = pbuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<22,stdin),p1==p2)?EOF:*p1++)
#define ocl() fwrite(pbuf,1,pp-pbuf,stdout),pp=pbuf,0
#define putchar(x) pp-pbuf==1<<22&&(ocl()),*pp++=x

template<typename T>
void read(T &x) {
    x = 0;
    bool f = 1;
    char c;
    while (!isdigit(c = getchar()))if (c == '-')f = 0;
    if (f)for (; isdigit(c); c = getchar())x = x * 10 + c - 48;
    else for (; isdigit(c); c = getchar())x = x * 10 - c + 48;
    if (c == '.')for (T i = f ? 10 : -10; isdigit(c = getchar()); i *= 10)x += (c ^ 48) / i;
}

template<typename T, typename ...Args>
void read(T &x, Args &...args) { read(x), read(args...); }

template<typename T>
void write(T x, char y = 10) {
    if (!x)putchar(48);
    else {
        static int s[44];
        int l = 0;
        if (x < 0)putchar('-'), x = -x;
        for (; x; x /= 10)s[l++] = x % 10;
        while (l)putchar(s[--l] | 48);
    }
    putchar(y);
}

template<typename X, typename Y>
void ckmax(X &x, Y y) { if (x < y) x = y; }

template<typename X, typename Y>
void ckmin(X &x, Y y) { if (y < x) x = y; }

char readc() {
    char c;
    while (!isupper(c = getchar()));
    return c;
}

const int N = 2e5 + 5;
int n, m;

struct Graph {
    int ind, scc, ans, dfn[N], low[N], in[N];
    bool vis[N];
    VI sol, e[N], id[N];
    int tp, stk[N];

    void adde(int x, int y) { e[x].pb(y), e[y].pb(x); }

    void tarjan(int u) {
        dfn[u] = low[u] = ++ind, stk[++tp] = u, in[u] = -1;
        for (int v: e[u])
            if (!in[v]) tarjan(v), ckmin(low[u], low[v]);
            else if (in[v] == -1) ckmin(low[u], dfn[v]);
        if (dfn[u] == low[u]) {
            ++scc;
            int t;
            do {
                t = stk[tp--], in[t] = scc;
                if (t > n) id[scc].pb(t - n);
            } while (t != u);
        }
    }

    void main() {
        For(i, 1, n * 2) if (!dfn[i]) tarjan(i);
        For(i, 1, n) if (in[i] == in[i + n]) return ans = N, void();
        For(i, 1, n) if (!vis[in[i]]) {
                vis[in[i]] = vis[in[i + n]] = 1;
                if (id[in[i]].size() < id[in[i + n]].size())
                    ans += id[in[i]].size(), sol.insert(sol.end(), all(id[in[i]]));
                else ans += id[in[i + n]].size(), sol.insert(sol.end(), all(id[in[i + n]]));
            }
    }
} g[2];

signed main() {
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
    read(n, m);
    For(i, 1, m, x, y) {
        read(x, y);
        bool k = readc() == 'B';
        g[k].adde(x, y), g[k].adde(x + n, y + n);
        g[!k].adde(x, y + n), g[!k].adde(x + n, y);
    }
    g[0].main(), g[1].main();
    bool k = g[1].ans < g[0].ans;
    if (g[k].ans == N) return puts("-1"), 0;
    write(g[k].ans);
    for (int i: g[k].sol) write(i, ' ');
    return ocl();
}