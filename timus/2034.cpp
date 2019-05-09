#include<bits/stdc++.h>
#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"
#define printCase() "Case #" << caseNum << ": "
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

const int N = 1e5+1;
int n,m,s,f,r,u,v;
vi g[N];
int rdist[N];
ii dist[N];

void bfs() {
	memset(rdist, -1, sizeof(rdist));
	queue<int> q; q.push(r);
	rdist[r]=0;
	while(!q.empty()) {
		int cr = q.front(); q.pop();
		for(auto nxt: g[cr]) {
			if(rdist[nxt] == -1) {
				rdist[nxt] = rdist[cr] + 1;
				q.push(nxt);
			}
		}
	}
}

void bfs2() {
	FOR(i, 0, n) {
		dist[i] = {-1, rdist[i]};
	}
	queue<int> q; q.push(s);
	dist[s].ff = 0;
	while(!q.empty()) {
		int curr = q.front(); q.pop();
		if(curr == f) break;
		for(int nxt : g[curr]) {
			int nxtdist = min(dist[curr].ss, rdist[nxt]);
			if(dist[nxt].ff == -1 || (dist[curr].ff + 1 == dist[nxt].ff && nxtdist > dist[nxt].ss)) {
				if(dist[nxt].ff == -1) q.push(nxt);
				dist[nxt] = {dist[curr].ff + 1, nxtdist}; // taking the maximum of the minimum.
			}
		}
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    FOR(i, 0, m) {
    	cin>>u>>v; u--; v--;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    cin>>s>>f>>r; s--; f--; r--;
    bfs();
    bfs2();
    cout<<dist[f].ss;

    return 0;
}