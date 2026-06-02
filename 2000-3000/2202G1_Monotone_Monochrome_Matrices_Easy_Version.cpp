#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int sz,qs; 
        cin>>sz>>qs;
        vector<int> ro(sz+1,0),co(sz+1,0),gt(sz+2,0);
        gt[0]=sz;
        long long l=0,r=0;
        while(qs--){
            int u,v;
            cin>>u>>v;
            l+=co[v]++;
            r+=gt[ro[u]+1];
            int n=++ro[u];
            gt[n]++;
            if(l!=r)cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
    return 0;
}