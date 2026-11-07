#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
	ll n,k,q; cin>>n>>k>>q;
	vector<ll>v;
	vector<ll>mp(200000,0);
	for(int i=0;i<n;i++){
		ll l,r; cin>>l>>r;
		mp[l]++;
		mp[r+1]--;
	}
	ll sum=0;
	for(int i=0;i<=200000;i++){
		sum+=mp[i];
		if(sum>=k)	v.push_back(i);
	}
	for(int i=0;i<q;i++){
		ll a,b; cin>>a>>b;
		auto lb=lower_bound(v.begin(),v.end(),a);
		auto rb=upper_bound(v.begin(),v.end(),b);
		cout<<distance(lb,rb)<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1; //cin>>t;
	for(int i=0;i<t;i++)	solve();
}