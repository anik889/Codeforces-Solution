#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n; cin>>n;
    string s; cin>>s;
    ll one=count(s.begin(),s.end(),'1');
    ll zero=count(s.begin(),s.end(),'0');
    if(s[0]=='1'){
        cout<<zero<<endl; return;
    }
    ll res=min(one,zero);
    ll co=0,cz=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1')   co++;
        cz=(i+1)-co;
        res=min(res,(zero-cz+co));
    }
    cout<<res<<endl;
}
int main() {
    ll t; cin>>t;
    for(ll i=0;i<t;i++)     solve();
}