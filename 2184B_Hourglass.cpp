#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int s,k,m;
    cin>>s>>k>>m;
    if(k>=s)    cout<<max(0LL,s-(m%k))<<endl;
    else{
        if((m/k)%2==0)  cout<<max(0LL,s-(m%k))<<endl;
        else        cout<<max(0LL,k-(m%k))<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++)    solve();
}