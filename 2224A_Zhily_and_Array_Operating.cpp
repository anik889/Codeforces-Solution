#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;
    cin>>n;
    vector<long long int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    long long int s=0,k=0;
    for(int i=n-2;i>=0;i--){
        if(a[i+1]>0)
            a[i]=a[i]+a[i+1];
    }
    for(int i=0;i<n;i++){
        if(a[i]>0)  s++;
    }
    cout<<s<<endl;
   
}
int main(){
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
        solve();
}