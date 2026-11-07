#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
    ll n,k; cin>>n>>k;
    vector<ll>a(n),b(n);
    for(int i=0;i<n;i++)    cin>>a[i];
    for(int i=0;i<n;i++)    cin>>b[i];
    ll ca=0,cb=0;
    for(int i=0;i<n;i++){
        if((a[i]%2)==(k%2))     ca++;
        if((b[i]%2)==(k%2))      cb++;
    }
    if(ca<=cb)  cout<<"YES\n";
    else    cout<<"NO\n";
}
int main(){
    int t; cin>>t;
    for(int i=0;i<t;i++)    solve();
}