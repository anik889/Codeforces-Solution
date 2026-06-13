 #include <bits/stdc++.h>
 
using namespace std;
int main(){
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
	    int n,k;
	    cin>>n>>k;
	    int j=n-((k-1)*2);
	    int m=n-(k-1);
	    if(j%2==0 && j>0){
	        cout<<"YES"<<endl;
	        for(int i=1;i<k;i++)
	            cout<<2<<" ";
	        cout<<j<<endl;
	    }
	    else if(m%2!=0 && m>0){
	        cout<<"YES"<<endl;
	        for(int i=1;i<k;i++)
	            cout<<1<<" ";
	        cout<<m<<endl;
	    }
	    else
	        cout<<"NO"<<endl;
    }
}