#include<bits/stdc++.h>
using namespace std;
bool checker(vector<int>a, int n){
  vector<int>ans(n);
  long long int checking=0;
  long long maxelem=a[0];
  for(int i=0;i<n;i++){
    if(a[i]<maxelem)
      checking=max(checking,(long long int)maxelem-a[i]);
    else
        maxelem=a[i];
  }
  if(checking==0)   return true;
  ans[0]=a[0];
  for(int i=1;i<(int)ans.size();i++){
      if(a[i]>=ans[i-1])  ans[i]=a[i];
      else if(a[i]+checking>=ans[i-1])    ans[i]=a[i]+checking;
      else  return false;
  }
  return true;
}
void solve(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)  cin>>a[i];
  if(checker(a,n))  cout<<"YES"<<endl;
  else  cout<<"NO"<<endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  for(int i=0;i<t;i++)
    solve();
}