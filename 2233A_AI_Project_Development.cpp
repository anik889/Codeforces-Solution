#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n,x,y,z;
    cin>>n>>x>>y>>z;
    long long work_ai=(n+x+y-1)/(x+y);
    long long lines=n*z;
    long long time_ai,additional;
    if(x*z >= n)    time_ai=(n+x-1)/x;
    else        time_ai=z+(((n-(x*z))+(x+(10*y))-1)/(x+(10*y)));
    cout<<min(work_ai,time_ai)<<endl;
 
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++)    solve();
}