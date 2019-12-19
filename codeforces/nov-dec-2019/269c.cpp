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

int main() {
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int n,m,a,b,c; cin>>n>>m;
    vector<vector<pair<ii, ii>>> g(n); // v, c, idx and 0/1
    vi f(n, 0);
    FOR(i, 0, m) {
        cin>>a>>b>>c; a--; b--;
        g[a].push_back({{b, c}, {i, 0}});
        g[b].push_back({{a, c}, {i, 1}});
        f[a] += c;
        f[b] += c;
    }
    FOR(i, 1, n-1) f[i] /= 2;
    vi res(m, -1);
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        int v, r, idx;
        for(auto nxt : g[curr]) {
            tie(v, c) = nxt.ff; tie(idx, r) = nxt.ss;

            if(res[idx] == -1) {
                res[idx] = r;
                f[v] -= c;

                if(v != n-1 && f[v] == 0) q.push(v);
            }
        }
    }

    FOR(i, 0, m) {
        cout<<res[i]<<endl;
    }
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}