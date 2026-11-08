#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s; cin>>s;
    int n=s.size();
    map<char,int>m;
    for(auto x:s)   m[x]++;
    if(m.size()==1)     cout<<0<<endl;
    else    cout<<2*(n-1)<<endl;
}
int main(){
    int t; cin>>t;
    for(int i=0;i<t;i++)    solve();
}