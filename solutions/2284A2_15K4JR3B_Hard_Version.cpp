#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
	ll n; cin>>n;
	vector<ll>a(n);
	for(int i=0;i<n;i++)	cin>>a[i];
	sort(a.begin(),a.end());
	ll x=0,y=0;
	for(int i=n-1;i>=0;i--){
		if(x<y)		x+=(1ll<<a[i]);
		else 	y+=(1ll<<a[i]);
	}
	cout<<x*y<<endl;
}
int main() {
    int t=1;  cin>>t;
    for(int i=0;i<t;i++)   	solve();
    return 0;
}