#include<bits/stdc++.h>
using namespace std;
#define ll long long 
bool check(ll n, ll k, ll size, vector<ll>&a,vector<ll>&b){
    for(int i=0;i<=n-size;i++){
        ll lb=i, rb=i+size-1;
        if(b[lb+1]>=rb+1){
            if(a[rb+1]-a[lb-1+1] <=k) return true;
        }
    }    
    return false;
}
void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n), h(n);
    for(int i=0;i<n;i++)    cin>>a[i];
    for(int i=0;i<n;i++)    cin>>h[i];
    vector<ll>pref(n+1,0);
    for(int i=1;i<=n;i++)  pref[i]=pref[i-1]+a[i-1];
    vector<ll>len(n+1);
    len[n]=n;
    for(int i=n-1;i>=1;i--){
        if(h[i-1]%h[i]==0)   len[i]=len[i+1];
        else    len[i]=i;
    }
    ll l=1,r=n,mid, ans=0;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(n,k,mid,pref,len)){
            ans=mid;
            l=mid+1;
        }
        else    r=mid-1;
    }
    cout<<ans<<endl;
}
int main(){
    int t; cin>>t;
    for(int i=0;i<t;i++)    solve();
}