#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
	ll n; cin>>n;
	vector<ll>b(n-1),a(n);
	for(int i=0;i<n-1;i++)	cin>>b[i];
 
	a[0]=b[0],a[n-1]=b[n-2];
	for(int i=1;i<n-1;i++){
		a[i]=b[i-1]|b[i];
	}
	bool check=true;
	for(int i=0;i<n-1;i++){
		if((a[i] & a[i+1])!=b[i]){
			check=false;
			break;
		}
	}
	if(check){
		for(int i=0;i<n;i++)	cout<<a[i]<<' ';
		cout<<endl;
	}
	else 	cout<<-1<<endl;
}
int main() {
    int t=1;  cin>>t;
    for(int i=0;i<t;i++)   	solve();
    return 0;
}