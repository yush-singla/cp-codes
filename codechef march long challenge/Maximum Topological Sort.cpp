#include <bits/stdc++.h>
using namespace std;
#define int                     long long
#define mod                     1000000007
// #define inf                     1e18
#define endl                    "\n"
#define tc                      int ntc;cin>>ntc;while(ntc--)
#define pb                         push_back
#define vi                      vector<int>
#define vs                        vector<string>
#define pii                     pair<int,int>
#define ump                        unordered_map
#define mp                         make_pair
#define pqb                     priority_queue<int>
#define pqs                     priority_queue<int,vi,greater<int> >
#define all(n)                     n.begin(),n.end()
#define ff                         first
#define ss                         second
#define ps(x,y)                 fixed<<setprecision(y)<<x
#define mid(l,r)                (l+(r-l)/2)
#define bitc(n)                 __builtin_popcount(n)
#define loop(i,a,b)             for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)             for(int i=(a);i>=(b);i--)
#define iter(container, it)     for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...)             { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)            for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;    
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
void file_i_o(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
int n;
const int N = (int)5e5 + 5;
int invff[N + 1];
int nnf[N + 1];
int fac[N + 1];
void inv(int p) {
 nnf[0] = nnf[1] = 1;
 for (int i = 2; i <= N; i++)
  nnf[i] = nnf[p % i] * (p - p / i) % p;
}
void inf(int p) {
 invff[0] = invff[1] = 1;
 for (int i = 2; i <= N; i++)
  invff[i] = (nnf[i] * invff[i - 1]) % p;
}
void factorial(int p) {
 fac[0] = 1;
 for (int i = 1; i <= N; i++) {
  fac[i] = (fac[i - 1] * i) % p;
 }
}
int Binomial(int N, int R, int p) {//ncr-
    if(R>N) return 0;
    if(R==N) return 1;
 int ans = ((fac[N] * invff[R]) % p * invff[N - R]) % p;
 return ans;
}
vector<vector<int>> adj;
vector<int> vis;
vector<int> tempans;
vector<int> midtree;
int dfs(int node) {
    vis[node] = 1;
    int ans=1, semi=0;
    for(auto x: adj[node]) {
        if(vis[x] == 0) {
            int curr_s = dfs(x);
            semi += curr_s;
            ans*= Binomial(semi, curr_s, mod);
            ans%=mod;
            ans*=tempans[x];
            ans%=mod;
        }
    }
    ans%=mod;
    tempans[node] = ans;
    return semi+1;
}
vector<pair<int, pair<int, int>>> useless;
int getNode(int node) {
    vis[node] = 1;
    int semi=0, curr;
    for(auto x: adj[node]) {
        if(vis[x] == 0) {
            curr = getNode(x);
            semi += curr;
    int abcd = min(curr,(n-curr));
            useless.push_back({abcd, {x, node}});
        }
    }
    midtree[node] = semi+1;
    return semi+1;
}
int32_t main() {
    file_i_o();
    factorial(mod);
    inv(mod);
    inf(mod);
    tc {
        int  k;
        cin>>n>>k;
        int m=n-1;
        adj.clear(), vis.clear(), tempans.clear();
        adj.resize(n), vis.resize(n, 0), tempans.resize(n);
        while(m--) {
            int x,y;
            cin>>x>>y;
            adj[x-1].push_back(y-1);
            adj[y-1].push_back(x-1);
        }
        if(n==1) {
            int case1=0,case2=0;
            if(k==1) {
                vis.clear(), tempans.clear();
                vis.resize(n, 0), tempans.resize(n);
                dfs(case1);
                cout<<case1+1<<" "<<tempans[case1]%mod<<endl;
            } else {
                vis.clear(), tempans.clear();
                vis.resize(n, 0), tempans.resize(n);
                dfs(case2);
                cout<<case2+1<<" "<<tempans[case2]%mod<<endl;
            }
            continue;
        }
        useless.clear(), midtree.clear(), midtree.resize(n);
        getNode(0);
        int idx=1;
        sort(useless.begin(), useless.end(), greater<pair<int, pair<int, int>>>());
        int case1,case2;
        if(useless[0].first != useless[1].first) {        
            int X = useless[0].second.first, Y = useless[0].second.second;
            if(midtree[X] == n-midtree[X]) {
                case1=max(X, Y);
                case2=min(X, Y);
            } else {
                if(midtree[X] > n-midtree[X]) {
                    case1=X;
                    case2=Y;
                } else {
                    case2=X;
                    case1=Y;
                }
            }
        } else {
            vector<int> temp;
            if((useless[0].second.first == useless[1].second.first) || (useless[0].second.first == useless[1].second.second)) {
                case1 = useless[0].second.first;
            } else {
                case1 = useless[0].second.second;
            }
            idx = 1;
            temp.push_back((useless[0].second.first != case1)? useless[0].second.first : useless[0].second.second);
            while(idx!=n && useless[idx-1].first == useless[idx].first ) {
                temp.push_back((useless[idx].second.first != case1)? useless[idx].second.first : useless[idx].second.second);
                ++idx;
            }
            case2 = *max_element(temp.begin(), temp.end());
        }
        if(k==1) {
            vis.clear(), tempans.clear();
vis.resize(n, 0), tempans.resize(n);
            dfs(case1);
            cout<<case1+1<<" "<<tempans[case1]%mod<<endl;
        } else {
            vis.clear(), tempans.clear();
            vis.resize(n, 0), tempans.resize(n);
            dfs(case2);
            cout<<case2+1<<" "<<tempans[case2]<<endl;
        }
    }
}