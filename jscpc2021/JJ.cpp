//
// Created by DELLPC on 24-4-28.
//
#include<bits/stdc++.h>

using namespace std;

#define irep(i, l, r) for(int i = l; i <= r; ++ i)
#define drep(i, r, l) for(int i = r; i >= l; -- i)

#define ll long long
#define LD double
const int mod = 1000000000 + 7;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>>a(n, vector<int>(m));
    irep(i, 0, n - 1){
        irep(j, 0, m - 1){
            cin >> a[i][j];
        }
    }
    vector<array<int, 2>>ans;
    int num;
    vector<array<int, 2>>D = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    vector<vector<int>>vis(n, vector<int>(m));
    vector<vector<array<int, 2>>>tp(2);
    function<void(int, int)> dfs = [&](int x, int y){
        tp[(x + y) % 2].push_back({x, y});
        vis[x][y] = 1;
        for(auto [dx, dy] : D){
            if(x + dx >= n || x + dx < 0 || y + dy >= m ||  y + dy < 0 || vis[x + dx][y + dy] || a[x + dx][y + dy] != num)
                continue;
            dfs(x + dx, y + dy);
        }
    };
    irep(i, 0, n - 1){
        irep(j, 0, m - 1){
            if(!vis[i][j]){
                num = a[i][j];
                dfs(i, j);
                if(tp[0].size() > tp[1].size()){
                    swap(tp[0], tp[1]);
                }
                while(tp[0].size()){
                    ans.push_back(tp[0].back());
                    tp[0].pop_back();
                }
                tp[0].clear();
                tp[1].clear();
            }
        }
    }
    if(ans.size() == 0){
        cout << "0 0";
    }
    else{
        cout << "1 " << ans.size() << '\n';
        for(auto [x, y] : ans){
            cout << x + 1 <<' ' << y + 1 << " 1\n";
        }
    }
    return;
}

int main(){
    int T = 1;
    solve();
    return 0;
}