#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
    ll n; cin>>n;
    cout<<"? "<<1<<' '<<n<<endl;
    ll x; cin>>x;
    if(x==-1)   exit(0);
    if(x==0){
        cout<<"! NO"<<endl;
        return;
    }
    cout<<"? "<<1<<' '<<x<<endl;
    ll y; cin>>y;
    if(y==-1)   exit(0);
    if(y==x)    cout<<"! NO"<<endl;
    else       cout<<"! YES"<<endl;
}
int main(){
    int t; cin>>t;
    for(int i=0;i<t;i++)    solve();
}