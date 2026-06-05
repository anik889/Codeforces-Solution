#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    set<char>s;
    for(int i=0;i<n;i++){
        char ss;
        cin>>ss;
        if(ss>='A' && ss<='Z')
            ss=ss+32;
        s.insert(ss);
    }
    if(s.size()==26)    cout<<"YES"<<endl;
    else    cout<<"NO"<<endl;
}