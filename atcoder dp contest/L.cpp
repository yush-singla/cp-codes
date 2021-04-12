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
	vi arr(n);
	int sum = 0;
	for (auto &el : arr) {
		cin >> el;
		sum += el;
	}
	//state is the max amount i can get ie x so now
	//when i have dp[i][j] i can go to either
	//dp[i+1][j] or dp[i][j-1] take the max from them since
	//i have the choice to go there
	//but since now dp[i+1][j] and dp[i][j-1]is not my turn
	//i can't use that same recurrence here so i get all the
	//poss from this state to others and get there min since
	//then it will again be my turn and i will have the freedom
	//so recurrence can be applied
	//***********see pepcoding dp vid best explanation
	int dp[n][n];
	loop(i, 0, n - 1) {
		loop(j, 0, n - 1)dp[i][j] = 0;
	}
	loop(i, 0, n - 1) {
		dp[i][i] = arr[i];
		dp[i][i + 1] = max(arr[i], arr[i + 1]);
	}
	loop(gap, 2, n - 1) {
		loop(i, 0, n - 1 - gap) {
			int j = i + gap;
			dp[i][j] = max(arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]), arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
		}
	}
	cout << 2 * dp[0][n - 1] - sum << endl;
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
