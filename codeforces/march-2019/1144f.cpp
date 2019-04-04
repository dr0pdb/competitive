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

const int N = 2e5+5;
vi g[N];
int n,m,u,v;
bool visited[N], color[N], poss = true;
vii edges;

void dfs(int curr) {
	if(!poss) return;
	visited[curr]=true;
	for(auto next: g[curr]) {
		if(!visited[next]) {
			visited[next] = true;
			color[next]= !color[curr];
			dfs(next);
		} else if(color[curr] ==  color[next]) {
			poss = false;
			return;
		}
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    FOR(i, 0, m) {
    	cin>>u>>v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    	edges.push_back({u, v});
    }

    memset(visited, false, sizeof(visited));
    memset(color, false, sizeof(color));
    FOR(i, 1, n+1) {
    	if(!visited[i]) {
    		dfs(i);
    	}
    }

    if(!poss) {
    	cout<<"NO";
    	return 0;
    }

    string ans="";
    FOR(i, 0, edges.size()) {
    	u = edges[i].ff, v = edges[i].ss;
    	if(color[u] == color[v]) {
    		cout<<"NO";
    		return 0;
    	}

    	if(color[u]) {
    		ans.push_back('1');
    	} else {
    		ans.push_back('0');
    	}
    }
    cout<<"YES\n";
    cout<<ans;

    return 0;
}