#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define irep(i,l,r) for(int i = l; i <= r; ++ i)
using namespace std;
#include "bits/stdc++.h"
const int N = 1000010;
#define drep(i,r,l) for(int i = r; i >= l; -- i)
//string s;

char s[N];
// key1[i] = rk[id[i]]（作为基数排序的第一关键字数组）
int n, sa[N], rk[N], oldrk[N << 1], id[N], key1[N], cnt[N];
int height[N];
bool cmp(int x, int y, int w) {
    return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];
}

void SA() {
    memset(sa, 0, sizeof sa);
    memset(rk, 0, sizeof rk);
    memset(oldrk, 0, sizeof oldrk);
    memset(id, 0, sizeof id);
    memset(key1, 0, sizeof key1);
    memset(cnt, 0, sizeof cnt);
//    memset(s, 0, sizeof s);

    int i, m = 127, p, w;
//    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (i = 1; i <= n; ++i) ++cnt[rk[i] = s[i]];
    for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (i = n; i >= 1; --i) sa[cnt[rk[i]]--] = i;

    for (w = 1;; w <<= 1, m = p) {  // m=p 就是优化计数排序值域
        for (p = 0, i = n; i > n - w; --i) id[++p] = i;
        for (i = 1; i <= n; ++i)
            if (sa[i] > w) id[++p] = sa[i] - w;

        memset(cnt, 0, sizeof(cnt));
        for (i = 1; i <= n; ++i) ++cnt[key1[i] = rk[id[i]]];
        // 注意这里px[i] != i，因为rk没有更新，是上一轮的排名数组

        for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
        for (i = n; i >= 1; --i) sa[cnt[key1[i]]--] = id[i];
        memcpy(oldrk + 1, rk + 1, n * sizeof(int));
        for (p = 0, i = 1; i <= n; ++i)
            rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
        if (p == n) {
            break;
        }
    }

//    for (i = 1; i <= n; ++i) printf("%d ", sa[i]);

    for (int i = 1, k = 0; i <= n; ++i) {
        if (rk[i] == 0) continue;
        if (k) --k;
        while (s[i + k] == s[sa[rk[i] - 1] + k]) ++k;
        height[rk[i]] = k;
    }
    irep(i, 1, n){
        s[i] = '\0';
    }
    return;
}

void solve(){
    string str;
    cin >> str;
    int m = str.length();
    vector<int>cc(26);
    irep(i, 0, m - 1){
        cc[str[i] - 'a'] ++;
    }
    char maxc = 'a';
    int pos = -1;
    irep(i, 0, m - 1){
        char ch = str[i];
        if(str[i] == maxc)
            cc[maxc - 'a'] --;
        else{
            int ok = 1;
            irep(j, maxc - 'a', ch - 'a' - 1){
                if(cc[j] != 0){
                    pos = i;
                    ok = 0;
                    break;
                }
            }
            if(ok == 0)break;
            maxc = ch;
            cc[maxc - 'a'] --;
        }
        //useit
        cout << ch;
    }
    string T = str, S;
    if(pos == -1){
        cout << '\n';
        return;
    }
    T.erase(T.begin(), T.begin() + pos);
    S = T;
    reverse(T.begin(), T.end());
    int tot = 1;
    for(auto c : T){
        s[tot ++] = c;
    }
//    for(int i = pos, L = 1; i < m; ++ i, ++ L){
//        s[L] = str[i];
//    }
    SA();

//    irep(i, 1, n){
//        cerr << sa[i] << ' ';
//    }
    int lstpos = 0;
//    irep(i, 1, n){
//        cout << sa[i] << ' ';
//    }
//    cout << endl;
//    irep(i, 1, n){
//        cout <<height[i] << ' ';
//    }
//    cout <<endl;

    irep(i, 1, n){
        if(height[i + 1] == n - sa[i] + 1){
            int l = lstpos + 1, r = sa[i];
            for(int p = l, q = r; p != r; ++ p, -- q){
                if(S[p] < S[q]){
                    irep(rs, 1, l - 1){
                        cout << T[i - 1];
                    }
                    irep(rs, l, n){
                        cout << S[rs - 1];
                    }
                    return;
                }
            }
            lstpos = r;
        }
        else{
//            cerr <<"non\n" << lstpos;
            int l = sa[i];
            irep(rs, l, n){
//                cerr << rs;
                cout << T[rs - 1];
            }

            drep(rs, l - 1, 1){
//                cerr << rs ;
                cout << T[rs - 1];
            }
            cout << '\n';
            return;
        }
    }

//        irep(i, 1, n){
//        cerr << sa[i] << ' ';
    }
//    int lstpos = 0;
//    irep(i, 1, n){
//        cout << sa[i] << ' ';
//    }
//    cout << endl;
//    irep(i, 1, n){
//        cout <<height[i] << ' ';
//    }
//    cout <<endl;

/*
 10
bbabbbabbb
baababbabb
bcccaacacb
babcccbcaa
cbcabbaaaa
 *
 */
int main(){
    int T;
    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}