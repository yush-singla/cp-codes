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
int n,m,k;
vector<vector<pii>> adj;
int getPos(int i,int j){
	return i*m+j;
}
bool valid(int i,int j){
	return i>=0 && j>=0 && i<n && j<m;
}

int dijkstra(int s,int curr,int *cap) {
    int no = adj.size();
    vi d(no, inf);
    vi p(no, -1);

    d[s] = 0;
    // using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
            // log(to,len,cap[to],curr);
            if(curr>cap[v]-len){
            	continue;
            }
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
    return d[no-1];
}



int32_t main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	tc{
		adj.clear();
		cin>>n>>m>>k;
		adj.resize(m*n);
		int arr[n][m];
		int cap[n*m];
		int dir[n][m];
		loop(i,0,n-1){
			loop(j,0,m-1){
				cin>>arr[i][j];
				cap[getPos(i,j)]=arr[i][j];
			}
		}
		loop(i,0,n-1){
			loop(j,0,m-1){
				char ch;
				cin>>ch;
				if(ch=='U'){
					dir[i][j]=3;
				}else if(ch=='D'){
					dir[i][j]=1;
				}else if(ch=='R'){
					dir[i][j]=0;
				}else if(ch=='L'){
					dir[i][j]=2;
				}
			}
		}
		pii moves[4]={{0,1},{1,0},{0,-1},{-1,0}};//R,D,L,U
		for(auto el:moves){
			// log(el.ff,el.ss)
		}
		loop(i,0,n-1){
			loop(j,0,m-1){
				int wt=0;
				int stIndex=dir[i][j];
				loop(k,0,3){
					pii st=moves[stIndex];
					// log(i+st.ff,j+st.ss);
					if(valid(i+st.ff,j+st.ss)){
						// cout<<"adding between "<<i<<','<<j<<" and "<<i+st.ff<<','<<j+st.ss<<"of weight= "<<wt<<endl;
						adj[getPos(i,j)].pb({getPos(i+st.ff,j+st.ss),wt});
						// adj[getPos(i+st.ff,j+st.ss)].pb({getPos(i,j),wt});
					}
					stIndex++;
					stIndex%=4;
					wt++;
				}
			}
		}
		// loop(i,0,m*n-1){
		// 	cout<<i<<"----->";
		// 	for(auto el:adj[i]){
		// 		cout<<el.ff<<'-'<<el.ss<<' ';
		// 	}
		// 	cout<<endl;
		// }
		// int bn=3;
		// int dis=dijkstra(0,bn,cap);
		// log(dis)

		int l=0,r=1e9+1;
		int ans=-1;
		while(l<=r){
			int m=mid(l,r);
			// log(m);
			if(dijkstra(0,m,cap)<=k){
				ans=m;
				l=m+1;
			}
			else{
				r=m-1;
			}
		}
		// log(ans);
		if(ans==-1){
			ans=0;
		}
		cout<<ans<<endl;
	}

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
