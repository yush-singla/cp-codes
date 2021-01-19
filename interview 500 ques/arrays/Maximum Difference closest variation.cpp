// Problem Link - https://practice.geeksforgeeks.org/problems/maximum-difference-1587115620/1
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
//we mantain a stack to get the closest smallest element
//this helps us achieve the goal in o(n) only!!
int findMaxDiff(vi &arr, int n){
  //Your code here
  int ls[n]={0};
  int rs[n]={0};
  stack<int> st;
  int mnr=0,mnl=0;
  for(int i=0;i<n;i++){
      if(st.empty()){
      	ls[i]=0;
      }
      else{
      	while(!st.empty() && st.top()>=arr[i]){
      		st.pop();
      	}
      	if(!st.empty())
      	ls[i]=st.top();
      	else ls[i]=0;
      }
      st.push(arr[i]);
  }
  reverse(arr.begin(), arr.end());
  //clEAR THE STACK here to get the proper elements
  while(!st.empty()) st.pop();
  for(int i=0;i<n;i++){
      if(st.empty()){
      	rs[i]=0;
      }
      else{
      	while(!st.empty() && st.top()>=arr[i]){
      		st.pop();
      	}
      	if(!st.empty())
      	rs[i]=st.top();
      	else rs[i]=0;
      }
      st.push(arr[i]);
  }
  // logarr(ls,0,n-1);
  // logarr(rs,0,n-1);
  // logarr(arr,0,n-1);
  int ans=0;
  for(int i=0;i<n;i++){
  	ans=max(ans,abs(ls[i]-rs[n-1-i]));
  }
  return ans;

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
	cout<<findMaxDiff(arr,n)<<endl;
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
