// Problem Link - https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
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


//here there are many many possibilities which we need to consider
//as each element may have +k or -k so we store all 
//nos with each +k and -k into an array such that
//we cover all the possibilities. now we will just 
//store them with proper index such that we can use 2 pointer
//where we move right till atleast one occurrence of each char comes
//then we move left till one char goes missing and simel
//update the ans for our future use

int getMinDiff(vi &arr, int n, int k) {
    // code here
    vector<pii> allPoss;
    loop(i,0,n-1){
    	if(arr[i]-k>=0)
    		allPoss.pb({arr[i]-k,i});
    	allPoss.pb({arr[i]+k,i});
    }
    int count=0;
    vi visited(n,0);
    sort(allPoss.begin(), allPoss.end());
    int ans=allPoss[allPoss.size()-1].ff-allPoss[0].ff;
    int left=0,right=0;
    for(int left=0;right<=allPoss.size();){
    	if(right==allPoss.size()){
    		if(count==n)
    		ans=min(ans,allPoss[right-1].ff- allPoss[left].ff);
    		break;
    		// log(ans)
    	}
    	if(count==n){
    		ans=min(ans,allPoss[right-1].ff- allPoss[left].ff);
    		visited[allPoss[left].ss]--;
    		if(visited[allPoss[left].ss]==0)
    			count--;
    		left++;
    	// log(ans);
    	}
    	else{
    		if(visited[allPoss[right].ss]==0){
    			count++;
    		}
   			visited[allPoss[right].ss]++;
   			right++;
    	}
    	// log(left,right)
    }
    return ans;
}

int32_t main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int k,n;
	cin>>k>>n;
	vi arr(n);
	for(auto &el:arr){
		cin>>el;
	}
	cout<<getMinDiff(arr,n,k);
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
