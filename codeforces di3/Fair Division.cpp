#include<iostream>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int t, n, k, a, b;
	cin>>t;
	while(t--){
		a = b = 0;
		cin >> n;
		while(n--){
			cin >> k;
			(k==1?a++:b++);
		}
		cout << ((a%2 || (b%2 && a<2))?"NO":"YES") << endl;
	} 	
	return 0;
} 