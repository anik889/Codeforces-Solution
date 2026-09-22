#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n,k; cin>>n>>k;
    string s;cin>>s;
    ll c=count(s.begin(),s.begin()+k,'W');
    ll w=c;
    for(int i=1;i<=n-k;i++){
        if(s[i-1]=='W')    w--;
        if(s[i+k-1]=='W')  w++;
        c=min(w,c);
    }
    cout<<c<<endl;
 
}
int main(){
	int t; cin>>t;
	for(int i=0;i<t;i++) solve();
}