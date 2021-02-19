// Problem Link - 
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
std::vector<vi> adj;
int n,m;
std::vector<int> col,visited;

// bool dfs(int v/*,int c,int par*/){
// 	/*visited[i]=1;
// 	col[i]=c;
// 	for(auto el:adj[i]){
// 		if(el==par)continue;
// 		if(col[el]!=c){
// 			col[el]=(1-c);
// 			if(visited[el])continue;
// 			if(!dfs(el,1-c,i)){
// 				log(el);
// 				return false;
// 			}
// 		}
// 		else{
// 			// log(el);
// 			return false;
// 		} 
// 	}
// 	// bool b=true;
// 	// for(auto el:adj[i]){
// 	// }
// 	return true;*/
// 	for (int u : adj[v]) {
 
//         // if vertex u is not explored before
//         if (visited[u] == false) {
 
//             // mark present vertic as visited
//             visited[u] = true;
 
//             // mark its color opposite to its parent
//             col[u] = !col[v];
 
//             // if the subtree rooted at vertex v is not bipartite
//             if (!dfs(u))
//                 return false;
//         }
 
//         // if two adjacent are coled with same col then
//         // the graph is not bipartite
//         else if (col[u] == col[v])
//             return false;
//     }
//     return true;
// }

bool dfs(int i){
	for(auto el:adj[i]){
		if(!visited[el]){
			col[el]=1-col[i];
			visited[el]=1;
			if(!dfs(el)){
				log(i,el,1)
				return false;
			}
		}
		else{
			if(col[i]==col[el]){
				log(i,el,2)
				return false;
			}
		}
	}
	return true;
}


int32_t main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	tc{
		cin>>n>>m;
		adj.clear();
		adj.resize(n);
		col.clear();
		col.resize(n);
		col.assign(n,0);
		visited.clear();
		visited.resize(n);
		visited.assign(n,0);
		while(m--){
			int u,v;
			cin>>u>>v;
			u--,v--;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		loop(k,0,n-1){
			// cout<<k<<"----->";
			// logarr(adj[k],0,adj[k].size()-1);
			sort(adj[k].begin(), adj[k].end());
		}
		visited[0]=1;
		bool got=dfs(0);
		for(auto el:visited){
			if(el==0){
				got=0;
				break;
			}
		}
		// log(got);
		if(got){
			cout<<"YES"<<endl;
			int count=0;
			for(auto el:col){
				count+=el;
			}
			cout<<count<<endl;
			loop(i,0,n-1){
				if(col[i])cout<<i+1<<' ';
			}
			cout<<endl;
		}
		else
			cout<<"NO"<<endl;
	}

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
