#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n; cin>>n;
    string s;
    cin>>s;
    char ch='R';
    ll ans=0;
    for(int i=0;i<n;i++){
        if(ch!=s[i])    ans++;
        if(s[i]=='R')   ch='B';
        else    ch='R';
    }
    cout<<ans<<endl;
}
int main(){
    int t=1; cin>>t;
    for(int i=0;i<t;i++)    solve();
}