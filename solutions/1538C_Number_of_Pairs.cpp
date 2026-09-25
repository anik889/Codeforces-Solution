#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
    ll n,l,r; cin>>n>>l>>r;
    vector<ll>a(n);
    for(int i=0;i<n;i++)    cin>>a[i];
    sort(a.begin(),a.end());
    ll ans=0;
    for(int i=0;i<n;i++){
        auto lb=lower_bound(a.begin()+i+1,a.end(),l-a[i]);
        auto ub=upper_bound(a.begin()+i+1,a.end(),r-a[i]);
        ans=ans+(ub-lb);
    }
    cout<<ans<<endl;
 
}
int main() {
    ll t; cin>>t;
    for(int i=0;i<t;i++)    solve();
}