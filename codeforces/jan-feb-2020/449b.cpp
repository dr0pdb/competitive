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
const ll INF = 1e15+5;
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

const int nax = 1e5+5;
int n,m,k;
vector<iii> g[nax]; // iii : dist, 0/1(1 for road, 0 for train), neighbour
bool used[nax];
int cnt[nax];
ll dist[nax];
vii trains;

void dijkstra() {
    FOR(i, 0, n) {
        used[i] = false;
        dist[i] = INF;
        cnt[i] = 0;
    }

    maxpq<pair<ll, ii> > pq;
    pq.push({0, {1, 0}}); // -dist, train/road, curr

    ll d;
    bool b; int curr;
    while(!pq.empty()) {
        auto c = pq.top(); pq.pop();

        d = -c.ff; tie(b, curr) = c.ss;
        if(dist[curr] <= d) continue;
        // deb(curr);
        used[curr] = b;
        dist[curr] = d;

        for(auto e : g[curr]) {
            ll nd = d + e.ff;
            bool nb = e.ss.ff;
            int nxt = e.ss.ss;

            if(dist[nxt] > nd) {
                pq.push({-nd, {nb, nxt}});
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n>>m>>k;
    int a,b,x;
    FOR(i, 0, m) {
        cin>>a>>b>>x; a--; b--;
        g[a].pb({x, {1, b}});
        g[b].pb({x, {1, a}});
    }
    FOR(i, 0, k) {
        cin>>a>>x; a--;
        g[a].pb({x, {0, 0}});
        g[0].pb({x, {0, a}});
        trains.pb({a, x});
    }
    dijkstra();
    int res = 0;
    for(auto e : trains) {
        tie(a, x) = e;
        assert(dist[a] <= x);
        if(x > dist[a]) res++;
        else {
            if(used[a] || cnt[a]) res++;
            else cnt[a]++;
        }
    }
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}