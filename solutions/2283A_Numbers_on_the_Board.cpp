#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
	ll l,r;
	cin>>l>>r;
	if(l>0 || r<0)		cout<<r-l<<endl;
	else{
		if((-l)<r)	cout<<r+l-1<<endl;
		else if((-l)>r) 	cout<<-l-r-1<<endl;
		else 	cout<<0<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1; cin>>t;
	for(int i=0;i<t;i++)	solve();
}