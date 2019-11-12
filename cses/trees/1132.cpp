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
#define bitcount(x) __builtin_popcount(x)
#define cps CLOCKS_PER_SEC
#define verify(x) if(x >= MOD) x -= MOD;

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int N = 2e5+5;
vi g[N];
int n,a,b;
int depth[N], dist[N], par[N][15];
int tin[N],tout[N],timer = 0;

void dfs(int curr, int p) {
    tin[curr] = ++timer;

    par[curr][0] = p;
    FOR(i, 1, 15)
        par[curr][i] = par[par[curr][i - 1]][i - 1];
    
    for(int nxt : g[curr]) {
        if(nxt != p) {
            depth[nxt] = depth[curr] + 1;
            dist[nxt] = depth[nxt];
            dfs(nxt, curr);
        }
    }

    tout[curr] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

void dfs2(int curr, int p) {
    for(int nxt : g[curr]) {
        if(nxt == p) continue;
        dist[nxt] = dist[curr] + 1;
        dfs2(nxt, curr);
    }
}

int lca(int u, int v) {
    if(is_ancestor(u, v)) return u;
    if(is_ancestor(v, u)) return v;

    RFOR(i, 14, 0) {
        if(!is_ancestor(par[u][i], v)) 
            u = par[u][i];
    }

    return par[u][0];
}

int dis(int u, int v) {
    int lc = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[lc];
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n;
    FOR(i, 1, n) {
        cin>>a>>b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    depth[0] = 0; dist[0] = 0; 
    dfs(0, 0);
    int u = distance(dist, max_element(dist, dist + n));
    
    dist[u] = 0;
    dfs2(u, u);
    int v = distance(dist, max_element(dist, dist + n));
    
    // deb(u); deb(v);
    // deb(dis(2, 1));
    // deb(dis(1, 2));

    FOR(i, 0, n) {
        cout<<max(dis(u, i), dis(v, i))<<" ";
    }
    
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}