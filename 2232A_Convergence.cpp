#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)    cin>>a[i];
    int c=0;
    sort(a.begin(),a.end());
    for(int i=0,j=n-1;i<=j;i++,j--){
        if(a[i]==a[j] && a[i]==a[(n-1)/2])  continue;
        c++;
    }
    cout<<c<<endl;
}
int main(){
    int t; cin>>t;
    for(int i=0;i<t;i++)
        solve();
}