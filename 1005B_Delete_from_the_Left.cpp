#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s,c;
    cin>>s>>c;
    int t=0,k=0;
    int n=s.length(), m=c.length(),i=n-1,j=m-1;
    while(i>=0 && j>=0 and s[i]==c[j]){
        i--,j--;
    }
    cout<<(i+1)+(j+1)<<endl;
 
}
int main(){
   solve(); 
}