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

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int N = 2e3+5;
vi g[N];
ll a[N],f[N],n,d;

void dfs(int curr, int root, int par = -1) {
    f[curr] = 1;
    for(int nxt : g[curr]) {
        if(nxt != par) {
            if(a[nxt] < a[root] || a[nxt] > a[root] + d) continue;
            if(a[nxt] == a[root] && nxt < root) continue; // the call to dfs(nxt, nxt) has already been done before. don't double count.
            dfs(nxt, root, curr);
            f[curr] *= (f[nxt] + 1) % MOD; f[curr] %= MOD;
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int u,v;
    cin>>d>>n;
    FOR(i,0,n) cin>>a[i];
    FOR(i,1,n) {
        cin>>u>>v; u--; v--;
        g[u].push_back(v); g[v].push_back(u);
    }

    ll res = 0;
    FOR(i, 0, n) {
        memset(f, 0, sizeof(f));
        dfs(i, i);
        res += f[i]; res%=MOD;
    }
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}