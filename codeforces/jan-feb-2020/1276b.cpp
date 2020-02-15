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
vi g[nax];
int n,m,a,b;
bool visited[nax];

int bfs(int src) {
    queue<int> q({src});
    visited[src] = true;
    int res = n - 2;

    while(!q.empty()) {
        int c = q.front(); q.pop();
        for(int nxt : g[c]) {
            if(!visited[nxt] && nxt != (a ^ b ^ src)) {
                visited[nxt] = true;
                res--;
                q.push(nxt);
            }
        }
    }

    return res;
}

void reset_visited() {
    FOR(i, 0, n) visited[i] = false;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int t; cin>>t;
    while(t--) {
        cin>>n>>m>>a>>b;
        FOR(i, 0, n) {
            g[i].clear();
        }
        reset_visited();
        a--; b--;
        int u,v;
        FOR(i, 0, m) {
            cin>>u>>v; u--; v--;
            g[u].pb(v); g[v].pb(u);
        }
        int p1 = bfs(a);
        assert(p1 >= 0);
        reset_visited();
        int p2 = bfs(b);
        assert(p2 >= 0);
        // deb(p1); deb(p2);
        cout<<1LL * p1 * p2 <<endl;
    }

    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}