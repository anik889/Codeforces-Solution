#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    vector<ll>a(3);
    for(int i=0;i<3;i++)    cin>>a[i];
    sort(a.begin(), a.end());
    cout<<(a[1]-a[0]==1 && a[2]-a[1]==1 ?"YES\n":"NO\n");
}
int main(){
    int t=1; cin>>t;
    for(int i=0;i<t;i++)    solve();
}