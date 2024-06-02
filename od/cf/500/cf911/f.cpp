#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout<<#x<<" " <<x<<endl;

struct node {
    vector<string> v;
    //map<int,int> child;
    vector<int> child;

    node() {
        child.resize(30);
    }
};

struct trie {

    vector<node> tree;
    int tot;

    trie() {
        int sizes = 5e5;
        tree.resize(sizes);
        tot = 1;
    }

    void add(string &s, vector<char> &pre) {
        int now = 1;
        for (auto i: pre) {
            int nex = i - 'a';
            if (!(tree[now].child[nex])) {
                tree[now].child[nex] = ++tot;
            }
            now = tree[now].child[nex];

        }

        tree[now].v.emplace_back(s);
    }

    vector<string> querry(vector<char> &pre) {
        int now = 1;
        for (auto i: pre) {
            int nex = i - 'a';
            if (!(tree[now].child[nex])) {
                vector<string> v;
                return v;
            }
            now = tree[now].child[nex];
        }
        return tree[now].v;
    }
};


int main() {
    trie t;
//    int n;
//    cin>>n;
//
//    getchar();
//    for(int i = 1;i<=n;i++){
//        string s;
//        getline(cin,s);
//
//        vector<char> arr;
//        arr.emplace_back(s[0]);
//        for(int i = 1;i<s.size();i++){
//            if(s[i-1]==' '&&s[i]!=' '){
//                 arr.emplace_back(s[i]);
//
//            }
//        }
//
//        t.add(s,arr);
//    }
//    int q;
//    cin>>q;
//    getchar();
//    for(int i = 1;i<=q;i++){
//        string s;
//        getline(cin,s);
//
//        vector<char> arr;
//        arr.emplace_back(s[0]);
//
//        for(int i = 1;i<s.size();i++){
//            if(s[i-1]==' '&&s[i]!=' '){
//                 arr.emplace_back(s[i]);
//
//            }
//        }
//
//        vector<string>ans = t.querry(arr);
//        if(ans.size()==0){
//            cout<<s<<endl;
//        }else{
//            sort(ans.begin(),ans.end());
//            int a = ans.size();
//            for(int i=0;i<a-1;i++){
//                cout<<ans[i]<<"|";
//            }
//            cout<<ans[a-1]<<endl;
//        }
//    }


    return 0;
}
