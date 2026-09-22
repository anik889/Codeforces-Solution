#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin>>n;
    int a,b,c,d;
    cin>>a>>b>>c;
    d=min({a,b,c});
    cout<<n-d<<endl;
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++)    solve();
}