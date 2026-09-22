#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n; cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)        cin>>a[i];
    set<ll>s;
    for(int i=0;i<n;i++){
        s.insert(a[i]-i);
    }
    ll c=1,e=1;
    for(auto i=s.begin();i!=prev(s.end());i++){
        auto it=*i;
        auto itx=*next(i);
        if((itx-it) == 1)        c++;
        else{
            e=max(c,e);
            c=1;
        }
    }
    e=max(e,c);
    cout<<e<<endl;
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++)    solve();
}