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

const int nax = 1e6+5;
vi g[nax];
int n,a,b;
int p[nax], ht[nax];
int in[nax],out[nax],timertoidx[nax], timer=0;

const int K = 20;
int logg[nax], st[nax][K+2], idx[nax][K+2];
int res = 0;

void pre(int array[]) {
	logg[1] = 0;
	for (int i = 2; i < nax; i++)
    	logg[i] = logg[i/2] + 1;

    for (int i = 0; i < nax; i++) {
        st[i][0] = array[i];
        idx[i][0] = i;
    }

	for (int j = 1; j <= K; j++)
	    for (int i = 0; i + (1 << j) < nax; i++) {
            st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
            if(st[i][j-1] >= st[i + (1 << (j - 1))][j - 1]) {
                idx[i][j] = idx[i][j-1];
            } else {
                idx[i][j] = idx[i + (1 << (j - 1))][j - 1];
            }
        }
}

int query(int L, int R) {
	int j = logg[R - L + 1];
	if(st[L][j] >= st[R - (1 << j) + 1][j]) {
        return idx[L][j];
    }
    return idx[R - (1 << j) + 1][j];
}

// range of subtree of i will be [in[i], out[i]-1].
void dfs(int curr, int par = -1) {
    in[curr] = timer++;
    timertoidx[in[curr]] = curr;
    if(par >= 0) ht[in[curr]] = ht[in[par]] + 1;
    p[curr] = par;

    for(int nxt : g[curr]) {
        if(nxt != par) {
            dfs(nxt, curr);
        }
    }

    out[curr] = timer;
}

bool done[nax];

void solve(int curr) {
    int l = in[curr], r = out[curr] - 1;
    int htidx = query(l, r);
    int vertex = timertoidx[htidx];
    assert(!done[vertex]);
    
    bool nosolve = true; p[curr] = -1;
    while(vertex != -1) {
        done[vertex] = true;
        for(int v : g[vertex]) {
            if(v == p[vertex] || done[v]) continue;
            nosolve = false;
            solve(v);
        }
        vertex = p[vertex];
    }
    
    if(nosolve) res++; // consider 1 - 2 - 3 - 4.
}

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
    scanf("%d", &n);
    FOR(i, 0, n - 1) {
        scanf("%d %d", &a, &b);
        a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    memset(done, false, sizeof(done));
    memset(st, -1, sizeof(st));
    ht[0] = 0; p[0] = -1;
    dfs(0);
    pre(ht);
    solve(0);
    printf("%d", res);
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}