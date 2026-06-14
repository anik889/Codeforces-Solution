#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;
    cin>>n;
    vector<long long int>v;
    v.push_back(1);
    while(n>=2){
        v.push_back(n);n--;
    }
    for(int i=0;i<(int)v.size();i++)    cout<<v[i]<<' ';
    cout<<endl;    
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++)     solve();
 
}