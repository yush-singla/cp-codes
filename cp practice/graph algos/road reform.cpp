// Problem Link - https://codeforces.com/contest/1468/problem/J
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
class union_find
{
	int n;
	vector<int> par;
	vector<int> sz;
public:
	union_find(int nval)
	{
		n = nval;
		par.resize(n + 1);
		sz.resize(n + 1);

		for (int i = 1; i <= n; ++i)
			par[i] = i, sz[i] = 1;
	}

	//O(1) ammortized
	int root(int x)
	{
		/*while(x!=par[x])
			x=par[x];
		return x;*/

		if (x == par[x])
			return x;

		return par[x] = root(par[x]);
	}

	//O(1) ammortized
	bool find(int a, int b)
	{
		return root(a) == root(b);
	}

	//O(1) ammortized
	void un(int a, int b)
	{
		int ra = root(a);
		int rb = root(b);

		if (ra == rb)
			return;

		if (sz[ra] > sz[rb])
			swap(ra, rb);

		par[ra] = rb;
		sz[rb] += sz[ra];
	}
};
class compare{
public:
	bool operator()(pair<pii,int> a,pair<pii,int>b){
		return a.ss>b.ss;
	}
};
class compare1{
public:
	bool operator()(pair<pii,int> a,pair<pii,int>b){
		return a.ss<b.ss;
	}
};


int32_t main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	tc{
		int n,m,k,count=0;
		std::vector<pair<pii,int>> edges,st;
		priority_queue<pair<pii,int>,vector<pair<pii,int>>,compare> greatEdge;
		priority_queue<pair<pii,int>,vector<pair<pii,int>>,compare1> lesEdge;

		cin>>n>>m>>k;
		union_find dsu(n);
		while(m--){
			int x,y,s;
			cin>>x>>y>>s;
			edges.pb({{x,y},s});
		}
		for(auto e:edges){
			if(e.ss>k){
				//log(e.ss);
				greatEdge.push(e);
			}
			// else if(e.ss==k){
			// 	if(!dsu.find(e.ff.ff,e.ff.ss)){
			// 		st.pb(e);
			// 		dsu.un(e.ff.ff,e.ff.ss);
			// 		count++;
			// 	}
			// }
			else{
				lesEdge.push(e);
			}
		}
		// if(!greatEdge.empty()&&!lesEdge.empty()&& greatEdge.top().ss-k<=k-lesEdge.top().ss && count==0){
		// 	st.pb(greatEdge.top());
		// 	dsu.un(greatEdge.top().ff.ff,greatEdge.top().ff.ss);
		// 	greatEdge.pop();
		// }
		// while(!lesEdge.empty()){
		// 	cout<<lesEdge.top()<<endl;
		// }
		while(!lesEdge.empty()){
			auto e=lesEdge.top();
			if(!dsu.find(e.ff.ff,e.ff.ss)){
				dsu.un(e.ff.ff,e.ff.ss);
				st.pb(e);
				count++;
			}
			lesEdge.pop();
			if(count==n-1){
				break;
			}
		}
		while(!greatEdge.empty()){
			auto e=greatEdge.top();
				//log(e.ss);
			if(!dsu.find(e.ff.ff,e.ff.ss)){
				dsu.un(e.ff.ff,e.ff.ss);
				st.pb(e);
				count++;
			}
			greatEdge.pop();
			if(count==n-1){
				break;
			}
		}
		int big=0;
		//if we go here than there must be a bigger than k
		//edge if big!=0 so we just return big and are done
		for(auto el:st){
			if(el.ss>k){
				// //log(st.size());
				big+=el.ss-k;
				//log(big,el.ss);
			}
		}
		//if we go in this it means all vals are smaller
		//so we can simply just replace any one edge with the 
		//smallest possible edge
		//this is a property ;of mst that if we
		//add only one edge to the mst we can always keep it 
		//an mst be removing an edge
		if(big==0){
			big=inf;
			for(auto el:edges){
				big=min(big,abs(el.ss-k));
			}
		}
		cout<<big<<endl;
	}

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
