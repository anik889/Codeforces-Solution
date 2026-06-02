#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    multiset<int>a;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        a.insert(num);
    }
    int c1 = a.count(1), c2=a.count(2);
    cout<<a.count(0)+min(c1,c2)+(abs(c1-c2) / 3)<<endl;
    
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}