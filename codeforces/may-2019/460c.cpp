#include<bits/stdc++.h>
#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"
#define printCase() "Case #" << caseNum << ": "
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
const ll MOD = 1000000007;
const ll INF = INT_MAX;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

const int N = 1e5+1;
int arr[N];
ii tree[4*N];
int lazy[4*N];

void merge(int node) {
	int lt = 2*node; int rt = lt + 1;
	tree[node].ff = min(tree[lt].ff, tree[rt].ff);
	if(tree[lt].ff <= tree[rt].ff) { // equality important!
		tree[node].ss = tree[lt].ss;
	} else {
		tree[node].ss = tree[rt].ss;
	}
}

/**
 * Build and init tree
 */
void build_tree(int node, int a, int b) {
  	if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
		tree[node].ff = arr[a]; // Init value
		tree[node].ss = a;
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
	
	merge(node);
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int value) {
  
  	if(lazy[node] != 0) { // This node needs to be updated
   		tree[node].ff += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

   		lazy[node] = 0; // Reset it
  	}
  
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a >= i && b <= j) { // Segment is fully within range
    		tree[node].ff += value;

		if(a != b) { // Not leaf node
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}
		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	merge(node);
}

/**
 * Query tree to get max element value within range [i, j]
 */
ii query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return {INF, -1}; // Out of range

	if(lazy[node] != 0) { // This node needs to be updated
		tree[node].ff += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	ii q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	ii q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	ii res = {min(q1.ff, q2.ff), q1.ss};
	if(q2.ff < q1.ff) {
		res.ss = q2.ss;
	}
	
	return res;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m,w;
    cin>>n>>m>>w;
    FOR(i, 0, n) {
    	cin>>arr[i];
    }
    build_tree(1, 0, n-1);
    while(m--) {
    	ii res = query_tree(1, 0, n-1, 0, n-1);
    	// deb(res.ss);
    	update_tree(1, 0, n-1, res.ss, min(res.ss + w - 1, n-1), 1);
    }
    cout<<query_tree(1, 0, n-1, 0, n-1).ff<<endl;

    return 0;
}