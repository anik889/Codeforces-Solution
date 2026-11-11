#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
    ll n; cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)    cin>>a[i];
    sort(a.rbegin(),a.rend());
    vector<pair<ll,ll>>p;
    ll c=1;
    for(int i=0;i<n;i++){
        if(i>0 && a[i]==a[i-1])     c++;
        else    c=1;
        p.push_back({c,-a[i]});
    }
    sort(p.begin(),p.end());
    for(auto x:p)   cout<<-x.second<<' ';
    cout<<endl;
}
int main(){
    int t; cin>>t;
    for(int i=0;i<t;i++)    solve();
}