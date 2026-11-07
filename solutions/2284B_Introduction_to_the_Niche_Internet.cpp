#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
void solve() {
	ll n,k; cin>>n>>k;
	vector<ll>a(n);
	for(int i=0;i<n;i++)	cin>>a[i];
	sort(a.begin(),a.end());
	vector<ll>ans;
	for(int i=n-k;i<n;i++)		ans.pb(a[i]);
	for(int i=n-k-1;i>=0;i--)	ans.pb(a[i]);
	ll check=0, b=0;
	for(int i=0;i<(int)(ans.size());i++){
		if(ans[i]*i>=check)		b++;
		check+=ans[i];
	}
	if(b!=k)		cout<<"NO\n";
	else{
		cout<<"YES\n";
		for(int i=0;i<(int)(ans.size());i++)	cout<<ans[i]<<' ';
		cout<<endl;
	}
}
int main() {
    int t=1;  cin>>t;
    for(int i=0;i<t;i++)   	solve();
    return 0;
}