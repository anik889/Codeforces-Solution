#include<bits/stdc++.h>
using namespace std;
void solve(){
    float a,b,c;
    cin>>a>>b>>c;
    float ans=(ceil((a*c)/b));
    cout<<(int)ans-c<<endl;
}
int main(){
    int t=1;
    //cin>>t;
    for(int i=0;i<t;i++)     solve();
}