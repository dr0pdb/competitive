/**
    __author__ : srv_twry
**/

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

bool ge(const ll& a, const ll& b) { return a >= b; }
bool le(const ll& a, const ll& b) { return a <= b; }
bool eq(const ll& a, const ll& b) { return a == b; }
bool gt(const ll& a, const ll& b) { return a > b; }
bool lt(const ll& a, const ll& b) { return a < b; }
int sgn(const ll& x) { return le(x, 0) ? eq(x, 0) ? 0 : -1 : 1; }
/*----------------------------------------------------------------------*/

const int N = 1e4+5;
vii adj[N];
vii nodes;
vi dist;
int n,m,k,x,y,starter;
ii target;

bool adjacent(int u, int v) {
	bool a = (nodes[u].ff == nodes[v].ff && (abs(nodes[u].ss - nodes[v].ss) == 1));	
	bool b = (nodes[u].ss == nodes[v].ss && (abs(nodes[u].ff - nodes[v].ff) == 1));	
	return a || b;
}

bool samerow(int u, int v) {
	return nodes[u].ff == nodes[v].ff;
}

bool samecolumn(int u, int v) {
	return (nodes[u].ss == nodes[v].ss);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
   	cin>>n>>m>>k;
    bool targetlit = false;
    FOR(i, 0, k) {
    	cin>>x>>y; x--; y--;
    	nodes.push_back({x, y});
    	if(x == 0 && y == 0) starter = i;
    	if(x == n-1 && y == m-1) targetlit = true;
    }
    target = {n-1, m-1};
    if (!targetlit)
    {
    	nodes.push_back(target);
    	k++;
    }
    dist.resize(k, -1);
    FOR(i, 0, k) {
    	FOR(j, i+1, k) {
    		if((nodes[i] == target || nodes[j] == target) && !targetlit) {
    			if(adjacent(i, j) || samerow(i, j) || samecolumn(i, j)) {
    				adj[i].push_back({j, 1});
    				adj[j].push_back({i, 1});
    			}
    			continue;
    		}

    		if(adjacent(i, j)) {
    			adj[i].push_back({j, 0});
    			adj[j].push_back({i, 0});
    		} else if(samerow(i, j) || samecolumn(i, j)) {
    			adj[i].push_back({j, 1});
    			adj[j].push_back({i, 1});
    		}
    	}
    }
    queue<ii> q; q.push(nodes[starter]);
    dist[starter] = 0;
    while(!q.empty()) {
    	ii curr = q.front(); q.pop();
    	int nidx = curr.ff, cost = curr.ss;

    	for(auto itr : adj[nidx]) {
    		int nxt = itr.ff, wt = itr.ss;
    		if(dist[nxt] == -1) {
    			dist[nxt] = cost + wt;
    			if(nodes[nxt] == target) {
    				cout<<dist[nxt];
    				return 0;
    			}
    			q.push({nxt, dist[nxt]});
    		}
    	}
    }
    cout<<-1;
    return 0;
}