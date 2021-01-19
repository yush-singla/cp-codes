// Problem Link - https://www.codechef.com/problems/MOSTDIST
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
#define pb				        push_back
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

class compare1{
public:
	bool operator()(pair<pii,int>a,pair<pii,int>b){
		return(a.ff.ss+a.ff.ff>b.ff.ss+b.ff.ff);
	}
};
class compare2{
public:
	bool operator()(pair<pii,int>a,pair<pii,int>b){
		return(a.ff.ss-a.ff.ff>b.ff.ss-b.ff.ff);
	}
};
class compare3{
public:
	bool operator()(pair<pii,int>a,pair<pii,int>b){
		return(a.ff.ss-a.ff.ff<b.ff.ss-b.ff.ff);
	}
};
class compare4{
public:
	bool operator()(pair<pii,int>a,pair<pii,int>b){
		return(a.ff.ss+a.ff.ff<b.ff.ss+b.ff.ff);
	}
};

int32_t main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int q;
	cin>>q;
	priority_queue<pair<pii,int>,vector<pair<pii,int>>,compare1> smax;
	priority_queue<pair<pii,int>,vector<pair<pii,int>>,compare2> dmax;
	priority_queue<pair<pii,int>,vector<pair<pii,int>>,compare3> dmin;
	priority_queue<pair<pii,int>,vector<pair<pii,int>>,compare4> smin;
	unordered_set<int> deleted;

	int n=1,answer=0;
	while(q--){
		char ch;
		cin>>ch;
		if(ch=='+'){
			int a,b;
			cin>>a>>b;
			a^=answer;
			b^=answer;
			smax.push(mp(mp(a,b),n));
			dmax.push(mp(mp(a,b),n));
			smin.push(mp(mp(a,b),n));
			dmin.push(mp(mp(a,b),n));
			n++;
		}
		else if(ch=='-'){
			int a;
			cin>>a;
			a^=answer;
			deleted.insert(a);
		}
		else if(ch=='?'){
			int a,b;
			cin>>a>>b;
			a^=answer;
			b^=answer;
			while(deleted.count(smax.top().ss)){
				smax.pop();
			}
			while(deleted.count(dmax.top().ss)){
				dmax.pop();
			}
			while(deleted.count(dmin.top().ss)){
				dmin.pop();
			}
			while(deleted.count(smin.top().ss)){
				smin.pop();
			}
			int ans1=abs(smax.top().ff.ff+smax.top().ff.ss-a-b);
			int ans2=abs(dmax.top().ff.ff-dmax.top().ff.ss-a+b);
			int ans3=abs(dmin.top().ff.ff-dmin.top().ff.ss-a+b);
			int ans4=abs(smin.top().ff.ff+smin.top().ff.ss-a-b);
			answer=max(max(ans1,ans2),max(ans3,ans4));
			cout<<answer<<endl;
		}
	}

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
