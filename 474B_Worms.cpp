#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll bin(vector<ll>&a,ll n,ll t){
    ll lb=1,ub=n,mid,ans=n;
    while(lb<=ub){
        mid=lb+(ub-lb)/2;
        if(a[mid]>=t){
            ans=mid;
            ub=mid-1;
        }
        else    lb=mid+1;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++)     cin>>a[i];
    vector<ll>b(n+1,0);
    for(ll i=0;i<n;i++)      b[i+1]=b[i]+a[i];
    ll t; cin>>t;
    for(ll i=0;i<t;i++){
        ll k;cin>>k;
        cout<<bin(b,n+1,k)<<'\n';
    }
}