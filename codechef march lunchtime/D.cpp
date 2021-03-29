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
#define mod                     998244353 
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


int exponentMod(int A, int B, int C=mod) 
{ 
    // Base cases 
    if (A == 0) 
        return 0; 
    if (B == 0) 
        return 1; 
  
    // If B is even 
    long y; 
    if (B % 2 == 0) { 
        y = exponentMod(A, B / 2, C); 
        y = (y * y) % C; 
    } 
  
    // If B is odd 
    else { 
        y = A % C; 
        y = (y * exponentMod(A, B - 1, C) % C) % C; 
    } 
  
    return (int)((y + C) % C); 
} 

class union_find
{
	int n;
	vector<int> par;
	vector<int> sz;
public:
	int dist;
	union_find(int nval)
	{
		n = nval;
		dist=nval;
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
		dist--;
		par[ra] = rb;
		sz[rb] += sz[ra];
	}
};



int32_t main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	tc{
		int c,n,m;
		cin>>c>>n>>m;
		std::vector<vector<pii>> v(c);
		vector<pii> pp;
		vector<pair<pii,int>> ppp;
		loop(i,0,c-1){
			int x;
			cin>>x;
			loop(j,0,x-1){
				int l,r;
				cin>>l>>r;
				l--,r--;
				v[i].pb({l,r});
				ppp.pb({{l,r},i});
				pp.pb({l,r});
			}
		}	
		union_find dsu(c);
		// loop(i,0,c-2){
		// 	vector<pii> nww;
		// 	for(auto el:v[i]){
		// 		nww.pb(el);
		// 	}
		// 	for(auto el:v[i+1]){
		// 		nww.pb(el);
		// 	}
		// 	sort(all(nww));
		// 	loop(j,0,nww.size()-2){
		// 		if(nww[j+1].ff<=nww[j].ss){
		// 			dsu.un(i,i+1);
		// 			break;
		// 		}
		// 	}
		// }
		int uniquests=0;
		sort(all(pp));
		sort(all(ppp));
		int tot=n,st=pp[0].ff;
		int rm=0;
		loop(i,0,pp.size()-1){
			// log(pp[i].ff,pp[i].ss)
			rm=max(pp[i].ss,rm);
			if(i==pp.size()-1 || pp[i+1].ff>rm){
				tot-=rm-st+1;
				// log(tot)
				if(i!=pp.size()-1)
				st=pp[i+1].ff;
			}
		}
		uniquests=tot;
		int rmost=0;
		loop(i,0,ppp.size()-2){
			rmost=max(ppp[i].ff.ss,rmost);
			if(rmost>=ppp[i+1].ff.ff){
				// log(ppp[i].ss,ppp[i+1].ss);
				dsu.un(ppp[i].ss,ppp[i+1].ss);
			}
		}
		int uniqueClubs=dsu.dist;
		int ans=((exponentMod(m,uniquests))%mod*exponentMod(m,uniqueClubs)%mod)%mod;
		cout<<ans<<endl;
		// log(uniquests,uniqueClubs)
	}

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
