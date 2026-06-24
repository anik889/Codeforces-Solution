#include<bits/stdc++.h>
using namespace std;
#define lli long long int 
bool isPrime(lli n) {
    if(n<=1)   return false;
    if(n==2)   return true;
    if(n%2==0)     return false;
    for(lli i=3;i*i<=n;i+=2) {
        if(n%i==0)      return false;
    }
    return true;
}
void solve(){
    lli n;
    cin>>n;
    vector<lli>a(n);
    for(lli i=0;i<n;i++)    cin>>a[i];
    for(lli i=0;i<n;i++){
        lli j=round(sqrt(a[i]));
        if(j*j==a[i] and isPrime(j))    cout<<"YES\n";
        else    cout<<"NO\n";
    }
}
int main(){
    int t=1;
    for(int i=0;i<t;i++)    solve();
}