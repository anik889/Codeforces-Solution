#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
    ll n,k; cin>>n>>k;
    vector<ll>a(k);
    for(int i=0;i<k;i++)        
        cin>>a[i];
    vector<ll>s;
    for(int i=1;i<k;i++){
        s.push_back(a[i]-a[i-1]);
    }
    if(!is_sorted(s.begin(),s.end())){
        cout<<"NO\n";
        return;
    }    
    if(k==1){
        cout<<"YES\n";
        return;
    }
    ll x=(a[1]-a[0])*(n-k+1);
    if(x>=a[0])      cout<<"YES\n";
    else    cout<<"NO\n";
}
int main(){
    int t; cin>>t;
    for(int i=0;i<t;i++)    solve();
}