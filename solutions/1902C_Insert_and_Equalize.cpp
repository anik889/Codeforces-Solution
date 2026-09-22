#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n; cin>>n;
    vector<ll>a(n);
    ll sum=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a.begin(),a.end());
    ll m=a[n-1];
    ll x=m-a[0];
    for(ll i=1;i<n;i++)    x=gcd(x,m-a[i]);
    if(n==1){
        cout<<1<<endl;
        return;
    }
    if(x==0){
        cout<<1<<endl;
        return;
    }
    ll ans=((m*n)-sum)/x;
    ll k=m-x,l=0;
    for(ll i=n-2;i>=0;i--){
        if(a[i]==k)     k=k-x;
        else if(a[i]<k)   break;
    }
 
    cout<<ans+((m-k)/x)<<endl;
}
int main(){
    int t; cin>>t; 
    for(int i=0;i<t;i++)    solve();
}