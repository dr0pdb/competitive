/*
    A large part of this template has been copy-pasted. Heck i don't even know how some of these work :|
*/

#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
const int INF = 1<<29;
#define SIEVELIM 10000000+10
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
inline double nextdouble(){double temporary; scanf("%lf",&temporary); return temporary;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll leftChild(ll p ){return p<<1;}
ll rightChild(ll p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
const ll MOD = 1000000007;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define deb(x )     cerr << #x << " here "<< x; 
#define endl    "\n"
#define pb push_back
#define mp make_pair
#define all(cc) (cc).begin(),(cc).end()

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

template<typename T > void modulize(T & a, const T & b) { if (a >= b) { a %= b; } }
ll mulmod(ll a, ll b, ll m) { ll q = (ll)(((ld)a*(ld)b) / (ld)m); ll r = a*b - q*m; if (r>m)r %= m; if (r<0)r += m; return r; }
template <typename T, typename S>T expo(T e, S n) { T x = 1, p = e; while (n) { if (n & 1)x = x*p; p = p*p; n >>= 1; }return x; }
template <typename T>T power(T e, T n, T & m) { T x = 1, p = e; while (n) { if (n & 1)x = mod(x*p, m); p = mod(p*p, m); n >>= 1; }return x; }
template <typename T>T powerL(T e, T n, T & m) { T x = 1, p = e; while (n) { if (n & 1)x = mulmod(x, p, m); p = mulmod(p, p, m); n >>= 1; }return x; }
template <typename T> T InverseEuler(T a, T & m) { return (a == 1 ? 1 : power(a, m - 2, m)); }

inline int two(int n) { return 1 << n; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
/*----------------------------------------------------------------------*/

typedef vector <vector <int>> graph;
typedef vector <int> :: const_iterator const_graph_iter;


vector <int> lca_h, lca_dfs_list, lca_first, lca_tree;
vector <char> lca_dfs_used;

void clearVectors() {
	lca_h.clear();
	lca_dfs_list.clear();
	lca_first.clear();
	lca_tree.clear();
	lca_dfs_used.clear();
}

void lca_dfs (const graph &g, int v, int h = 1)
{
	lca_dfs_used [v] = true;
	lca_h [v] = h;
	lca_dfs_list.push_back (v);
	for (const_graph_iter i = g [v].begin (); i != g[v].end (); ++ i)
		if (!lca_dfs_used [*i])
		{
			lca_dfs (g, *i, h + 1);
			lca_dfs_list.push_back (v);
		}
}

void lca_build_tree (int i, int l, int r)
{
	if (l == r)
		lca_tree [i] = lca_dfs_list [l];
	else
	{
		int m = (l + r) >> 1;
		lca_build_tree (i + i, l, m);
		lca_build_tree (i + i + 1, m + 1, r);
		if (lca_h [lca_tree [i + i]] <lca_h [lca_tree [i + i + 1]])
			lca_tree [i] = lca_tree [i + i];
		else
			lca_tree [i] = lca_tree [i + i + 1];
	}
}

void lca_prepare (const graph &g, int root)
{
	int n = (int) g.size ();
	lca_h.resize (n);
	lca_dfs_list.reserve (n * 2);
	lca_dfs_used.assign (n, 0);

	lca_dfs (g, root);

	int m = (int) lca_dfs_list.size ();
	lca_tree.assign (lca_dfs_list.size () * 4 + 1, -1);
	lca_build_tree (1, 0, m-1);

	lca_first.assign (n, -1);
	for (int i = 0; i <m; ++ i)
	{
		int v = lca_dfs_list [i];
		if (lca_first [v] == -1)
			lca_first [v] = i;
	}
}

int lca_tree_min (int i, int sl, int sr, int l, int r)
{
	if (sl == l && sr == r)
		return lca_tree [i];
	int sm = (sl + sr) >> 1;
	if (r <= sm)
		return lca_tree_min (i + i, sl, sm, l, r);
	if (l> sm)
		return lca_tree_min (i + i + 1, sm + 1, sr, l, r);
	int ans1 = lca_tree_min (i + i, sl, sm, l, sm);
	int ans2 = lca_tree_min (i + i + 1, sm + 1, sr, sm + 1, r);
	return lca_h [ans1] <lca_h [ans2]? ans1: ans2;
}

int lca (int a, int b)
{
	int left = lca_first[a],
		right = lca_first[b];
	if (left> right) swap(left, right);
	return lca_tree_min (1, 0, (int) lca_dfs_list.size() - 1, left, right);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	int t,n;
	cin>>t;

	F(tn,1,t+1){
		cin>>n;
		clearVectors();
		graph g(n);
	    int root;

	    // bool isroot[n];
	    // memset(isroot, true, sizeof(isroot));

	    int m;
	    F(i, 0, n){
	    	cin>>m;

	    	int to;
	    	F(j, 0, m){
	    		cin>>to;
	    		to--;
	    		g[i].push_back(to);
	    		g[to].push_back(i);
	    		// isroot[to] = false;
	    	}
	    }

	    // F(i, 0, n){
	    // 	if (isroot[i])
	    // 	{
	    // 		root = i;
	    // 		break;
	    // 	}
	    // }

	    lca_prepare(g, 0);
	    cout<<"Case "<<tn<<":\n";
	    int q;
	    cin>>q;
	    while (q--) {
	        int v1, v2; 
	        cin>>v1>>v2;
	        v1--; v2--;
	        cout<<lca(v1, v2) + 1<<endl;
	    }
	}    

    return 0;          
}/*
    WroNg anSWer, BHY :~(
*/