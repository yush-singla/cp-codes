// // Problem Link - 
// /* By Yush singla */
// #include<bits/stdc++.h>
// //#include<ext/pb_ds/assoc_container.hpp>
// //#include<ext/pb_ds/tree_policy.hpp>
// //#include <ext/pb_ds/trie_policy.hpp>
// //using namespace __gnu_pbds;
// using namespace std;
// #define int                     long long 
// #define ld                        long double
// #define mod                     1000000007
// #define inf                     1e18
// #define endl                    "\n"
// #define tc                      int ntc;cin>>ntc;while(ntc--)
// #define pb                         push_back
// #define vi                      vector<int>
// #define vs                        vector<string>
// #define pii                     pair<int,int>
// #define ump                        unordered_map
// #define mp                         make_pair
// #define pqb                     priority_queue<int>
// #define pqs                     priority_queue<int,vi,greater<int> >
// #define all(n)                     n.begin(),n.end()
// #define ff                         first
// #define ss                         second
// #define ps(x,y)                 fixed<<setprecision(y)<<x
// #define mid(l,r)                (l+(r-l)/2)
// #define bitc(n)                 __builtin_popcount(n)
// #define loop(i,a,b)             for(int i=(a);i<=(b);i++)
// #define looprev(i,a,b)             for(int i=(a);i>=(b);i--)
// #define iter(container, it)     for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
// #define log(args...)             { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
// #define logarr(arr,a,b)            for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;    
// template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
// template <typename T> T lcm(T a, T b)        {return (a*(b/gcd(a,b)));}
// vs tokenizer(string str,char ch)         {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


// void err(istream_iterator<string> it) {}
// template<typename T, typename... Args>
// void err(istream_iterator<string> it, T a, Args... args) {
//     cout << *it << " = " << a << endl;
//     err(++it, args...);
// }
// //typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// //typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

// void file_i_o()
// {
//     ios_base::sync_with_stdio(0); 
//     cin.tie(0); 
//     cout.tie(0);
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
// }

// int32_t main() {
//     clock_t begin = clock();
//     file_i_o();
//     // Write your code here....

//     #ifndef ONLINE_JUDGE 
//       clock_t end = clock();
//       cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
//     #endif 
//     return 0;
// }



#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
        Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }


class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};



    void topView(Node * root) {
        std::vector<int> vr,vl;
        Node* temp=root;
        while(temp->left){
            vl.push_back(temp->left->data);
        }
        temp=root;
        while(temp->right){
            vr.push_back(temp->right->data);
        }
        reverse(vl.begin(), vl.end());
        for(auto it:vl){
            cout<<it<<' ';
        }
        cout<<root->data<<' ';
        for(auto it:vr){
            cout<<it<<' ';
        }

    }

}; //End of Solution

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.topView(root);
    return 0;
}
