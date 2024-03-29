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
#define tc                      int ntc;cin>>ntc;int ttc=ntc;while(ntc--)
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


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;;
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

int mini(int x, int y) {
	if (y < 4)return 0;
	return min(x - 1, y / 2 - 1);
}

int32_t main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	tc{
		int r, c;
		cin >> r >> c;
		int arr[r][c];
		loop(i, 0, r - 1) {
			loop(j, 0, c - 1) {
				cin >> arr[i][j];
			}
		}
		int up[r][c] = {0}, down[r][c] = {0}, left[r][c] = {0}, right[r][c] = {0};
		loop(i, 0, r - 1) {
			loop(j, 0, c - 1) {
				up[i][j] = 0, down[i][j] = 0, right[i][j] = 0, left[i][j] = 0;
			}
		}
		loop(i, 0, r - 1) {
			left[i][0] = arr[i][0];
			loop(j, 1, c - 1) {
				if (arr[i][j] == 1) {
					left[i][j] = left[i][j - 1] + 1;
				}
			}
			right[i][c - 1] = arr[i][c - 1];
			looprev(j, c - 2, 0) {
				if (arr[i][j] == 1) {
					right[i][j] = right[i][j + 1] + 1;
				}
			}
		}

		loop(j, 0, c - 1) {
			up[0][j] = arr[0][j];
			loop(i, 1, r - 1) {
				if (arr[i][j] == 1) {
					up[i][j] = up[i - 1][j] + 1;
				}
			}
			down[r - 1][j] = arr[r - 1][j];
			looprev(i, r - 2, 0) {
				if (arr[i][j] == 1) {
					down[i][j] = down[i + 1][j] + 1;
				}
			}
		}
		/*loop(i, 0, r - 1) {
			loop(j, 0, c - 1) {
				log(i, j, down[i][j])
			}
		}*/
		// loop(i,0,r-1)
		int anss = 0;
		loop(i, 0, r - 1) {
			loop(j, 0, c - 1) {
				if (arr[i][j] == 1) {
					int ans = 0;
					ans += mini(up[i][j], left[i][j]);
					ans += mini(down[i][j], left[i][j]);
					ans += mini(up[i][j], right[i][j]);
					// log(right[i][j], down[i][j]);
					ans += mini(down[i][j], right[i][j]);
					ans += mini(left[i][j], up[i][j]);
					ans += mini(left[i][j], down[i][j]);
					ans += mini(right[i][j], up[i][j]);
					ans += mini(right[i][j], down[i][j]);
					anss += ans;
					if (i == 0 && j == 0) {
						// log(up[i][j], down[i][j], right[i][j], left[i][j])
						// log(ans, i, j)cout << endl;
					}
				}
			}
		}
		// log(anss)
		cout << "Case #" << ttc - ntc << ": " << anss << endl;
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
