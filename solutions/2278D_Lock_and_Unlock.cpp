#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
	ll n;
	cin>>n;
	vector<ll>v;
	for(int i=0;i<n;i++){
		ll x; cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
 
	ll mid=v[n/2];
	ll ans=0;
	for(int i=0;i<n;i++){
		if(v[i]>mid)	ans+=(v[i]-mid);
		else 	ans+=(mid-v[i]);
	}
	ll step=*max_element(v.begin(),v.end()) - *min_element(v.begin(),v.end());
	cout<<ans<<' '<<step<<endl;
}
int main() {
    int t;  cin>>t;
    for(int i=0;i<t;i++)   	solve();
    return 0;
}