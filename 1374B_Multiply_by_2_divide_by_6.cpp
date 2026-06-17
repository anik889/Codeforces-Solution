#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n;
    cin>>n;
    long long k=n,ans=0,c2=0,c3=0;
    while(n%2==0){
        n=n/2;c2++;
    }
    while(n%3==0){
        n=n/3;c3++;
    }
    if(n==1 && c3>=c2)
        cout<<(c3-c2)+c3<<endl;
    else 
        cout<<-1<<endl;
}
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++)    solve();
}