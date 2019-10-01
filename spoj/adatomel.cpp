/**
    __author__ : srv_twry
**/

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

bool ge(const ll& a, const ll& b) { return a >= b; }
bool le(const ll& a, const ll& b) { return a <= b; }
bool eq(const ll& a, const ll& b) { return a == b; }
bool gt(const ll& a, const ll& b) { return a > b; }
bool lt(const ll& a, const ll& b) { return a < b; }
int sgn(const ll& x) { return le(x, 0) ? eq(x, 0) ? 0 : -1 : 1; }
/*----------------------------------------------------------------------*/

int n, k, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;
vector<vector<bitset<1001>>> fruits;
vector<int> flavours;
vector<int> depth;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p; fruits[v][0][flavours[v]]=1;
    fruits[v][0][flavours[p]] = 1;
    for (int i = 1; i <= l; ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
        fruits[v][i] = fruits[v][i-1] | fruits[up[v][i-1]][i-1];
    }

    for (int u : adj[v]) {
        if (u != p) {
        	depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }

    tout[v] = ++timer;
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
    depth.resize(n);
    depth[root]=0;
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 	int q,p,u,v;
 	cin>>n>>k>>q;
 	adj.resize(n); flavours.resize(n);
 	FOR(i, 1, n) {
 		cin>>p;
 		adj[p].push_back(i);
 	}
 	l = ceil(log2(n));
 	fruits.resize(n, vector<bitset<1001>>(l + 1));
 	FOR(i, 0, n) cin>>flavours[i];
 	preprocess(0);
 	while(q--) {
 		bitset<1001> result;
 		FOR(i, 0, 3) {
 			cin>>u>>v;
 			int lc = lca(u, v);

 			for(int j = l; j >= 0; j--) {
 				if(depth[u] - (1 >> j) >= depth[lc]) {
 					result |= fruits[u][j];
 					u = up[u][j];
 				}
 			}

 			for(int j = l; j >= 0; j--) {
 				if(depth[v] - (1 >> j) >= depth[lc]) {
 					result |= fruits[v][j];
 					v = up[v][j];
 				}
 			}
 		}
 		cout<<static_cast<int>(result.count())<<endl;
 	}
    return 0;
}