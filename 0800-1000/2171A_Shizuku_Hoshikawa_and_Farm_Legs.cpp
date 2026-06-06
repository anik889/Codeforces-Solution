#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    if(n%2 !=0 )    cout<<0<<endl;
    else    cout<<(n/4)+1<<endl;
    
}
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++)        solve();
}
