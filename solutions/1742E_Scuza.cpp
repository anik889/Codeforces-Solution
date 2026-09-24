#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //PBDS header
#include <ext/pb_ds/tree_policy.hpp> //PBDS Header
using namespace std;
using namespace __gnu_pbds; //PBDS nammespace
template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
template<typename T>
using ordered_multiset = tree<
    pair<T, int>,
    null_type,
    less<pair<T, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
#define ll long long 
void solve(){
	ll n,q; cin>>n>>q;
    vector<ll>a(n);
    for(int i=0;i<n;i++)    cin>>a[i];
    vector<pair<ll,ll>>pref(n+1,{0,0});
    for(int i=1;i<=n;i++){
        pref[i].first=max(pref[i-1].first,a[i-1]);
        //c=a[i-1];
        pref[i].second=a[i-1]+pref[i-1].second;
    }
    for(int i=0;i<q;i++){
        ll k; cin>>k;
        ll l=1,r=n,mid, ans=0;
        while(l<=r){
            mid=l+(r-l)/2;
            if(k>=pref[mid].first){
                l=mid+1;
                ans=pref[mid].second;
            }
            else    r=mid-1;
        }
        cout<<ans<<' ';
    }
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t; cin>>t;
    for(int i=0;i<t;i++)    solve();
}