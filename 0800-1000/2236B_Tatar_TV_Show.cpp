#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n, k;
    cin>>n>>k;
    string s;
    cin>> s;
    vector<long long int>v(k,0);
    for (long long int i=0;i<k;i++) {
        for (long long int j=i;j<n;j+=k)
            if (s[j] == '1') v[i]++;
    }
    for (long long int i=0;i<k;i++) {
        if (v[i]%2!=0){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long int t;
    cin>>t;
    while (t--) solve();
}
