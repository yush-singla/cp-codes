// Problem Link - https://codeforces.com/contest/1433/problem/G
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
#define iPair                   pair<int,int>
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
std::vector<std::vector<pii>> adj;
vector<pair<pii,int>> edges;
std::vector<pii> rt;	

void shortestPath(int src,vi &dist) 
{ 
    // Create a priority queue to store vertices that 
    // are being preprocessed. This is weird syntax in C++. 
    // Refer below link for details of this syntax 
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/ 
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
  
    // Create a vector for distances and initialize all 
    // distances as infinite (INF) 
  
    // Insert source itself in priority queue and initialize 
    // its distance as 0. 
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
  
    /* Looping till priority queue becomes empty (or all 
      distances are not finalized) */
    while (!pq.empty()) 
    { 
        // The first vertex in pair is the minimum distance 
        // vertex, extract it from priority queue. 
        // vertex label is stored in second of pair (it 
        // has to be done this way to keep the vertices 
        // sorted distance (distance must be first item 
        // in pair) 
        int u = pq.top().second; 
        pq.pop(); 
  
        // 'i' is used to get all adjacent vertices of a vertex 
        for (auto el:adj[u]) 
        { 
            // Get vertex label and weight of current adjacent 
            // of u. 
            int v = el.first; 
            int weight = el.second; 
  
            //  If there is shorted path to v through u. 
            if (dist[v] > dist[u] + weight) 
            { 
                // Updating distance of v 
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 
  
    // // Print shortest distances stored in dist[] 
    // printf("Vertex   Distance from Source\n"); 
    // for (int i = 0; i < V; ++i) 
    //     printf("%d \t\t %d\n", i, dist[i]); 
} 




int32_t main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int n,m,k;
	cin>>n>>m>>k;
	adj.resize(n);
	vector<vi> wt;
	wt.resize(n);
	loop(i,0,m-1){
		int x,y,w;
		cin>>x>>y>>w;
		x--,y--;
		adj[x].pb({y,w});
		adj[y].pb({x,w});
		edges.pb({{x,y},w});
		// wt[x][y]=w;
		// wt[y][x]=w;
	}
	loop(i,0,n-1){
		wt[i].resize(n);
		loop(j,0,n-1){
			wt[i][j]=mod;
			if(i==j)
				wt[i][j]=0;
		}
	}
	//all pair shortest path using floyd warshall algo also we can do but it is n3
	//since here edges are n only we can just use dijksteas n times its better
	loop(i,0,n-1){
		shortestPath(i,wt[i]);
		// wt[i][i]=0;
	}
	// loop(i,0,n-1){
	// 	loop(j,0,n-1){
	// 		cout<<wt[i][j]<<' ';
	// 	}
	// 	cout<<endl;
	// }
	loop(i,0,k-1){
		int x,y;
		cin>>x>>y;
		x--,y--;
		rt.pb({x,y});
	}
	int finalAns=inf;
	for(auto ell:edges){
		// cout<<"CAME";
		auto el=ell.ff;
		int currAns=0;
		//making current edge to be 0
		for(auto rtt:rt){
			// cout<<"HERE";
			// log(rtt.ff,rtt.ss);
			currAns+=min(wt[rtt.ff][rtt.ss],min(wt[rtt.ff][el.ff]+wt[el.ss][rtt.ss],wt[rtt.ff][el.ss]+wt[el.ff][rtt.ss]));
		}
		// log(currAns,el.ff,el.ss);
		finalAns=min(finalAns,currAns);
	}
	cout<<finalAns<<endl;
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
