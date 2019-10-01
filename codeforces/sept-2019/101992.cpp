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

const int N = 1e5+5;
vii adj[N];
vector<bool> marked[N];
int dist[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    freopen("path.in", "r", stdin);
	int t,n,m,u,l,k,a,b,w; cin>>t;
	while(t--) {
		cin>>n>>m>>u>>l>>k; u--;
		FOR(i, 0, n) {
			adj[i].clear();
			marked[i].clear();
		}
		FOR(i, 0, m) {
			cin>>a>>b>>w; a--; b--;
			adj[a].push_back({b, w});
			marked[a].push_back(false);
			adj[b].push_back({a, w});
			marked[b].push_back(false);
		}
		memset(dist, -1, sizeof(dist));
		queue<ii> q;
		dist[u] = 0; q.push({u,0});
		int ans = 0;
		while(!q.empty()) {
			int curr = q.front().ff; int steps = q.front().ss; q.pop();
			for(int idx = 0; idx < adj[curr].size(); idx++) {
				auto itr = adj[curr][idx];
				bool mark = marked[curr][idx];
				if(mark) continue;
				int nxt = itr.ff, wt = itr.ss;
				if(steps + 1 <= k) {
					ans = max(ans, wt);
					marked[curr][idx] = true;
					q.push({nxt, steps+1});
				}
			}
		}
		cout<<ans<<endl;
	}

    return 0;
}