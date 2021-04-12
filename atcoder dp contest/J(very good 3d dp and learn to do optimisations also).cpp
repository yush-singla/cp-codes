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
template <typename T> T gcd(T a, T b) {if (a % b) return gcd(b, a % b); return b;}
template <typename T> T lcm(T a, T b)        {return (a * (b / gcd(a, b)));}
vs tokenizer(string str, char ch)         {std::istringstream var((str)); vs v; string t; while (getline((var), t, (ch))) {v.pb(t);} return v;}

int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };

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
	int n;
	cin >> n;
	double dp[n + 1][n + 1][n + 1];
	dp[0][0][0] = 0;
	int cnt[4] = {0};
	loop(i, 0, n - 1) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	dp[0][0][0] = 0;
	//dp[x][y][z]=1+dp[x-1][y+1][z]*p3+dp[x][y-1][z+1]*p2+dp[x][y][z-1]*p1+dp[x][y][z]*p0;
	//solving this equation taking dp[x][y][z] as the only variable
	loop(three, 0, n) {
		loop(two, 0, n) {
			loop(one, 0, n) {
				int zero = n - one - two - three;
				if (one + two + three > n || zero == n)
					continue;
				double p3 = (1.0 * three / n);
				double p2 = (1.0 * two / n);
				double p1 = (1.0 * one / n);
				double p0 = (1.0 * zero / n);
				double val = 1;
				//pick3
				if (three > 0)val += p3 * dp[three - 1][two + 1][one];
				//pick2
				if (two > 0)val += p2 * dp[three][two - 1][one + 1];
				//pick1
				if (one > 0)val += p1 * dp[three][two][one - 1];
				dp[three][two][one] = val / (1 - p0);
			}
		}
	}

	cout << ps(dp[cnt[3]][cnt[2]][cnt[1]], 9) << endl;

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
