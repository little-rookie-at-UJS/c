//
// Created by DELLPC on 24-4-28.
//
#include <iostream>
#include <vector>
using namespace std;
void solve(){
    int n=0;
    cin>>n;
    string a;
    vector<int> first(n);
    vector<int> second(n);
    for(auto &i:first){
        cin>>a;
        i=(a[a.size()-1]-'0')/3;
        //cout<<i<<" ";
    }
    //cout<<endl;
    for(auto &i:second){
        cin>>a;
        i=(a[a.size()-1]-'0')/3;
//cout<<i<<" ";
    }
    //cout<<endl;
    if(!first[n-1]){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(first[i]==second[i]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}