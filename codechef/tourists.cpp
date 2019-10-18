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

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using maxpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using minpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int N = 1e5+5;
set<int> g[N];
int deg[N] = {0}, vcount = 0;
bool visited[N], poss = true;
vii edges;

void dfs(int curr) {
    visited[curr] = true; vcount++;
    while(!g[curr].empty()) {
        int idx = *g[curr].begin();
        int nxt = curr ^ edges[idx].ff ^ edges[idx].ss; // either curr = edges[idx].ff or curr = edges[idx].ss

        if(nxt != edges[idx].ss) {
            swap(edges[idx].ff, edges[idx].ss);
        }

        g[curr].erase(idx);
        g[nxt].erase(idx);

        dfs(nxt);
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m,u,v; cin>>n>>m;
    FOR(i, 0, m) {
        cin>>u>>v; u--; v--;
        g[u].insert(edges.size());
        g[v].insert(edges.size());
        edges.push_back({u, v});
        deg[u]++; deg[v]++;
    }
    memset(visited, false, sizeof(visited));
    dfs(0);
    
    FOR(i, 0, n) {
        poss &= (deg[i] % 2 == 0);
        poss &= visited[i];
    }
    if(!poss) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    FOR(i, 0, m) {
        cout<<edges[i].ff+1<<" "<<edges[i].ss+1<<endl;
    }
    return 0;
}