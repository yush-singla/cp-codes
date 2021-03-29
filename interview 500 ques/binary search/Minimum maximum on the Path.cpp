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
int n,m,d;
bool bfs(int val,vector<vector<pii>> &adj,vi &pr,int st=0){
	int lvl=0;
	queue<int> q;
	vi vst(n,0);
	q.push(st);
	q.push((int)-1000);
	vst[st]=1;
	// logarr(vst,0,n-1);
	while(!q.empty()){
		int frnt=q.front();
		q.pop();
		if(frnt==-1000){
			if(!q.empty()){
				lvl++;
				q.push((int)-1000);
			}
			continue;
		}
		// vst[frnt]=1;
		if(lvl>=d)
			return false;
		for(auto el:adj[frnt]){
			if(!vst[el.ff] && el.ss<=val){
				// log(frnt+1,el.ff+1,lvl);
				q.push(el.ff);
				pr[el.ff]=frnt;
				vst[el.ff]=1;
				if(el.ff==n-1 && lvl<d){
					// if(val==5)log(lvl);
					return true;
				}
			}
		}
	}
	return false;
}

int32_t main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....		
		//just applied bfs on the ans with binary search
		cin>>n>>m>>d;
		// log(n,m,d)
		vector<vector<pii>> adj(n);
		int r=0;
		loop(i,0,m-1){
			int a,b,c;
			cin>>a>>b>>c;
			a--,b--;
			adj[a].pb({b,c});
			// adj[b].pb({a,c});
			// r=max(r,c);
		}
		int l=1;
		r=10000000009;
		vi ans;
		int xx=-1;
		// bfs(5,adj,ans);
		while(l<=r){
			int mi=mid(l,r);
			vi pr(n,-1);
			if(bfs(mi,adj,pr)){
				ans=pr;
				xx=mi;
				r=mi-1;
			}
			else{
				l=mi+1;
			}
		}
		// logarr(ans,0,n-1);
		// log(xx)
		vi final;
		// // final.pb(n-1);
		if(xx==-1){
			cout<<"-1"<<endl;
			// return 0;
		}
		else{
			int st=n-1;
			while(st!=0){
				final.pb(st);
				// log(st);
				st=ans[st];
			}
			reverse(all(final));
			cout<<final.size()<<endl;
			cout<<"1 ";
			for(auto el:final){
				cout<<el+1<<' ';
			}
			// cout<<endl;
		}

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
