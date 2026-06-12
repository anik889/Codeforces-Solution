#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;
    cin>>n;
    vector<long long int >a(n);
    for(long long int i=0;i<n;i++)    cin>>a[i];
    long long int f=*max_element(a.begin(),a.end())+1;
    long long int ans=0;
    for(long long int i=0;i<n;i++){
        ans=max(ans,(f-a[i]));
        //cout<<f-a[i]<<' ';
    }
    cout<<ans<<endl;
}
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++)    solve();
}