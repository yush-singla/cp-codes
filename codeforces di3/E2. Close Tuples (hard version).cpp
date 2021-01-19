// Problem Link - https://codeforces.com/contest/1462/problem/E2
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
#define p                       1000000007
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

vi fac(300007,1),modInversee(300007,1);

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

  

int power(int x, int y){
    int res = 1; 

    x = x % p; 
     
    while (y > 0) 
    {        
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1; 
        x = (x * x) % p;
    }
    return res;
}
 

// int modInverse(int n){
//     return power(n, p - 2);
// }
 
int nCrModPFermat(int n,int r){
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    return (fac[n] * modInversee[fac[r]] % p
            * modInversee[fac[n - r]] % p)
           % p;
}



int32_t main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	// cout<<nCrModPFermat(12312,50)<<endl;
	loop(i,1,300007){
		fac[i]=(fac[i-1]*i)%mod;
	}
	loop(i,1,300007){
		modInversee[i]=power(i,p-2);
	}
	// cout<<"hello";
	// logarr(fac,20000,20002);
	tc{
		int n,m,k,sum=0;
		cin>>n>>m>>k;
		vi arr(n),freq(300007,0);
		for(int &e:arr){
			cin>>e;
		}
		sort(arr.begin(), arr.end());
		// loop(i,0,n-1){
		// 	freq[arr[i]]++;
		// }
		int prev=-1;
		loop(i,0,n-1){
			// if(arr[i]==prev){
			// 	continue;
			// }
			int upperBound=arr[i]+k,ans;
			int l=i,r=n-1;
			while(l<=r){
				int m=mid(l,r);
				if(arr[m]>upperBound){
					r=m-1;
				}
				else{
					l=m+1;
					ans=m;
				}
			}
			int numberOfElements=ans-i;
			// int x=freq[arr[i]];
			/*loop(c,0,m-1){
				sum=(sum+(nCrModPFermat(x,m-c)*
					nCrModPFermat(numberOfElements,c))%mod)%mod;
			}*/
			sum=(sum+nCrModPFermat(numberOfElements,m-1))%mod;
			// prev=arr[i];
		}
		cout<<sum<<endl;
	}

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
/*#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100500;
const int mod = 1000000007;
ll fact[N];
ll invFact[N];

ll fast_pow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p % 2 == 0) {
            a = (a * a) % mod;
            p /= 2;
        } else {
            res = (res * a) % mod;
            p--;
        }
    }
    return res;
}

ll C(int n, int k) {
    if (k > n) {
        return 0;
    }
    return fact[n] * invFact[k] % mod * invFact[n - k] % mod;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> v(n);
    for (ll &e : v) {
        cin >> e;
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i + 1;
        int r = upper_bound(v.begin(), v.end(), v[i] + k) - v.begin();
        // cout<<"r-l = "<<r-l<<endl;
        // cout<<"add = "<<C(r - l, m - 1) % mod<<endl;
        ans = (ans + C(r - l, m - 1)) % mod;
    }
    cout << ans << "\n";
}

int main() { 
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        invFact[i] = fast_pow(fact[i], mod - 2);
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}*/