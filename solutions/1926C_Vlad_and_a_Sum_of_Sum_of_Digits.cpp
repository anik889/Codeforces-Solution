#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll getDigitSum(int n){
    ll sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
ll limit=2e5+5;
vector<ll>a(limit);
vector<ll>p(limit,0);
void solve(){
    ll n; cin>>n;
    cout<<p[n]<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(ll i=0;i<limit;i++)         a[i]=getDigitSum(i+1);
    for(ll i=1;i<limit;i++)        p[i]=p[i-1]+a[i-1];
    int t; cin>>t;
    for(ll i=0;i<t;i++)   
          solve();
}