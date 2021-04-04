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
// #define endl			        "\n"
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
#define logarr(arr,a,b)	        for(int z=(a);z<=(b);z++) {cout<<arr[z].ff<<' '<<arr[z].ss<<" ";}cout<<endl;
template <typename T> T gcd(T a, T b) {if (a % b) return gcd(b, a % b); return b;}
template <typename T> T lcm(T a, T b)        {return (a * (b / gcd(a, b)));}
vs tokenizer(string str, char ch)         {std::istringstream var((str)); vs v; string t; while (getline((var), t, (ch))) {v.pb(t);} return v;}


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
	int arr[n][n];
	std::vector<pii> v[2];
	loop(i, 0, n - 1) {
		loop(j, 0, n - 1) {
			v[(i + j) % 2].pb({i + 1, j + 1});
		}
	}
	// logarr(v[0], 0, n - 1);
	// logarr(v[1], 0, n - 1);
	int a;
	cin >> a;
	int fill0 = (a + 1) % 3, i0 = 0;
	if (fill0 == 0)fill0 = 3;
	int fill1 = (a + 2) % 3, i1 = 0;
	if (fill1 == 0)fill1 = 3;
	// log(fill1, fill0)
	cout << fill0 << ' ' << v[0][i0].ff << ' ' << v[0][i0++].ss << endl;
	// fflush(stdout);
	int emp;
	loop(i, 0, n * n ) {
		if (i0 == v[0].size()) {
			emp = 0;
			break;
		}
		if (i1 == v[1].size()) {
			emp = 1;
			break;
		}
		cin >> a;
		if (a == fill0) {
			cout << fill1 << ' ' << v[1][i1].ff << ' ' << v[1][i1++].ss << endl;
			// fflush(stdout);
		} else if (a == fill1) {
			cout << fill0 << ' ' << v[0][i0].ff << ' ' << v[0][i0++].ss << endl;
			// fflush(stdout);
		}
	}
	if (emp == 1) {
		while (i0 != v[0].size()) {
			cin >> a;
			if (a != fill0) {
				cout << fill0 << ' ' << v[0][i0].ff << ' ' << v[0][i0++].ss << endl;
				// fflush(stdout);
			} else {
				if (a == fill0) {
					int fill2 = 6 - fill1 - a;
					cout << fill2 << ' ' << v[0][i0].ff << ' ' << v[0][i0++].ss << endl;
					// fflush(stdout);
				}
			}
		}
	} else if (emp == 0) {
		while (i1 != v[1].size()) {
			cin >> a;
			if (a != fill1) {
				cout << fill1 << ' ' << v[1][i1].ff << ' ' << v[1][i1++].ss << endl;
				// fflush(stdout);
			} else {
				if (a == fill1) {
					int fill2 = 6 - fill1 - a;
					cout << fill2 << ' ' << v[1][i1].ff << ' ' << v[1][i1++].ss << endl;
					// fflush(stdout);
				}
			}
		}
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
