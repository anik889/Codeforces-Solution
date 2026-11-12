#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n; cin>>n;
    string s; cin>>s;
    vector<ll>v(26,0);
    for(int i=0;i<n;i++){
        ll x=min(s[i],s[n-i-1])-'a';
        ll y=max(s[i],s[n-i-1])-'a';
        for(int k=x+1;k<=y;k++)   v[k]++;
    }
    ll ans=0;
    for(int i=0;i<26;i++){
        if(v[i]>0)  ans++;
        else    continue;
    }
    cout<<ans<<endl;
}
int main(){
    int t=1; cin>>t;
    for(int i=0;i<t;i++)    solve();
}