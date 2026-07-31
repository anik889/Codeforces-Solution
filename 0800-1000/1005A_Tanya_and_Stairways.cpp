#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    vector<ll>v;
    for(ll i=0;i<n;i++)     cin>>a[i];
    ll count=1;
    for(ll i=0;i<n-1;i++){
        if(a[i]>=a[i+1]){    
            count++; 
            v.push_back(a[i]);
        }
        else continue;
    }
    v.push_back(a[n-1]);
    cout<<count<<'\n';
    for(auto x:v)    cout<<x<<' ';
    cout<<'\n';
}
int main(){
    ll t=1;
    //cin>>t;
    for(ll i=0;i<t;i++)     solve();
}
