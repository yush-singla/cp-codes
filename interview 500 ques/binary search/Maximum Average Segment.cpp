// Problem Link - https://codeforces.com/edu/course/2/lesson/6/4/practice/contest/285069/problem/A
//see solution here(very beautifully done)-https://codeforces.com/edu/course/2/lesson/6/4
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
int n,d;
vi arr;


//i have implemented just like in the problem 
//largest contigous sum with atleast k elements though
//it may be implemented otherwise also by method given in 
//the solution at above link but this allows for more conceptual clarity
pair<int,pii> good(double x){
	vector<double> a(n);
	vector <pair<double,int>> msxs(n);
	loop(i,0,n-1){
		a[i]=arr[i]-x;
	}
	double currSum=0;
	int currIndex=0;
	loop(i,0,n-1){
		msxs[i]=mp(currSum,currIndex);
		currSum+=a[i];
		if(currSum<0){
			currSum=0;
			currIndex=i+1;
		}
		// log(currSum)
	}
	// logarr(msxs,0,n-1)
	double windowSum=0,ans=-inf;
	pii anss;
	loop(i,0,d-1){
		windowSum+=a[i];
	}

	loop(i,d,n){
		// log(windowSum)
		if(ans<windowSum+msxs[i-d].ff){
			ans=windowSum+msxs[i-d].ff;
			// log(ans);
			anss=mp(msxs[i-d].ss,i-1);
			// log(i,i-d);
		}
		if(i>=n)break;
		windowSum+=arr[i];
		windowSum-=arr[i-d];
	}
	return mp(ans>=0,anss);
}

int32_t main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	//we can convert it to sigma(a[i]-x)>=0 see solution
	
	cin>>n>>d;
	int mx=0;
	arr.resize(n);
	for(auto &el:arr){
		cin>>el;
		mx=max(mx,el);
	}
	// auto gg=good(0);
	// log(gg.ss.ff,gg.ss.ss)
	double l=0,r=mx;
	pii ans;
	loop(k,0,100){
		double m=mid(l,r);
		// log(m);
		auto gg=good(m);
		if(gg.ff){
			l=m;
			ans=gg.ss;
		}
		else{
			r=m;
		}
		
	}
	cout<<ans.ff+1<<' '<<ans.ss+1;

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
