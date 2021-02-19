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
		char ch;
		int arr[n][n];
		vi minRow(10,mod),minCol(10,mod),maxRow(10,-1),maxCol(10,-1),maxArea(10,0);
		loop(i,0,n-1){
			loop(j,0,n-1){
				cin>>ch;
				// log(ch);
				arr[i][j]=ch-'0';
				minRow[ch-'0']=min(minRow[ch-'0'],i);
				maxRow[ch-'0']=max(maxRow[ch-'0'],i);
				minCol[ch-'0']=min(minCol[ch-'0'],j);
				maxCol[ch-'0']=max(maxCol[ch-'0'],j);
			}
		}
		// logarr(minCol,0,n-1);
		// logarr(maxCol,0,n-1);
		// logarr(maxRow,0,n-1)
		// logarr(minRow,0,n-1);
		// loop(j,0,n-1){
		// 	logarr(arr[j],0,n-1);
		// }
		loop(x,0,9){
			loop(i,0,n-1){
				loop(j,0,n-1){
					if(arr[i][j]==x){
						int base=max(j,n-j-1);
						int height=max(i,n-i-1);
						
						int area1=base*max(i- minRow[x],maxRow[x]-i);
						int area2=height*max(j- minCol[x],maxCol[x]-j);
						
						maxArea[x]=max(maxArea[x],max(area1,area2));
						// if(x==2){
						// 	log(base,height,area1,area2,maxRow[x],maxCol[x],minCol[x],minRow[x])
						// }
					}
				}
			}
		}
		loop(x,0,9){
			cout<<maxArea[x]<<' ';
		}
		cout<<endl;
	}
	//here we just try to greedily get the max possible vals of all the 
	//height and base and solve it by visiting each and every index of array
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
