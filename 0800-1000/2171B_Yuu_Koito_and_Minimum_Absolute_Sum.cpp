#include<bits/stdc++.h>
using namespace std;
long long int l=0ll;
void solve(){
    long long int n;cin>>n;
    vector<long long int>a(n);
    long long int maxed=0;
    for(long long int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==-1)        maxed=max(maxed,i);
    }    
    long long int sum,x;
    if(a[0]==-1 && a[n-1]==-1){ 
        sum=0; x=0;
    }
    else if(a[0]==-1 && a[n-1]!=-1){
        sum=0;x=a[n-1];a[0]=x;
    }
    else if(a[n-1]==-1 && a[0]!=-1){  
        sum=0;x=a[0];a[n-1]=x; 
    }
    else {  
        sum=abs(a[n-1]-a[0]);
        //if(maxed>1)    swap(a[maxed],sum);
        //else    maxed=0;
    }
    cout<<sum<<endl;
    for(int i=0;i<n;i++){    
        if(a[i]==-1)    a[i]=0;
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++)    solve();
}
