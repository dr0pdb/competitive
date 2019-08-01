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

const int N = 5e4+5;
vi g[N];
int n,k,u,v;
ll dp[N][501], cnt[N];

void dfs(int curr, int par) {
	for(auto nxt : g[curr]) {
		if(nxt == par) continue;
		dfs(nxt, curr);
	}

	dp[curr][0]=1; cnt[curr]=0;
	FOR(i, 1, k+1) {
		for(auto nxt : g[curr]) {
			if(nxt == par) continue;
			dp[curr][i] += dp[nxt][i-1];
		}
	}
	FOR(i, 1, k) {
		for(auto nxt: g[curr]) {
			if(nxt == par) continue;
			cnt[curr] += dp[nxt][i-1]*(dp[curr][k-i] - dp[nxt][k-i-1]); 
		}
	}
	cnt[curr]/=2;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	cin>>n>>k;
    FOR(i, 0, n-1) {
    	cin>>u>>v; u--; v--;
    	g[u].push_back(v); g[v].push_back(u);
    }
    memset(dp, 0, sizeof(dp)); memset(cnt, 0, sizeof(cnt));
    dfs(0, -1);
    ll ans = 0;
    FOR(i, 0, n) {
    	ans += dp[i][k] + cnt[i];
    }
    cout<<ans;
    return 0;
}