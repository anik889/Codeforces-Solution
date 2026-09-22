#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n; cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll>pref(n+1,0);
    for(int i=1;i<=n;i++)   pref[i]=pref[i-1]+a[i-1];
    ll q; cin>>q;
    for(int i=0;i<q;i++){
        ll x; cin>>x;
        ll ans=n;
        ll left=0,right=n-1, mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(pref[mid]>=x){
                ans=mid; 
                right=mid-1;
            }
            else    left=mid+1;
        }
        cout<<ans<<endl;
    }
}
int main(){    solve();
}