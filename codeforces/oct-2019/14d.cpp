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

const int N = 201;
vii edges; bool del[N];
int n, dist[N];
vi g[N];

void dfs(int curr, int par = -1) {
    for(int ni : g[curr]) {
        if(del[ni]) continue;
        int nxt = curr ^ edges[ni].ff ^ edges[ni].ss;
        if(nxt != par) {
            dist[nxt] = dist[curr] + 1;
            dfs(nxt, curr);
        }
    }
}

int diam(int root) {
    memset(dist, -1, sizeof(dist));
    dist[root] = 0;
    dfs(root);

    int fend = max_element(dist, dist + n) - dist;

    memset(dist, -1, sizeof(dist));
    dist[fend] = 0;
    dfs(fend);

    return *max_element(dist, dist+n);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
   
    cin>>n;
    int u,v;
    FOR(i, 0, n-1) {
        cin>>u>>v; u--; v--;
        del[edges.size()] = false;
        g[u].push_back(edges.size()); g[v].push_back(edges.size());
        edges.push_back({u, v});
    }
    int res = 0;
    FOR(i, 0, n-1) {
        del[i] = true;
        res = max(res, diam(edges[i].ff) * diam(edges[i].ss));
        del[i] = false;
    }
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}