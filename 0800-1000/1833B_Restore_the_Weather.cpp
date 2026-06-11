#include<bits/stdc++.h>
using namespace std;
    int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        long long int n,m;
        cin>>n>>m;
        vector<pair<long long int,long long int>>a(n);
        vector<long long int>b(n);
        vector<long long int>ans(n);
        for(long long int i=0;i<n;i++){
            long long int j;cin>>j;
            a[i].first=j;a[i].second=i;
        }
 
        for(long long int i=0;i<n;i++)    cin>>b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(long long int i=0;i<n;i++){
            ans[a[i].second]=b[i];
        }
        for(int i=0;i<n;i++)    cout<<ans[i]<<' ';
        cout<<endl;
    }
}
