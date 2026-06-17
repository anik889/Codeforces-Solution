#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<string>a;
    set<string>aa;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        a.push_back(s);
    }
    for(int i=n-1;i>=0;i--){
        if(aa.find(a[i])==aa.end())
            cout<<a[i]<<endl;
        aa.insert(a[i]);
    }
}
int main() {
    solve();
}