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

int32_t main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	tc{
		int n,k;
		cin>>n>>k;
		vi arr(n);
		for(auto &el:arr){
			cin>>el;
		}
		int totcount=0,windowCount=0,minWindowCount=0;
		// pii minCountIndex=mp(0,k-1);
		loop(i,0,k-1){
			totcount+=arr[i];
			windowCount+=arr[i];			
		}
		minWindowCount=windowCount;
		loop(i,k,n-1){
			totcount+=arr[i];
			windowCount+=arr[i]-arr[i-k];
			minWindowCount=min(minWindowCount,windowCount);	
		}
		// log(minWindowCount)
		int ans=((minWindowCount)*(minWindowCount+1))/2+(totcount- minWindowCount);
		cout<<ans<<endl;
	}

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
