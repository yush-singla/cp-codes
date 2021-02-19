// Problem Link - https://www.spoj.com/problems/ADASALES/
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

vi price;
std::vector<vi> adj;
vi dpin,dpin1,dpin2,dpout;

void dfs1(int k,int pr,int cost){
	// log(k)
	for(auto el:adj[k]){
		if(el!=pr){
			dfs1(el,k,price[k]);
			// dpin[k]=max(dpin[k],dpin[el]+max(price[el]-cost,(int)0));
		}
	}
	for(auto el:adj[k]){
		if(el!=pr){
			// dfs1(el,k,price[k]);
			dpin[k]=max(dpin[k],dpin[el]+max(price[el]-price[k],(int)0));
		}
	}
}
void dfs2(int k,int pr,int cost){
	// log(k);
	for(auto el:adj[k]){
		if(el==pr)continue;
		if(dpin[el]+ max(price[el]-price[k],(int)0) >=dpin1[k]){
			dpin2[k]=dpin1[k];
			dpin1[k]=dpin[el]+ max(price[el]-price[k],(int)0);
		}
		else if(dpin[el]+ max(price[el]-price[k],(int)0)>dpin2[k]){
			dpin2[k]=dpin[el]+ max(price[el]-price[k],(int)0);
		}
	}
	if(k==pr){
		dpout[k]=0;
	}
	else if(dpin1[pr]!=dpin[k]+max(price[k]-price[pr],(int)0))
	dpout[k]=max(dpout[pr],dpin1[pr])+max(price[pr]-price[k],(int)0);
	else dpout[k]=max(dpout[k],max(dpout[pr],dpin2[pr])+max(price[pr]-price[k],(int)0));
	for(auto el:adj[k]){
		if(el!=pr){
			dfs2(el,k,price[k]);
		}
	}
}

//this is a clasical ques of in out dp 
//here since we need to get the max value we use 2 max vals 
//so that we don't need to compute them again and again
//whenever we feel like travelling up in a tree we use this 
//type of the in out dp 


void doo(int n){
	price.resize(n);
	dpin.resize(n);
	dpin.assign(n,0);
	dpin2.resize(n);
	dpin2.assign(n,0);
	dpin1.resize(n);
	dpin1.assign(n,0);
	dpout.resize(n);
	dpout.assign(n,0);
	adj.resize(n);
}
int32_t main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int n,q;
	cin>>n>>q;
	doo(n);
	for(auto &el:price)
		cin>>el;
	// logarr(price,0,n-1);
	loop(i,0,n-2){
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	// loop(i,0,n-1){
	// 	cout<<i<<"--------->";
	// 	for(auto el:adj[i])
	// 		cout<<el<<' ';
	// 	cout<<endl;
	// }
	dfs1(0,0,price[0]);
	dfs2(0,0,price[0]);
	loop(i,0,q-1){
		int x;
		cin>>x;
		cout<<max(dpin[x],dpout[x])<<endl;
	}
	// logarr(dpin,0,n-1);
	// logarr(dpout,0,n-1)
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
