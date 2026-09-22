#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
    int n,k; cin>>n>>k;
    vector<ll>a(n);
    for(int i=0;i<n;i++)    cin>>a[i];
    if(is_sorted(a.begin(),a.end()))    cout<<"YES\n";
    else if(k==1)    cout<<"NO\n";
    else    cout<<"YES\n";
}
int main(){
    int t; cin>>t; 
    for(int i=0;i<t;i++)    
        solve();
}