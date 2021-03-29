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
#define tccc                    int ntc;cin>>ntc;while(ntc--)
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
	tccc{
		int n,e,h,a,b,c;
		cin>>n>>e>>h>>a>>b>>c;
		int cak=0,choc=0,oml=0;
		int finalAns=inf;
		for(int cake=0;cake<=n && cake<=e && cake<=h;cake++){
			cak=cake;
			choc=(h-cake)/3;
			oml=(e-cake)/2;
			if(choc+oml+cake>=n){
				vector<pii> v;
				v.pb({a,oml});
				v.pb({b,choc});
				v.pb({c,cak});
				sort(all(v));
				int count=0,ans=0;
				loop(i,0,2){
					if(count>=n)break;
					int req=min(v[i].ss,n-count);
					ans+=v[i].ff*req;
					count+=req;
				}



			// // log(cak,choc,oml)
			// 	//get the answer
			// 	int ans=0;
			// 	// log(cak,c,choc,b,oml,a)
			// 	//swap s.t a<=b<=c and make swappings such a way
			// 	int ta=a,tb=b,tc=c,tom=oml,tcak=cak,tchoc=choc;
			// 	if(a>b && a>c){
			// 		if(b>c){
			// 			c=ta,cak=tom,a=tc,oml=tcak;
			// 		}
			// 		else{
			// 			b=tc,choc=tcak,c=ta,cak=tom,a=tb,oml=tchoc;
			// 		}
			// 	}
			// 	else if(b>a && b>c){
			// 		if(a>c){
			// 			c=tb,cak=tchoc,b=ta,choc=tom,a=tc,oml=tcak;
			// 		}
			// 		else{
			// 			c=tb,cak=tchoc,b=tc,choc=tcak;
			// 		}
			// 	}
			// 	else if(c>a && c>b){
			// 		if(b>a){
			// 			c=tc;
			// 		}
			// 		else{
			// 			b=ta,choc=tom,a=tb,oml=tchoc;
			// 		}
			// 	}
			// 	log(cak,c,choc,b,oml,a)
			// 	int count=0;
			// 	ans+=min(oml,n-count)*a;
			// 	count+=min(oml,n-count);
			// 	// log(ans,count,1)
			// 	ans+=min(choc,n-count)*b;
			// 	count+=min(choc,n-count);
			// 	// log(ans,count,2)
			// 	ans+=min(cak,n-count)*c;
			// 	count+=min(cak,n-count);
			// 	// log(ans)
				finalAns=min(finalAns,ans);
			}
			else{
				//got nothing as answer
				continue;
			}
		}
		if(finalAns!=inf)cout<<finalAns<<endl;
		else cout<<"-1"<<endl;
	}

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
