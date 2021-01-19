// Problem Link - 
/* By Yush singla */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
// #define int 		            long long 
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


//here we have used bianry search to get the index needed
//since here we need the left of our index to less than or equal
//to the prev vals second(max of all prefix vals) so keping that in mind we calculate the next 
//index and only push in vector when there are no more indexes that can be added
//we need to mantain a max prefix vals since at any point we may need to 
//use it 
vector<pair<int,int>> overlappedInterval1(vector<pair<int,int>> vec, int n) {
    //code here
    vector<pii> ans;
    vi prefixMaxR(n);
    sort(all(vec));
    prefixMaxR[0]=vec[0].ss;
    loop(i,1,n-1){
    	prefixMaxR[i]=max(prefixMaxR[i-1],vec[i].ss);

    }

    for(auto &el:vec){
		cout<<el.ff<<' '<<el.ss<<endl;
	}
    int count=0;
    for(int i=0;i<n && count<10;){
    	// log(i);
    	int boundary;
    	int l=i,r=n-1;
    	while(l<=r){
    		int m=mid(l,r);
    		if(vec[m].ff<=prefixMaxR[i]){
    			boundary=m;
    			l=m+1;
    		}
    		else{
    			r=m-1;
    		}
    	}
    	
    	if(boundary==i){
    		ans.pb(vec[i]);
    		log(i,boundary)
    		i++;
    	}
    	else{
    		int initI=i;
	    	while(i!=boundary){
	    		i=boundary;
		    	l=boundary,r=n-1;
		    	while(l<=r){
		    		int m=mid(l,r);
		    		if(vec[m].ff<=prefixMaxR[i]){
		    			boundary=m;
		    			l=m+1;
		    		}
		    		else{
		    			r=m-1;
		    		}
		    	}
		    	// cout<<"w";
		    	// log(i,boundary)
		    	count++;
	    	}
	    	ans.pb({vec[initI].ff,prefixMaxR[i]});
	    	log(i,boundary,prefixMaxR[i],initI)
	    	i++;
    	}
    	log(prefixMaxR[14])
    	count++;
    	// log(count)
    }
    return ans;
}


//once we sort the array we just need to check if the next
//value is colliding or not becoz if it is not colliding 
//and keep a range of max and min vals so that we are able
//to get full range (it is easier than the above solution)
vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> arr, int n) {
    //code here
    std::vector<pii> v;
    sort(all(arr));
    int currL=arr[0].ff,currR=arr[0].ss;
    bool lastDone=0;
    for(int i=0;i<n-1;i++){
    	if(arr[i+1].ff<=currR){
    		currL=min(currL,arr[i].ff);
    		currR=max(currR,arr[i+1].ss);
    		lastDone=1;
    		if(i==n-2){
    			v.pb({currL,currR});
    		}
    	}
    	else{
    		v.pb({currL,currR});
    		currL=arr[i+1].ff,currR=arr[i+1].ss;
    		lastDone=0;
    	}
    }
    if(!lastDone){
    	v.pb(arr[n-1]);
    }
    return v;
}


int32_t main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int n;
	cin>>n;
	std::vector<pii> arr(n),v;
	for(auto &el:arr){
		cin>>el.ff>>el.ss;
	}
	v=overlappedInterval(arr,n);

	for(auto el:v){
		cout<<el.ff<<' '<<el.ss<<endl;
	}
	// sort(all(arr));
	// auto i=upper_bound(arr.begin(),arr.end(),mp(1,0))-arr.begin();
	// cout<<i;
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
