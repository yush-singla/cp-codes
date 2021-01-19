// Problem Link - https://www.pepcoding.com/most-important-interview-questions-list-for-product-based-companies
/* By Yush singla */
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;
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
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> pbds;
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
//here we make use of pbds since repeated vals are allowed 
//we need to take care of it be making a pair also while
//getting order we must take the inf as second since
//we want to include the same if not do 0 instead
int inversionCount1(vi &arr, int n)
{
    // Your Code Here
    int ans=0;
    pbds a;
    for(int i=0;i<n;i++){
    	ans+=i-a.order_of_key({arr[i],inf});
    	// log(arr[i],ans,i,a.order_of_key({arr[i],inf}));
    	a.insert({arr[i],i});
    }
    return ans;

}

int inversionCount(int *arr, int n)
{
    // Your Code Here
    if(n==1 || n==0){
    	return 0;
    }
    int inv1=inversionCount(arr,n/2);
    int inv2=inversionCount(arr+n/2,n-n/2);
    int i=0,j=n/2,k=0,inv3=0;
    int a[n];
    while(i<n/2 && j<n){
    	//if arr[i] is bigger than all the further element then
    	//we can say all next elments are also bigger hence we get
    	//this statement also now as the smaller element arr[j] 
    	//is being pushed into the array a so there is no chance of rep
    	//as well
    	if(arr[i]>arr[j]){
    		a[k++]=arr[j++];
    		inv3+=n/2-i;
    	}
    	else{
    		a[k++]=arr[i++];
    	}
    }
    while(i<n/2){
    	a[k++]=arr[i++];
    }
    while(j<n){
    	a[k++]=arr[j++];
    }
    for(i=0;i<n;i++){
    	arr[i]=a[i];
    }
    
    return inv1+inv2+inv3;
}

int32_t main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n;
	cin>>n;
	int *arr=new int[n];
	
	loop(i,0,n-1){
		cin>>arr[i];
	}
	cout<<inversionCount(arr,n)<<endl;
	// sort(all(arr));
	// logarr(arr,0,arr.size()-1)
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
