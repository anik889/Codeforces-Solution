#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n;
    cin>>n;
    vector<ll>p,q; 
    ll sum=0;
    for(int i=0;i<n;i++){ 
        ll x; 
        cin>>x;
        sum+=x; 
        if(i%2==0)     p.push_back(x);
        else   q.push_back(x);
    }
    sort(p.begin(),p.end()); 
    sort(q.begin(),q.end());
    ll a=0,b=0;
    ll range=min(p.size(),q.size());
    for(ll i=0;i<range;i++){
        b+=(p[i]+q[i]);
        a=max(a,-2*b);
    }
    cout<<(sum+a)<<endl;
}
int main(){
    ll t; cin>>t;
    for(int i=0;i<t;i++)    solve();
}