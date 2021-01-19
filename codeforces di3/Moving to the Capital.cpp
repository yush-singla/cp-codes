// Problem Link - https://codeforces.com/contest/1472/problem/G
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
// ump<int,int> dist;
vi dist,revdist,dp;
std::vector<vi> adj,revadj;
int n,m;

/*void dij(){
	vi visited(n,0);
	dist.resize(n);
	loop(i,0,n-1){
		dist[i]=inf;
	}
	priority_queue<pii,std::vector<pii>,greater<pii>> ps;
	dist[0]=0;
	ps.push({dist[0],(int)0});
	while(!ps.empty()){
		pii el=ps.top();
		ps.pop();
		if(visited[el.ss])
			continue;
		visited[el.ss]=1;
		for(auto vertice:adj[el.ss]){
			if(dist[el.ss]!=inf && dist[el.ss]+1<dist[vertice]){
				dist[vertice]=dist[el.ss]+1;
				ps.push({dist[vertice],vertice});
			}
		}
	}
}*/
void bfs1(){
	vi visited(n,0);
	//apply bfs from 0th node
	dist.resize(n);
	queue<int> q;
	q.push((int)0);
	q.push((int)-1);
	visited[0]=1;
	int lv=1;
	while(!q.empty()){
		int top=q.front();
		q.pop();
		if(top==-1){
			if(q.empty())
				break;
			else{
				q.push((int)-1);
				lv++;
				continue;
			}
		}
		for(auto el:adj[top]){
			if(!visited[el]){
				dist[el]=lv;
				visited[el]=1;
				q.push(el);
			}
		}

	}
}
void bfs2(){
	vi visited(n,0);
	//apply bfs from 0th node
	revdist.resize(n);
	loop(i,1,n-1){
		revdist[i]=inf;
	}
	queue<int> q;
	q.push((int)0);
	q.push((int)-1);
	visited[0]=1;
	int lv=1;
	while(!q.empty()){
		int top=q.front();
		q.pop();
		if(top==-1){
			if(q.empty())
				break;
			else{
				q.push((int)-1);
				lv++;
				continue;
			}
		}
		for(auto el:revadj[top]){
			if(!visited[el]){
				revdist[el]=lv;
				visited[el]=1;
				q.push(el);
			}
		}

	}
}
void dfs(int i,vi &visited){
	visited[i]=1;
	for(auto el:adj[i]){
		if(!visited[el]&&dist[el]>dist[i]){
			dfs(el,visited);
		}
		if(dist[el]>dist[i]){
			dp[i]=min(dp[i],dp[el]);
		}
		else{
			dp[i]=min(dp[i],dist[el]);
		}
	} 
}


int32_t main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	tc{
		cin>>n>>m;
		dist.clear();
		adj.clear();
		revadj.clear();
		adj.resize(n);
		revadj.resize(n);
		loop(i,0,m-1){
			int u,v;
			cin>>u>>v;
			u--,v--;
			adj[u].pb(v);
			revadj[v].pb(u);
		}
		bfs1();
		// bfs2();
		// logarr(dist,0,n-1);
		dp.clear();
		dp.resize(n);
		dp[0]=0;
		loop(i,1,n-1){
			dp[i]=dist[i];
		}
		// logarr(revdist,0,n-1);
		// std::vector<pii> vec;
		// loop(i,1,n-1){
		// 	vec.pb({revdist[i],i});
		// }
		// sort(vec.begin(), vec.end());
		// for(auto ee:vec){
		// 	log(ee.ff,ee.ss);
		// }
		/*for(auto ee:vec){
			for(auto ele:adj[ee.ss]){
				//no super pwer needed 
				if(dist[ele]>dist[ee.ss]){
					dp[0][ee.ss]=min(dp[0][ee.ss],dp[0][ele]);
					dp[1][ee.ss]=min(dp[1][ee.ss],dp[1][ele]);
				}
				//super pwer is must here to be used 
				else{
					dp[1][ee.ss]=min(dp[1][ee.ss],dp[0][ele]);
				}
			} 
		}*/
		vi visited(n,0);
		dfs(0,visited);
		loop(i,0,n-1){
			cout<<dp[i]<<" ";
		}
		cout<<endl;

	}

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
