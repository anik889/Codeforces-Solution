#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n;
    long long co=0,ce=0,coa=0,cea=0;
    cin>>n;
    vector<long long>a(n);
    for(int i=0;i<n;i++)      cin>>a[i];
    for(int i=0;i<n;i++){
        if(i%2==0){ 
            ce++;
            cea+=a[i];
        }
        else{
            co++;
            coa+=a[i];
        }
    }
    if((cea%ce==0)&&(coa%co==0)&&(cea/ce==coa/co)){
        cout<<"YES"<<endl;
    } else{
        cout<<"NO"<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) solve();
    return 0;
}
