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
//noot space optimised 
void threeWayPartition2(vector<int>& arr,int a, int b)
    {
        // code here 
        int n=arr.size();
        vi n1,n2,n3;
        int aa=0,bb=0;
        for(auto el:arr){
        	if(el<a){
        		n1.pb(el);
        	}
        	else if(el>a&&el<b){
        		n2.pb(el);
        	}
        	else if(el>b){
        		n3.pb(el);
        	}
        	if(el==a)
        		aa++;
        	if(el==b)
        		bb++;
        }
        arr.clear();
        for(auto el:n1){
        	arr.pb(el);
        }
        while(aa--)
        arr.pb(a);
        for(auto el:n2){
        	arr.pb(el);
        }
        while(bb--)
        arr.pb(b);
        for(auto el:n3){
        	arr.pb(el);
        }

    }

//we can also optimise the space needed using a quick sort like algo
//where pivot does the similar task as we are intending to do

void threeWayPartition(vector<int>& arr,int a, int b)
    {
        // code here 
    	int n=arr.size();
    	//this is dutch quick sort pivotiing hence we will
    	//do it llike this 
    	//put bigger elemenets at last and smaller at front 
    	//not midle automatically takes their postition 
    	//very impt algo for 3 way partitioning
    	int st=0,en=n-1;
    	for(int i=0;i<=en;){
    		if(arr[i]<a){
    			swap(arr[st],arr[i]);
    			st++,i++;
    		}
    		else if(arr[i]>b){
    			swap(arr[en],arr[i]);
    			en--;
    		}
    		else{
    			i++;
    		}
    	}
    }

int32_t main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int n;
	cin>>n;
	vi arr(n);
	for(auto &el:arr){
		cin>>el;
	}
	int a,b;
	cin>>a>>b;
	threeWayPartition(arr,a,b);
	logarr(arr,0,arr.size()-1)

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
