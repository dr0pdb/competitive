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
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

const int N = 100005;
ll tree[3][4*N][2]; // 0 - Red, 1 = green
ll lazy[3][4*N];

void combine(int c, int node) {
	int left = 2*node; int right = left + 1;
	tree[c][node][0] = tree[c][left][0] + tree[c][right][0];
	tree[c][node][1] = tree[c][left][1] + tree[c][right][1];
}

void swap_vals(int c, int node) {
	ll tmp = tree[c][node][0];
	tree[c][node][0] = tree[c][node][1]; // Update it
	tree[c][node][1] = tmp;
}

void push(int c, int node) {
	lazy[c][node*2] += lazy[c][node]; // Mark child as lazy
	lazy[c][node*2] %= 2;
	lazy[c][node*2+1] += lazy[c][node]; // Mark child as lazy
	lazy[c][node*2+1] %= 2;
}

void build_tree(int c, int node, int a, int b) {
  	if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
  		tree[c][node][0]=0;	
		tree[c][node][1]=1;
		return;
	}
	
	build_tree(c, node*2, a, (a+b)/2); // Init left child
	build_tree(c, node*2+1, 1+(a+b)/2, b); // Init right child
	combine(c, node);
}

void update_tree(int c, int node, int a, int b, int i, int j) {
  	if(lazy[c][node] != 0) { // This node needs to be updated
  		swap_vals(c, node);

		if(a != b) {
			push(c, node);
		}

   		lazy[c][node] = 0;
  	}
  
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a >= i && b <= j) { // Segment is fully within range
		swap_vals(c, node);

		if(a != b) { // Not leaf node
			lazy[c][2*node] = 1 - lazy[c][2*node];
			lazy[c][2*node+1] = 1 - lazy[c][2*node+1]; 
		}

		return;
	}

	update_tree(c, node*2, a, (a+b)/2, i, j); // Updating left child
	update_tree(c, 1+node*2, 1+(a+b)/2, b, i, j); // Updating right child

	combine(c, node);
}

ll query_tree(int c, int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return 0; // Out of range

	if(lazy[c][node] != 0) { // This node needs to be updated
		swap_vals(c, node);

		if(a != b) {
			push(c, node);
		}

		lazy[c][node] = 0; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[c][node][0];

	ll q1 = query_tree(c, node*2, a, (a+b)/2, i, j); // Query left child
	ll q2 = query_tree(c, 1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	return q1 + q2;
}

ll ans(ll rc[3], ll gc[3]) {
	ll ret = rc[0] * rc[1] * rc[2];
	ret += rc[0] * gc[1] * gc[2];
	ret += gc[0] * rc[1] * gc[2];
	ret += gc[0] * gc[1] * rc[2];
	return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t,q,nc[3],tp,l,r, a[3],b[3];
    cin>>t;

    while(t--) {
	    memset(lazy, 0, sizeof(lazy));
    	memset(tree, 0, sizeof(tree));
		
		FOR(i, 0, 3) {
			cin>>nc[i]; nc[i]--;
			build_tree(i, 1, 0, nc[i]);
		}

		cin>>q;
		FOR(i, 0, q) {
			cin>>tp;
			if(tp <= 2) {
				cin>>l>>r;
				update_tree(tp, 1, 0, nc[tp], l, r);
			} else {
				FOR(j, 0, 3) {
					cin>>a[j];
				}
				FOR(j, 0, 3) {
					cin>>b[j];
				}

				ll rc[3], gc[3];
				FOR(j, 0, 3){
					rc[j] = query_tree(j, 1, 0, nc[j], a[j], b[j]);
					gc[j] = (b[j] - a[j] + 1 - rc[j]);
				}
				cout<<ans(rc, gc)<<endl;
			}
		}
    }
    
    return 0;
}