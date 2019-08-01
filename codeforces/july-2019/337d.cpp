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

const int N = 1e5+5;
vi g[N];
bool marked[N];
int n,m,d,u,v,cnt=0,maxi,maxm;
int dist[N],dist2[N];

void dfs(int curr, int par, int dist[]) {
	for(auto nxt : g[curr]) {
		if(nxt != par) {
			dist[nxt] = dist[curr] + 1;
			if (marked[nxt] && maxm < dist[nxt]) {
				maxm = dist[nxt];
				maxi = nxt;
			}
			dfs(nxt, curr, dist);
		}
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>m>>d; memset(marked, false, sizeof(marked));
    int tmp;
    FOR(i, 0, m) {
    	cin>>u; u--; marked[u]=true;
    	tmp = u;
    }
    FOR(i, 0, n-1) {
    	cin>>u>>v; u--; v--;
    	g[u].push_back(v); g[v].push_back(u);
    }
    memset(dist, -1, sizeof(dist)); memset(dist2, -1, sizeof(dist2));
    dist[tmp]=0; maxi = tmp; maxm = 0;
    dfs(tmp, -1, dist);
    
    memset(dist, -1, sizeof(dist));
   	dist[maxi]=0; maxm = 0;
   	dfs(maxi, -1, dist);

   	dist2[maxi]=0; maxm = 0;
   	dfs(maxi, -1, dist2);
   	FOR(i, 0, n) {
		if(dist[i] <= d && dist2[i] <= d) {
			cnt++;
		}
   	}
   	cout<<cnt;

    return 0;
}