#include<bits/stdc++.h>
using namespace std;
void solve(){
	long long n,k; cin>>n>>k;
	vector<long long>a(n);
	for(int i=0;i<n;i++)	cin>>a[i];
	map<long long,long long>m;
	for(int i=0;i<n;i++){
		m[a[i]]++;
	}
	bool check=false;
	long long i=0,sum=0;
	while(true){
		if(m[i]<=0){
			cout<<i<<endl;
			return;
		}
		sum+=m[i];		//if(sum==0)	
		if(sum>=((1+i)*k))	i++;
		else{
			cout<<i<<endl;
			return;
		}
		//i++;
	}
	cout<<i<<endl;
}
int main(){
	int t; cin>>t;
	for(int i=0;i<t;i++)	solve();
}