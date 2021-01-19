// Problem Link - https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
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

int trappingWater(vi &arr,int n){
	//for each cell we need to find the max height 
	//on the left and right and the water that it 
	//will then be able to hold will be equal to
	//min(lmax,rmax)-arr[i] water in that space if it is positive
	//so we need to maintain a prefix max array and 
	//a suffix max array also to be able to get lmax n rmax easily
	std::vector<int> lmax(n,arr[0]),rmax(n,arr[n-1]);
	loop(i,1,n-1){
		lmax[i]=max(lmax[i-1],arr[i]);
	}
	looprev(i,n-2,0){
		rmax[i]=max(rmax[i+1],arr[i]);
	}
	int totWater=0;
	loop(i,0,n-1){
		totWater+=max(min(lmax[i],rmax[i])-arr[i],0);
	}
	return totWater;

}
int trappingWater2(vi arr[], int n){
//this is another approach that we could use to solve where
//space required is constant 
//here we basically have a left value and then traverse the 
//array trying to find an element s.t it is bigger than curr
//left if we find then we fixate the water for all the buildings
//else we repeat the same process in reverse till the point 
//we were not able to fixate the water and then fixate the water
//there as well
    int currLeft=0,tempWater=0,fixedWater=0;
    loop(i,1,n-1){
        if(arr[i]>=arr[currLeft]){
            fixedWater+=tempWater;
            tempWater=0;
            currLeft=i;
        }
        else{
            tempWater+=(arr[currLeft]-arr[i]);
        }
    }
    int currRight=n-1;
    tempWater=0;
    looprev(i,n-2,currLeft){
        if(arr[i]>=arr[currRight]){
            fixedWater+=tempWater;
            tempWater=0;
            currRight=i;
        }
        else{
            tempWater+=(arr[currRight]-arr[i]);
        }
    }
    return fixedWater;
}

int32_t main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int n;
	cin>>n;
	vi arr(n)
	for(auto &el:arr){
		cin>>el;
	}
	cout<<trappingWater(arr,n)<<endl;

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
