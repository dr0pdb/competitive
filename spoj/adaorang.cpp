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

int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;
vector<vector<bool> > colors;
vector<int> distincts;
vector<int> shade;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
            for(int i = 0; i < colors[v].size(); i++) {
            	if((!colors[v][i]) && colors[u][i]) {
            		colors[v][i] = true;
            		distincts[v]++;
            	}
            }
        }
    }

    if (!colors[v][shade[v]])
    {
    	colors[v][shade[v]] = true;
    	distincts[v]++;
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
    distincts.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    colors.resize(n, vector<bool>(251, false));
    dfs(root, root);
}

void clearup() {
	tin.clear();
	tout.clear();
	up.clear();
	distincts.clear();
	colors.clear();
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int t,q,r,u,v; cin>>t;
	while(t--) {
		cin>>n>>q>>r;
		shade.clear(); shade.resize(n);
		adj.clear(); adj.resize(n);
		FOR(i, 0, n) cin >> shade[i];
		FOR(i, 0, n-1) {
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		preprocess(r);
		while(q--) {
			cin>>u>>v;
			cout<<distincts[lca(u, v)]<<endl;
		}
		clearup();
	}    

    return 0;
}