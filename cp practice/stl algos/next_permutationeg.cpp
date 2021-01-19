// Problem Link - https://www.codechef.com/UAPRAC/problems/RNDWAEZ
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
#define logarr(arr,a,b)	        for(int z=(a);z<=(b);z++) cout<<(arr[z].ff)<<" "<<(arr[z].ss)<<"\t";cout<<endl;	
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

int32_t main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	tc{
		int n;
		cin>>n;
		std::vector<pair<long double,long double>> v;
		while(n--){
			long double a,b;
			cin>>a>>b;
			v.pb(mp(a,b));
		}
		long double qx,qy,rx,ry;
		cin>>qx>>qy>>rx>>ry;
		long double dmax=sqrt((qx-rx)*(qx-rx)+(qy-ry)*(qy-ry));
		sort(v.begin(),v.end());
		long double count=0;
		long double totcount=0;
		do{
			long double currdis=sqrt((v[0].ff-rx)*(v[0].ff-rx)
				+(v[0].ss-ry)*(v[0].ss-ry));
			loop(i,1,v.size()-1){
				currdis+=sqrt((v[i].ff-v[i-1].ff)*(v[i].ff-v[i-1].ff)+
					(v[i].ss-v[i-1].ss)*(v[i].ss-v[i-1].ss));				
			}
			count+=(currdis<=dmax);
			totcount++;
			// logarr(v,0,v.size()-1);
			// log(currdis);
		}while(next_permutation(v.begin(), v.end()));
		// log(dmax,count,totcount);
		long double ans=count*1.0/totcount;
		cout<<ps(ans,8)<<endl;
	}

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
