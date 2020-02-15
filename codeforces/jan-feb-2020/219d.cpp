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
int n;
int cnt[nax];

int dfs(int curr, int p = -1) {
    int res = 0;

    int nxt, wt;
    for(auto a : g[curr]) {
        tie(nxt, wt) = a;
        if(nxt != p) {
            res += wt + dfs(nxt, curr);
        }
    }

    return res;
}

void dfs2(int curr, int p = -1) {
    int a,b;
    for(auto nxt : g[curr]) {
        tie(a, b) = nxt;
        if(b == 0) b = -1;
        if(a != p) {
            cnt[a] = cnt[curr] - b;
            dfs2(a, curr);
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n; int a,b;
    FOR(i, 0, n - 1) {
        cin>>a>>b; a--; b--;
        g[a].pb({b, 0});
        g[b].pb({a, 1});
    }
    cnt[0] = dfs(0);
    dfs2(0);
    int res = cnt[distance(cnt, min_element(cnt, cnt + n))];
    vi ret;
    FOR(i, 0, n) {
        if(cnt[i] == res) ret.pb(i + 1);
    }
    cout<<res<<endl;
    for(int a : ret) cout<<a<<" ";
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}