#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<max(abs(a-b),abs(a-b+c))<<endl;
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++)    solve();
}