#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
    ll n,q;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++)    cin>>a[i];
    vector<ll>prefsort(n+1,0);
    vector<ll>prefunsort(n+1,0);
    for(int i=1;i<=n;i++){
        prefunsort[i]=prefunsort[i-1]+a[i-1];
    }
    sort(a.begin(),a.end());
    for(ll i=1;i<=n;i++){
        prefsort[i]=prefsort[i-1]+a[i-1];
    }
    cin>>q;
    for(int i=0;i<q;i++){
        ll x,l,r; cin>>x>>l>>r;
        if(x==1)        cout<<prefunsort[r]-prefunsort[l-1]<<endl;
        else    cout<<prefsort[r]-prefsort[l-1]<<endl;
    }
}
int main(){
    int t=1; //cin>>t;
    for(int i=0;i<t;i++)    solve();
}