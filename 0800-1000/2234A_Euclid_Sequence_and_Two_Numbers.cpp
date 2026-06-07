#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)    cin>>a[i];
    sort(a.begin(),a.end(),greater<int>());  
    if(n==2){
        cout<<a[0]<<' '<<a[1]<<endl;
    }else{
        bool found=true;
        for(int i=0;i+2<n;i++){
            if((a[i]%a[i+1])!=a[i+2]){
                found=false;
                break;
            }
            //else continue;
        }
        if(!found)
            cout<<-1<<endl;
        else
            cout<<a[0]<<' '<<a[1]<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++)    solve();
}
