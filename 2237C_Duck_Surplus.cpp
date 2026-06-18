#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n;
    cin>>n;
    vector<long long>a(n);
    for(long long i=0;i<n;i++)  cin>>a[i];
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            swap(a[i],a[i+1]);
            a[i+1]=a[i+1]+a[i];
        }
    }
    cout<<a[n-1]<<endl;
}
int main(){
    long long t;cin>>t;
    for(long long i=0;i<t;i++)  solve();
}