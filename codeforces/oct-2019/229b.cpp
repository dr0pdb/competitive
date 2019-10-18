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
const ll INF = INT_MAX;
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

const int N = 1e5+5;
vii g[N];
int dist[N];
minpq<ii> pq; // time and idx.
vii arrivals[N]; // {i,j} continuous arrivals from time i to j.

int getNextValidTime(int curr, int tm) {
    int sz = arrivals[curr].size();
    int lo = 0, hi = sz - 1, res = -1;
    while(lo <= hi) {
        int mid = (lo + hi)/2;
        if(arrivals[curr][mid].ff <= tm) {
            lo = mid + 1;
            res = max(res, mid);
        } else hi = mid - 1;
    }
    int ret = tm;
    if(res != -1) ret = max(ret, arrivals[curr][res].ss + 1);
    return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
    int n,m,u,v,wt; cin>>n>>m;
    FOR(i, 0, m) {
        cin>>u>>v>>wt; u--; v--;
        g[u].push_back({v, wt}); g[v].push_back({u, wt});
    }
    int k,t;
    FOR(i, 0, n) {
        cin>>k;
        dist[i] = INF;
        FOR(j, 0, k) {
            cin>>t;
            if(!arrivals[i].empty() && arrivals[i].back().ss == (t - 1)) {
                arrivals[i].back().ss = t;
            } else arrivals[i].push_back({t, t});
        }
    }
    dist[0] = getNextValidTime(0, 0);
    pq.push({dist[0], 0}); int res = INF;
    while(!pq.empty()) {
        ii curr = pq.top(); pq.pop();
        if(curr.ff > dist[curr.ss]) continue; // lazy deletion.
        for(auto nxt : g[curr.ss]) {
            tie(v, wt) = nxt;
            if(v == n - 1) res = min(res, dist[curr.ss] + wt);
            int nd = getNextValidTime(v, dist[curr.ss] + wt);
            if(dist[v] > nd) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    if(res == INF) res = -1;
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}