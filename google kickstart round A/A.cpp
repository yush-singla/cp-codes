#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int tc;
	cin>>tc;
	for(int ntc=1;ntc<=tc;ntc++){
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		int cnt=0;
		for(int i=0;i<n/2;i++){
			if(s[i]!=s[n-i-1]){
				cnt++;
			}
		}	
		int ans=max(0,k- cnt);
		cout<<"Case #"<<ntc<<": "<<ans<<endl;
	}
}