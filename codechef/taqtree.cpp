#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);

#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define ull unsigned long long
#define deb(x )     cerr << #x << " = "<< x << endl;
#define endl    "\n"
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using maxpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using minpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int N = 1e5+5;
vii g[N];
vector<iii> elist;
int order[N], b[N], e[N], dist[N], timer, timer2 = -1, n,l;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    order[++timer2] = v;
    b[v] = timer2;
    tin[v] = ++timer;

    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (ii itr : g[v]) {
        int u = itr.ff;
        if (u != p) {
            dist[u] = dist[v] + itr.ss;
            dfs(u, v);
        }
    }

    tout[v] = ++timer;
    e[v] = timer2;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    memset(dist, 0, sizeof(dist));
    dfs(root, root);
}

int arr[N];
int tree[4*N];
int lazy[4*N];

/**
 * Build and init tree
 */
void build_tree(int node, int a, int b) {
  	if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
    	tree[node] = arr[a]; // Init value
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
	
	tree[node] = tree[node*2] + tree[node*2+1]; // Init root value
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int value) {
  
  	if(lazy[node] != 0) { // This node needs to be updated
   		tree[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
    			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

   		lazy[node] = 0; // Reset it
  	}
  
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a >= i && b <= j) { // Segment is fully within range
    		tree[node] += value;

		if(a != b) { // Not leaf node
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}

    		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = tree[node*2] + tree[node*2+1]; // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return 0; // Out of range

	if(lazy[node] != 0) { // This node needs to be updated
		tree[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = q1 + q2; // Return final result
	
	return res;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n; int u,v,w;
    FOR(i, 0, n-1) {
        cin>>u>>v>>w; u--; v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        elist.push_back({w, {u, v}});
    }
    preprocess(0);
    FOR(i, 0, n) {
        arr[i] = dist[order[i]];
    }

    // FOR(i, 0, n) {
    //     cout<<order[i]<<" ";
    // }
    // cout<<endl;
    // FOR(i, 0, n) {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // FOR(i, 0, n) {
    //     cout<<b[i]<<" ";
    // }
    // cout<<endl;
    // FOR(i, 0, n) {
    //     cout<<e[i]<<" ";
    // }
    // cout<<endl;

    build_tree(1, 0, n-1);
    memset(lazy, 0, sizeof(lazy));
    int q,t,a,bb; cin>>q;
    while(q--) {
        cin>>t>>a>>bb;
        if(t == 2) {
            a--; bb--;
            int lc = lca(a, bb);
            int res = query_tree(1, 0, n-1, b[a], b[a]);
            res -= 2*query_tree(1, 0, n-1, b[lc], b[lc]);
            res += query_tree(1, 0, n-1, b[bb], b[bb]);
            cout<<res<<endl;
        } else {
            a--;
            int change = bb - elist[a].ff;
            tie(u,v) = elist[a].ss;
            elist[a].ff = bb;
            if(b[u] < b[v]) swap(u, v);
            update_tree(1, 0, n-1 ,b[u], e[u], change);
        }
    }

    return 0;
}/*
    Annoying -_-
*/