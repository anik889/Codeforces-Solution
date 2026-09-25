#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
    vector<vector<char>>grid(8,vector<char>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin>>grid[i][j];
        }
    }
    ll count_red=-1e5,count_blue=-1e5;
    for (int i = 0; i < 8; i++) {
        ll cc=count(grid[i].begin(),grid[i].end(),'R');
        count_red=max(cc,count_red);
    }
    if(count_red==8)        cout<<"R\n";
    else    cout<<"B\n";
}
int main() {
    ll t; cin>>t;
    for(int i=0;i<t;i++)    solve();
}