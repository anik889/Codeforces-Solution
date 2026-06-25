#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll bin(vector<ll>&a,ll t){
    ll n=a.size();
    ll lb=0,ub=n-1,mid,dis=n;
    while(lb<=ub){
        mid=lb+(ub-lb)/2;
        if(a[mid]>t){
            dis=mid;
            ub=mid-1;    
        } else 
            lb=mid+1;
    }
    return dis;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    vector<ll>b(m);
    for(ll i=0;i<m;i++) cin>>b[i];
    for(ll i=0;i<m;i++){
        cout<<bin(a,b[i])<<' ';
    }
 
}
int main(){
    solve();   
}