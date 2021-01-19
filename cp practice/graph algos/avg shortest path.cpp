// Problem Link - https://www.codechef.com/problems/AVGSHORT
/* By Yush singla */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define int 		            long long 
#define ld				        long double
#define mod                     1000000007
#define inf                     1e18
#define endl			        "\n"
#define tc                      int ntc;cin>>ntc;while(ntc--)
#define pb 				        push_back
#define vi                      vector<int>
#define vs				        vector<string>
#define pii                     pair<int,int>
#define ump				        unordered_map
#define mp 				        make_pair
#define pqb                     priority_queue<int>
#define pqs                     priority_queue<int,vi,greater<int> >
#define all(n) 			        n.begin(),n.end()
#define ff 				        first
#define ss 				        second
#define ps(x,y)                 fixed<<setprecision(y)<<x
#define mid(l,r)                (l+(r-l)/2)
#define bitc(n) 		        __builtin_popcount(n)
#define loop(i,a,b) 	        for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	        for(int i=(a);i>=(b);i--)
#define iter(container, it)     for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	        { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	        for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b)        {return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch)         {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}


vector<vector<pii>> adj;

bool check(int n,int a,int b,double m){
	std::vector<double> wt(n,inf);
	std::vector<bool> lol(n,false);
	wt[a]=0;
	loop(j,0,n-1){
		loop(i,0,n-1){
			for(auto el: adj[i]){
				if(wt[i]!=inf && wt[i]+(double)el.ss-m<wt[el.ff]){
					wt[el.ff]=wt[i]+(double)el.ss-m;
				}
			}
		}
	} 
	// logarr(wt,0,n-1);
	// log(wt[b]);
	loop(i,0,n-1){
			for(auto el: adj[i]){
				if(wt[i]!=inf && wt[i]+(double)el.ss-m<wt[el.ff]){
					lol[i]=true;
				}
			}
		}
	// double og=wt[b];
	// log(og);
	//to detect effect of negative weight cycle
	loop(j,0,n-1){
			loop(i,0,n-1){
				for(auto el: adj[i]){
					lol[i] =lol[i] | lol[el.ff];
				}
			}
		} 
	// log(wt[b],og,m,(og!=wt[b]||wt[b]<=0));
	return lol[b] || wt[b]<=0;
}
// bool check(int n,int s,int t,double x) {
// 	std::vector<double> d(n);
// 	std::vector<bool> lol(n);
// 	for (int i = 1; i <= n; i++)
// 		d[i] = 1e8, lol[i] = false;
// 	d[s] = 0;
// 	for (int i = 1; i <= n; i++)
// 		for (int v = 1; v <= n; v++)
// 			for (auto u: adj[v])
// 				if (d[u.first] < 1e8)
// 					d[v] = min(d[v], d[u.first] + (double)(u.second) - x);
// 	for (int v = 1; v <= n; v++)
// 		for (auto u: adj[v])
// 			if (d[u.first] + (double)(u.second) - x < d[v] && d[u.first] < 1e8)
// 				lol[v] = true;
// 	for (int i = 1; i <= n; i++)
// 		for (int v = 1; v <= n; v++)
// 			for (auto u: adj[v])
// 				lol[v] =lol[v]|lol[u.first];
// 	return (d[t] >= 0. && !lol[t]);
// }


bool bellmanCheckPath(int n,int a,int b,double m=0){
	std::vector<double> wt(n,inf);
	wt[a]=0;
	loop(j,0,n-1){
		loop(i,0,n-1){
			for(auto el: adj[i]){
				if(wt[i]!=inf && wt[i]+el.ss-m<wt[el.ff]){
					wt[el.ff]=wt[i]+el.ss-m;
				}
			}
		}
	}
	// logarr(wt,0,n-1);
	// log(wt[b]);
	double og=wt[b];
	// log(og);
	//to detect effect of negative weight cycle
	loop(j,0,n-1){
		loop(i,0,n-1){
			for(auto el: adj[i]){
				if(wt[i]!=inf && wt[i]+el.ss-m<wt[el.ff]){
					wt[el.ff]=wt[i]+el.ss-m;
				}
			}
		}
	} 
	// log(wt[b],og);
	return wt[b]!=inf;
}

int32_t main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	//we need to apply a binary search basically to get the
	//answer that is needed to 
	//to delete the concept of avg we just do -avg in all the
	//
	tc{
		int n,mi;
		cin>>n>>mi;
		adj.clear();
		adj.resize(n);
		int maxW=0;
		while(mi--){
			int x,y,z;
			cin>>x>>y>>z;
			x--,y--;
			adj[x].pb({y,z});
			maxW=max(maxW,z);
		}
		// log(maxW);
		int a,b;
		cin>>a>>b;
		a--,b--;
		// if(!bellmanCheckPath(n,a,b)){
		// 	cout<<"-1"<<endl;
		// 	continue;
		// }
		// cout<<bellman(n,a,b,1.5)<<endl;
		double l=1,r=200,m;
		loop(i,0,49){
			m=mid(l,r);
			// log(l,r,m);
			if(check(n,a,b,m)){
				r=m;
			}
			else{
				l=m;
			}
		}
		if(m<maxW)
		cout<<ps(m,7)<<endl;
		else cout<<"-1"<<endl;
	}
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
