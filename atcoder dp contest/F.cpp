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
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	pair<int, pii> dp[n + 1][m + 1];
	loop(i, 0, n) {
		dp[i][0] = mp(0, mp((int) - 1, (int) - 1));
	}
	loop(i, 0, m) {
		dp[0][i] = mp(0, mp((int) - 1, (int) - 1));
	}
	loop(i, 1, n) {
		loop(j, 1, m) {
			if (s[i - 1] == t[j - 1]) {
				auto el = dp[i - 1][j - 1];
				if (el.ff == 0 && el.ss == mp((int) - 1, (int) - 1)) {
					dp[i][j] = mp(el.ff + 1, el.ss);
				} else if (el.ff == 1 && el.ss == mp((int) - 1, (int) - 1)) {
					dp[i][j] = mp(el.ff + 1, mp(i - 1, j - 1));
				} else if (el.ff == dp[el.ss.ff][el.ss.ss].ff) {
					dp[i][j] = mp(dp[i - 1][j - 1].ff + 1, dp[i - 1][j - 1].ss);

				} else {
					dp[i][j] = mp(dp[i - 1][j - 1].ff + 1, mp(i - 1, j - 1));
				}

			} else {
				if (dp[i - 1][j] >= dp[i][j - 1]) {
					auto el = dp[i - 1][j];
					if (el.ff == 0 && el.ss ==  mp((int) - 1, (int) - 1)) {
						dp[i][j] = el;
					}
					else if (el.ff == 1 && el.ss ==  mp((int) - 1, (int) - 1)) {
						dp[i][j] = mp(el.ff, mp(i - 1, j));
					}
					else if (el.ff == dp[el.ss.ff][el.ss.ss].ff) {
						dp[i][j] = el;
					} else {
						dp[i][j] = mp(el.ff, mp(i - 1, j));
					}
				} else {
					auto el = dp[i][j - 1];
					if (el.ff == 0 && el.ss == mp((int) - 1, (int) - 1)) {
						dp[i][j] = el;
					}
					else if (el.ff == 1 && el.ss == mp((int) - 1, (int) - 1)) {
						dp[i][j] = mp(el.ff, mp(i, j - 1));
					}
					else if (el.ff == dp[el.ss.ff][el.ss.ss].ff) {
						dp[i][j] = el;
					} else {
						dp[i][j] = mp(el.ff, mp(i, j - 1));
					}
				}
			}
		}
	}
	pii gotoo;
	if (s[n - 1] == t[m - 1]) {
		gotoo = {n, m};
	} else {
		gotoo = dp[n][m].ss;
	}
	// loop(i, 0, n) {
	// 	loop(j, 0, m) {
	// 		auto el = dp[i][j];
	// 		cout << el.ff << "&" << el.ss.ff << ',' << el.ss.ss << ' ';
	// 	} cout << endl;
	// }
	string ans;
	while (gotoo != mp((int) - 1, (int) - 1)) {
		ans.pb(s[gotoo.ff - 1]);
		gotoo = dp[gotoo.ff][gotoo.ss].ss;
	}
	// cout << ans << endl;
	reverse(all(ans));
	cout << ans << endl;

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}