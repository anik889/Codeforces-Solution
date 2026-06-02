#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 3010
#define pii pair<int,int>
#define x first
#define y second
#define pct __builtin_popcount
#define mod 998244353
#define inf 1e14
#define pi ajcos(-1)
#define eps 1e-8
 
void solve(){
	int n,q;
	cin>>n>>q;
	multiset<int> ans;
	set<pii> st[n+1];
	set<int> pos[n+1]; 
	vector<int> a(n+1),res(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pos[a[i]].insert(i);
	}
	auto cal=[&](int l,int r){
		return (r-l+2)*(r-l+1)/2; 
	};
	auto insert=[&](int val){
		if(pos[val].size()<=1){
			return;
		}
		int len=*pos[val].rbegin()-*pos[val].begin();
		ans.insert(len);
		int p=*pos[val].begin();
		int L=p,R=p;
		auto it=st[len].upper_bound({p,-1});
		if(it!=st[len].begin()&&(--it)->second==p-1){
			res[len]-=cal(it->first,it->second);
			L=it->first;
			st[len].erase(it);
		}
		it=st[len].upper_bound({p,-1});
		if(it!=st[len].end()&&it->first==p+1){
			res[len]-=cal(it->first,it->second);
			R=it->second;
			st[len].erase(it);
		}
		res[len]+=cal(L,R);
		st[len].insert({L,R});
	};
	auto del=[&](int val){
		if(pos[val].size()<=1){
			return;
		}
		int len=*pos[val].rbegin()-*pos[val].begin();
		ans.erase(ans.find(len));
		int p=*pos[val].begin();
		auto it=--st[len].upper_bound({p,inf});
		int L=it->first,R=it->second;
		st[len].erase(it);
		res[len]-=cal(L,R);
		if(L<p){
			res[len]+=cal(L,p-1);
			st[len].insert({L,p-1});
		}
		if(R>p){
			res[len]+=cal(p+1,R);
			st[len].insert({p+1,R});
		}
	};
	for(int i=1;i<=n;i++){
		insert(i);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(a[x]!=y){
			int pre=a[x];
			del(pre),del(y);
			pos[pre].erase(x);
			a[x]=y;
			pos[a[x]].insert(x);
			insert(pre),insert(y);
		}
		if(ans.size()==0){
			cout<<"0 0\n";
		}
		else{
			cout<<*ans.rbegin()<<" "<<res[*ans.rbegin()]<<"\n";
		}
	}	
}
 
signed main(){
    ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cout<<fixed;
	cout<<setprecision(0);
	int T=1;
	cin>>T;
    while(T--) solve();
    return 0;
}