#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class union_find
{
	int n;
	vector<int> par;
	vector<int> sz;
public:
	union_find(int nval)
	{
		n = nval;
		par.resize(n + 1);
		sz.resize(n + 1);

		for (int i = 1; i <= n; ++i)
			par[i] = i, sz[i] = 1;
	}

	//O(1) ammortized
	int root(int x)
	{
		/*while(x!=par[x])
			x=par[x];
		return x;*/

		if (x == par[x])
			return x;

		return par[x] = root(par[x]);
	}

	//O(1) ammortized
	bool find(int a, int b)
	{
		return root(a) == root(b);
	}

	//O(1) ammortized
	void un(int a, int b)
	{
		int ra = root(a);
		int rb = root(b);

		if (ra == rb)
			return;

		if (sz[ra] > sz[rb])
			swap(ra, rb);

		par[ra] = rb;
		sz[rb] += sz[ra];
	}
};


int32_t main()
{
	FIO;
	union_find dsu(5);

	cout << dsu.find(1, 2) << '\n';

	dsu.un(1, 2);
	dsu.un(1, 3);

	cout << dsu.find(2, 3) << '\n';
	cout << dsu.find(4, 5) << '\n';
	return 0;
}