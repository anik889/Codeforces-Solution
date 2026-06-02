#include<bits/stdc++.h>
using namespace std;
void solve(){
    double n;
    cin>>n;
    vector<double>a(n);
    for(int i=0;i<n;i++)     cin>>a[i];
    double ans=(*max_element(a.begin(),a.end())-*min_element(a.begin(),a.end()))/2;
    cout<<ceil(ans)<<endl;
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++)    solve();
}