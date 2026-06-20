#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n; cin>>n;
    vector<long long>a(n);
    for(long long i=0;i<n;i++)    cin>>a[i];
    sort(a.begin(),a.end());
    set<long long>s;
    long long dis,lb,ub, ans=1e18;
    for(long long i=0;i<n;i++){
        if(s.find(a[i])==s.end()){
            s.insert(a[i]);
            lb=i;
            ub=n-(i+1);
            dis=max(lb,ub);
        }
        else{
            ub=n-(i+1)-count(a.begin()+i+1,a.end(),a[i]);
            dis=max(lb,ub);
        }
        ans=min(ans,dis);
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
        solve();
}