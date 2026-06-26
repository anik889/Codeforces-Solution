#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll bin(vector<ll>&a,ll n,ll t){
    ll lb=0,ub=n-1,mid,ans=n;
    while(lb<=ub){
        mid=lb+(ub-lb)/2;
        if(a[mid]>t){
            ans=mid;
            ub=mid-1;
        }
        else    lb=mid+1;
    }
    return ans;
}
void solve(){
    ll n; cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll q; cin>>q;
    for(ll i=0;i<q;i++){
        ll k;  cin>>k;
        ll j=bin(a,n,k);
        cout<<j<<endl;
    }
 
}
int main(){
    solve();   
}