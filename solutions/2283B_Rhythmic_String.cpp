#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
	ll n; cin>>n;
	vector<ll>a(n);
	for(int i=0;i<n;i++)	cin>>a[i];
	ll ans=0;
	for(int i=0;i<n;i++){
		ll sum=0;
		for(int j=0;j<n;j++){
			if(a[j]%a[i]==0) 	sum++;
		}
		ans=max(ans,sum);
	}
	cout<<n-ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1; cin>>t;
	for(int i=0;i<t;i++)	solve();
}