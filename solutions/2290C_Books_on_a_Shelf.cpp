#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n; cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)    cin>>a[i];
    sort(a.begin(),a.end());
    ll size=0;
    vector<ll>visit(n);
    ll lb=0,rb=n-1;
    for(int i=0;i<n;i++){
        if(i==0 || a[i]!=a[i-1]){
            visit[lb++]=a[i];
            size++;
        }
        else{
            visit[rb--]=a[i];
            if(i==1 || a[i]!=a[i-2])    size++;
        }
    }
    cout<<size<<endl;
    for(int i=0;i<n;i++)    cout<<visit[i]<<' ';
    cout<<endl;
}
int main(){
    int t=1; cin>>t;
    for(int i=0;i<t;i++)    solve();
}