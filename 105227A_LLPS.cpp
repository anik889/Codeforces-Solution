#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin>>s;
    map<char,int>ss;
    sort(s.begin(),s.end());
    //cout<<s<<endl;;
    char ch= *max_element(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(s[i]==ch)
            cout<<s[i];
        else    continue;
    }
    cout<<endl;
 
}
int main(){
    int t=1;
    //cin>>t;
    for(int i=0;i<t;i++)     solve();
}