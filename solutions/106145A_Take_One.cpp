#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n,c,k;
    cin>>n>>c>>k;
    vector<ll>a(n);
    for(int i=0;i<n;i++)    cin>>a[i];
    ll count=1;
    vector<ll>counting;
    for(int i=1;i<=n;i++){
        if(i<n && a[i]==a[i-1])    count++;
        else{
            if(a[i-1]==1){
                ll x=count/c;
                ll y=count%c;
                for(int j=0;j<x;j++)    counting.push_back(c) ;
                counting.push_back(y) ;
            }
            count=1;
        }
    }
    ll ans=0;
    ll s=min(k,(long long)counting.size());
    sort(counting.rbegin(),counting.rend());
    for(int i=0;i<s;i++){
        ans+=(counting[i]);
    }
    cout<<ans<<endl;
}
int main(){
    int t=1;
    // cin>>t;
    for(int i=0;i<t;i++)    solve();
    return 0;
}