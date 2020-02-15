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

const int nax = 2e5+5;
vii g[nax];
int k,sz[nax],a,b;
ll maxm = 0, minm = 0;

void dfs(int curr, int p = -1) {
    sz[curr] = 1;

    for(ii nxt : g[curr]) {
        if(nxt.ff == p) continue;
        dfs(nxt.ff, curr);
        sz[curr] += sz[nxt.ff];
        minm += 1LL * nxt.ss * (sz[nxt.ff] % 2);
        maxm += 1LL * nxt.ss * min(sz[nxt.ff], k - sz[nxt.ff]);
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int t,wt; cin>>t;
    while(t--) {
        cin>>k; k*=2;
        FOR(i, 0, k) {
            g[i].clear();
            sz[i] = 0;
        }
        maxm = 0; minm = 0;
        FOR(i, 0, k-1) {
            cin>>a>>b>>wt; a--; b--;
            g[a].pb({b, wt}); g[b].pb({a, wt});
        }
        dfs(0);
        cout<<minm<<" "<<maxm<<endl;
    }

    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}