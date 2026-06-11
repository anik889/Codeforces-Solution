#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<string,int>mp;
    vector<string>ss;
    for(int i=0;i<=n-2;i++){
        mp[s.substr(i,2)]++;
    }
    for(auto p:mp){
        ss.push_back(p.first);
    }
    cout<<ss.size()<<endl;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)    solve();
}
