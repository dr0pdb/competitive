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

const int N = 31;
int tickets, cities, m, a,b;
int th[10];
vii g[N];
double dp[31][(1 << 8)];

void reset() {
	memset(dp, -1, sizeof(dp));
	FOR(i, 0, N) g[i].clear();
}

double solve(int curr, int sofar, int tused) {
	double &ret = dp[curr][sofar];
	if (ret >= 0) return ret;
	if (curr == b)
	{
		return ret = 0;
	}
	if (tused == tickets)
	{
		if (curr == b)
		{
			return ret = 0;
		} else {
			return ret = INF;
		}
	}
	ret = INF;
	for(auto elem : g[curr]) {
		int nxt,dist; tie(nxt, dist) = elem;
		FOR(i, 0, tickets) {
			if (!(sofar & (1 << i)))
			{
				double cost = dist * 1.0 / th[i];
				cost += solve(nxt, (sofar | (1 << i)), tused+1);
				ret = min(ret, cost);
			}
		}
	}
	return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(cin>>tickets>>cities>>m>>a>>b && (tickets)) {
    	FOR(i, 0, tickets) {
    		cin>>th[i];
    	}
    	int u,v,w; a--; b--;
    	reset();
    	FOR(i, 0, m) {
    		cin>>u>>v>>w;
    		u--; v--;
    		g[u].push_back({v, w}); g[v].push_back({u, w});
    	}
    	double ans = solve(a, 0, 0);
    	if (ans > 1e5)
    	{
    		cout<<"Impossible";
    	} else {
    		coud(ans, 10);
    	}
    	cout<<endl;
    }

    return 0;
}