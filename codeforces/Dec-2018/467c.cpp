#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define SIEVELIM 10000000+10
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"
#define printCase() "Case #" << caseNum << ": "

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

const ll MOD = 1000000007;
const ll INF = 1e15+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
/*----------------------------------------------------------------------*/

ll arr[5005];
ll sums[5005];
ll dp[5005][5005];
int n,m,k;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    cin>>n>>m>>k;
    memset(sums, 0, sizeof(sums));
    F(i, 0, n) {
    	cin>>arr[i];
    	sums[i+1] = arr[i];
		sums[i+1] += sums[i];
    }

    F(i, 1, n+2) {
    	dp[i][0]=0;
    	F(j, 1, n+2) {
    		dp[i][j] = -INF;
    	}
    }

	F(i, 1, n+1) {
    	F(j, 1, k+1) {
    		dp[i][j] = dp[i-1][j];
    		if(i >= m) {
    			// deb(sums[i] - sums[i-k] + dp[i-k][j-1]);
    			dp[i][j] = max(dp[i][j], sums[i] - sums[i-m] + dp[i-m][j-1]);
    		}
    		// cout<<dp[i][j]<<" ";
    	}
    	// cout<<endl;
    }

    ll ans = 0;
    F(i, 1, n+1) {
    	ans = max(ans, dp[i][k]);
    }
    cout<<ans;

    return 0;
}/*

*/
