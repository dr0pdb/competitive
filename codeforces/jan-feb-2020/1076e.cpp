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

const int nax = 3e5+5;
int n,m,a,b;
vi g[nax];
vii queries[nax];
ll res[nax], d[nax];

void dfs(int curr, int p = -1, int depth = 0, ll sm = 0) {
    for(auto q : queries[curr]) {
        d[depth] += q.ss;
        if(depth + q.ff < n) d[depth + q.ff + 1] -= q.ss; 
    }

    sm += d[depth];
    res[curr] = sm;

    for(int nxt : g[curr]) {
        if(nxt != p) {
            dfs(nxt, curr, depth + 1, sm);
        }
    }

    for(auto q : queries[curr]) {
        d[depth] -= q.ss;
        if(depth + q.ff < n) d[depth + q.ff + 1] += q.ss; 
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n;
    memset(res, 0, sizeof(res)); memset(d, 0, sizeof(d));
    FOR(i, 0, n - 1) {
        cin>>a>>b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    cin>>m;int x;
    FOR(i, 0, m) {
        cin>>a>>b>>x; a--;
        queries[a].pb({b, x});
    }
    dfs(0);
    FOR(i, 0, n) cout<<res[i]<<" ";
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}