// Problem Link - https://codeforces.com/contest/1472/problem/E
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
		int n;
		cin>>n;
		std::vector<pair<pii,int>> val;
		vi answer(n,-3);
		std::vector<pii> prefixMinW(n,{inf,inf});
		loop(i,0,n-1){
			int x,y;
			cin>>x>>y;
			val.pb({{x,y},i+1});
		}
		sort(val.begin(), val.end());
		prefixMinW[0]={val[0].ff.ss,val[0].ss};
		//to get the min prefix for all the elements of the sorted 
		//array so that if we want to know at any point which element 
		//from all the elements has the least width upto this point we
		//can easily do so when applying binary search
		loop(i,1,n-1){
			if(val[i].ff.ss<prefixMinW[i-1].ff){
				prefixMinW[i]={val[i].ff.ss,val[i].ss};
			}
			else{
				prefixMinW[i]=prefixMinW[i-1];
			}
		}
		// loop(i,0,n-1){
		// 	log(i,val[i].ff.ff,val[i].ff.ss,prefixMinW[i].ff);
		// }
		//now just binary search a value of h for all the
		//values < curr and prefix will help us get the 
		//min width upto that point hence we can easily return the
		//correct ans
		loop(i,0,n-1){
			auto curr=val[i];
			int ans=-1;
			int l=0,r=n-1;
			while(l<=r){
				int m=mid(l,r);
				// log(m,l,r);
				auto el=val[m];
				if(el.ff.ff<curr.ff.ff){
					ans=m;
					l=m+1;
				}
				else{
					r=m-1;
				}
			}
			// log(i,ans)
			if(!(ans==-1 || prefixMinW[ans].ff>=curr.ff.ss)){
				answer[curr.ss-1]=prefixMinW[ans].ss;
			}
			else{
				// log(curr.ff.ff,curr.ff.ss);
				swap(curr.ff.ff,curr.ff.ss);
				// log(curr.ff.ff,curr.ff.ss);
				int ans=-1;
				//just binary search the whole array as the second value was
				//not really sorted we must hence make sure that 
				int l=0,r=n-1;
				while(l<=r){
					int m=mid(l,r);
					auto el=val[m];
					if(el.ff.ff<curr.ff.ff){
						ans=m;
						l=m+1;
					}
					else{
						r=m-1;
					}
				}
				// log(i,ans);
				if(!(ans==-1 || prefixMinW[ans].ff>=curr.ff.ss)){
					// cout<<"came here"<<endl;
					answer[curr.ss-1]=prefixMinW[ans].ss;
				}
				else answer[curr.ss-1]=-1;
			}
		}
		loop(i,0,n-1){
			cout<<answer[i]<<' ';
		}
		cout<<endl;
	}

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
