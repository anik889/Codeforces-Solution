#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
void solve() {
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++)    cin>>a[i];
    for(ll i=0;i<n-1;i++){
        if(a[i]<a[i+1]) a[i+1]=a[i];
        else continue;
    } ll sum=0;
    for(ll i=0;i<n;i++)    sum+=a[i];
    cout<<sum<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--) solve();
 
    return 0;
}