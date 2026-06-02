#include<bits/stdc++.h>
using namespace std;
void solve(){
    int t ;
    cin>>t;
    //vector<int>a;
    //a.reserve(64);
    char a[8][8];
    for(int x=0;x<t;x++){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cin>>a[i][j];
                if(a[i][j] >= 'a' && a[i][j]<='z')
                    cout<<a[i][j];
 
            }
        }
        cout<<endl;
       // t--;
    }
}
int main(){
    int n=1;
    for(int i=0;i<n;i++)
        solve();
}