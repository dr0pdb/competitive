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

const int N = 3005;
ll dp[N][N], pref[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n; string s; cin>>s;
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
    FOR(i, 2, n + 1) {
    	memset(pref, 0, sizeof(pref));
    	FOR(j, 1, n+1) {
    		pref[j] = (pref[j - 1] + dp[i-1][j])%MOD;
    	}
    	FOR(j, 1, i+1) {
    		int lo, hi;
    		if (s[i-2] == '<')
    		{
				lo = 1;
				hi = j-1;
    		} else {
    			lo = j;
    			hi = n - 1;
    		}
    		if (lo <= hi)
    		{
    			dp[i][j] += (pref[hi] - pref[lo-1] + MOD)%MOD;
    			dp[i][j] %= MOD;	
    		}
    	}
    }
    ll ans = 0;
    FOR(i, 1, n+1) {
    	ans += dp[n][i];
    	ans %= MOD;
    }
    cout<<ans;
    return 0;
}