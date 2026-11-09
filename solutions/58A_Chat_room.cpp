#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    string s; cin>>s;
    string c="hello";
    ll x=0;
    for(auto p:s){
        if(x<5 && p==c[x]) x++;
    }
    if(x==5)   cout<<"YES\n";
    else    cout<<"NO\n";
}
int main(){
    int t=1; //cin>>t;
    for(int i=0;i<t;i++)    solve();
}