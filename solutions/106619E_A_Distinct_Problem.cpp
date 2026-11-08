#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
    ll n; cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)    cin>>a[i];
    sort(a.begin(),a.end());
    map<ll,ll>m;
    for(int i=0;i<n;i++)    m[a[i]]++;
 
    ll sum=m[a[0]],maxed=m[a[0]];
    ll p=-2e18;
    for(auto x:m){
        if(x.first==p+1)  sum+=x.second;
        else    sum=x.second;
        maxed=max(maxed,sum);
        p=x.first;
    }
    cout<<n-maxed<<endl;
}
int main(){
    int t; cin>>t;
    for(int i=0;i<t;i++)    solve();
}