#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll x,y,k;
    cin>>x>>y>>k;
    ll g=gcd(x,y);
    if(max(x/g,y/g)<=k)  cout<<1<<endl;
    else    cout<<2<<endl;    
}
int main(){
    int t=1; cin>>t;
    for(int i=0;i<t;i++)    solve();
}   