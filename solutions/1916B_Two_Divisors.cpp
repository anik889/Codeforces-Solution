#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
	ll a,b; cin>>a>>b;
    if(b%a==0)  cout<<b*(b/a)<<endl;
    else    cout<<lcm(a,b)<<endl;
}
int main(){
	int t; cin>>t;
    for(int i=0;i<t;i++)    solve();
}