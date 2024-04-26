#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 20, S = 1 << N;
int n, q;
bool rev[N];
struct segment_tree
{
    int o[S << 2];
    void build(int l, int r, int rt)
    {
        if(l == r) { scanf("%lld", &o[rt]); return; }
        int mid = l + r >> 1;
        build(l, mid, rt << 1); build(mid + 1, r, rt << 1 | 1);
        o[rt] = o[rt << 1] + o[rt << 1 | 1];
    }
    void modify(int l, int r, int rt, int dep, int p, int v)
    {
        if(l == r) { o[rt] = v; return; }
        int mid = l + r >> 1;
        if(p <= mid) modify(l, mid, rt << 1 | rev[dep], dep - 1, p, v);
        else modify(mid + 1, r, rt << 1 | rev[dep] ^ 1, dep - 1, p, v);
        o[rt] = o[rt << 1] + o[rt << 1 | 1];
    }
    int query(int l, int r, int rt, int dep, int ql, int qr)
    {
        if(ql <= l && r <= qr) return o[rt];
        int mid = l + r >> 1, res = 0;
        if(ql <= mid) res += query(l, mid, rt << 1 | rev[dep], dep - 1, ql, qr);
        if(qr > mid) res += query(mid + 1, r, rt << 1 | rev[dep] ^ 1, dep - 1, ql, qr);
        return res;
    }
} sgt;
#define Replace(x, k) sgt.modify(1, 1 << n, 1, n, x, k)
#define Sum(l, r) sgt.query(1, 1 << n, 1, n, l, r)
#define Swap(k) rev[k + 1] ^= 1
inline void Reverse(int k) { for(int i = 0; i <= k; i++) rev[i] ^= 1; }
signed main()
{
    scanf("%lld %lld", &n, &q);
    sgt.build(1, 1 << n, 1);
    while(q--)
    {
        int opt, x, y;
        scanf("%lld", &opt);
        switch(opt)
        {
            case 1:
                scanf("%lld %lld", &x, &y); Replace(x, y); break;
            case 2:
                scanf("%lld", &x); Reverse(x); break;
            case 3:
                scanf("%lld", &x); Swap(x); break;
            case 4:
                scanf("%lld %lld", &x, &y); printf("%lld\n", Sum(x, y)); break;
        }
    }
    return 0;
}