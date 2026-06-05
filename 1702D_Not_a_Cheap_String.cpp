#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s; cin >> s;
    int c; cin >> c;
    
    int n = s.length();
    vector<int> a(27,0);
    for(int i=0;i<n;i++)    a[s[i]-'a'+1]++;
    int sum=0;
    for(int i=0;i<=26;i++)   sum+=(a[i]*i);
    for(int i=26;i>=1;i--){
        while(a[i]>0 && sum>c){
            a[i]--; sum-=(i);
        }
    }
    for(int i=0;i<n;i++){   
        if(a[s[i]+1-'a']>=1){
            cout<<s[i];
            a[s[i]+1-'a']--;
        }
    }
    cout<<endl;
}
int main(){
    int t; cin>>t;
    for(int i=0;i<t;i++)    solve();
}