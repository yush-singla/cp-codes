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

int n,m;
std::vector<vector<pii>>adj;

// bool dfs(int st,double x,double sum,vi &vst,vi &pr){
// 	if(st==n-1 && sum<=0){
// 		return true;
// 	}
// 	else if(st==n-1 && sum>0){
// 		// log(sum)
// 		return false;
// 	}
// 	vst[st]=1;
// 	bool b=false;
// 	for(auto el:adj[st]){
// 		if(!vst[el.ff]){
// 			pr[el.ff]=st;
// 			b=dfs(el.ff,x,sum+el.ss-x,vst,pr);
// 			if(b)return true;
// 		}
// 	}
// 	// vst[st]=0;
// 	return false;
// }

// bool dijUtil(int x){

// }
bool bfs(double x,vector<double> &summ,vi &pr){
	// queue<int> q;
	// vi inq(n,0);
	// q.push(st);
	// summ[st]=0;
	summ[0]=0;
	// inq[st]=1;
	/*while(!q.empty()){
		int frnt=q.front();
		q.pop();
		for(auto el:adj[frnt]){
			if(summ[el.ff]>summ[frnt]+el.ss-x){
				summ[el.ff]=summ[frnt]+el.ss-x;
				pr[el.ff]=frnt;
				if(!inq[el.ff]){
					q.push(el.ff);
					inq[el.ff]=1;
				}
			}
		}
	}*/
	//here we cant use the typical bfs since there is
	//nothing as vsted here as we may go and do 
	//however many rounds we feel like 
	//so we use fact that each edge only goes towards the
	//bigger edge and solve it easily using dp since
	//we can iterate and get the min poss weight used to 
	//reach that edge very easily !
	loop(frnt,0,n-1){
		if(summ[frnt]==inf){
			continue;
		}
		for(auto el:adj[frnt]){
			// log(summ[frnt]);
			if(summ[el.ff]>summ[frnt]+el.ss-x){
				summ[el.ff]=summ[frnt]+el.ss-x;
				pr[el.ff]=frnt;
			}
		}
	}
	// log(summ[n-1]);
	return summ[n-1]<=0;
}

int32_t main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	cin>>n>>m;
	adj.resize(n);
	// log(m,n)
	// loop(i,0,n-1){
	// 	cout<<i+1<<"---------->";
	// 	for(auto el:adj[i]){
	// 		cout<<el.ff<<' ';
	// 	}
	// 	cout<<endl;
	// }
	loop(i,0,m-1){
		int a,b,c;
		cin>>a>>b>>c;
		// if(a>b)swap(a,b);
		// log(a,b,c);
		// log(a,b)
		a--,b--;
		adj[a].pb({b,c});
	}
	loop(i,0,n-1){
		sort(all(adj[i]));
	}
	// loop(i,0,n-1){
	// 		cout<<i+1<<"---------->";
	// 	for(auto el:adj[i]){
	// 		cout<<el.ff+1<<'-'<<el.ss<<' ';
	// 	}
	// 	cout<<endl;
	// }
	vi prF(n,-1);
	// vi vst(n,0),pr(n,-1);
	// log(dfs(0,1.9,0,vst,pr))
	double l=0,r=100;
	loop(iko,1,61){
		double m=mid(l,r);
		vi pr(n,-1);
		vector<double> vst(n,inf);
		if(bfs(m,vst,pr)){
		// if(dijUtil(m))
			prF=pr;
			r=m;
		}
		else{
			l=m;
		}
		// log(m);
	}
	// logarr(prF,0,n-1);
	vi final;
	int st=n-1;
	while(st!=-1){
		final.pb(st);
		st=prF[st];
	}
	reverse(all(final));
	// logarr(final,0,final.size()-1)
	cout<<final.size()-1<<endl;
	for(auto el:final){
		cout<<el+1<<' ';
	}

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
