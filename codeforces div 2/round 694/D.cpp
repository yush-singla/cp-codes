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
	const int N = 1000006;
	int lp[N+1]={0};
	vector<int> pr;

	for (int i=2; i<=N; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back (i);
	    }
	    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
	        lp[i * pr[j]] = pr[j];
	}
	//to find the perfect squares this is a neat trick
	//where we just take the prime factor form 
	//and in that we take mod 2 so that the nos 
	//which are same afterwards are definitely 
	//going to give a perfect square 
	//from there it is easy since if any no comes 
	//odd times it'll remain imperfect square always 
	//but if it comes even times it will become 1 in 
	//next iteration and after 0 and 1 iterations 
	//no furthher changes shall occur in the array
	tc{
		int n;
		cin>>n;
		vi arr(n);
		for(auto &el:arr){
			cin>>el;
		}
		int q;
		cin>>q;
		vi query(q);
		for(auto &el:query){
			cin>>el;
		}
		ump<int ,int> m;
		for(auto el:arr){
			auto og=el;
			ump<int,int>prieFactorForm;
			while(el>1){
				prieFactorForm[lp[el]]++;
				el/=lp[el];
			}
			int ans=1;
			for(auto ell:prieFactorForm){
				// ell.ss=ell.ss%2;
				// log(ell.ff,ell.ss)
				ans*=pow(ell.ff,ell.ss%2);
			}
			// log(ans);
			m[ans]++;
		}
		int dmx0=0,dmx1=0,ones=m[1];
		for(auto el:m){
			dmx0=max(dmx0,el.ss);
		}
		for(auto &el:m){
			if(el.ss%2==0 && el.ff!=1){
				m[1]+=el.ss;
				el.ss=0;
			}
		}
		for(auto el:m){
			dmx1=max(dmx1,el.ss);
		}
		// log(dmx0,dmx1)
		for(auto el:query){
			if(el==0){
				// log(el)
				cout<<dmx0<<endl;
			}
			else cout<<dmx1<<endl;
		}
	}

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
