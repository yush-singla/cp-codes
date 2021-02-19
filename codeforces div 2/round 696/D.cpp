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
	tc{
		int n;
		cin>>n;
		vi a(n);
		for(auto &el:a){
			cin>>el;
		}
		int i;
		vi arr=a;
		vi dpPrefix(n,-1),dpSuffix(n,-1);
		dpPrefix[0]=arr[0];
		dpSuffix[n-1]=arr[n-1];
		for(i=0;i<n-1;i++){
			if(arr[i]>arr[i+1]){
				// log(i,arr[i]);
				break;
			}
			arr[i+1]-=arr[i];
			dpPrefix[i+1]=arr[i+1];
			arr[i]=0;
		}
		if(i==n-1 && arr[n-1]==0){
			cout<<"YES"<<endl;
			continue;
		}
		arr=a;
		int j;
		for(j=n-1;j>=1;j--){
			if(arr[j]>arr[j-1]){
				// log(j,arr[j])
				break;
			}
			arr[j-1]-=arr[j];
			// log(arr[j-1],arr[j]);
			dpSuffix[j-1]=arr[j-1];
			arr[j]=0;
		}
		// logarr(dpPrefix,0,n-1);
		// logarr(dpSuffix,0,n-1)
		arr=a;
		bool got=0;
		loop(i,0,n-2){
			//swapping of i and i+1 elements
			//just make sure that correspoinding
			//dps are not -1 since it may interfere with the
			//the question so either set them -inf or check
			//properly
			if(i==0){
				if(dpSuffix[i+2]==-1)
					continue;
				int t1=arr[i],t2=arr[i+1];
				swap(t1,t2);
				if(t1>t2)
					continue;
				t2-=t1;
				t1=0;
				// log(t1,t2,dpSuffix[i+2])
				if(t2==dpSuffix[i+2]){
					// log(arr[i+1],dpSuffix[i+2],i)
					got=1;
					break;
				}
			}
			else if(i==n-2){
				if(dpPrefix[i-1]==-1)
					continue;
				int t1=arr[i],t2=arr[i+1];
				swap(t1,t2);
				if(dpPrefix[i-1]>t1){
					continue;
				}
				t1-=dpPrefix[i-1];
				if(t1>t2)
					continue;
				else if(t1==t2){
					// log(arr[i],t2)
					got=1;
					break;
				}
			}
			else{
				if(dpSuffix[i+2]==-1)
					continue;
				if(dpPrefix[i-1]==-1)
					continue;
				int t1=arr[i],t2=arr[i+1];
				swap(t1,t2);
				if(dpPrefix[i-1]>t1){
					continue;
				}
				t1-=dpPrefix[i-1];
				if(t1>t2)
					continue;
				t2-=t1;
				t1=0;
				if(t2==dpSuffix[i+2]){
					// log(1)
					got=1;
					break;
				}
			}
		}
		if(got)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
