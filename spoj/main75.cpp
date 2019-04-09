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

const int N = 505;
ll dp[N][N],sum[N][N];

void solve() {
	memset(dp, 0, sizeof(dp));
	memset(sum, 0, sizeof(sum));

	dp[1][0]=1;
	FOR(j, 0, N) {
		sum[0][j]=1;
		sum[1][j]=1;
	}

	FOR(i, 2, N) {
		FOR(j, 1, N) {
			FOR(k, 1, i+1) {
				dp[i][j] = (dp[i][j] 
					        + dp[k - 1][j - 1] * sum[i - k][j - 1]
					        + dp[i - k][j - 1] * sum[k - 1][j - 1] 
					        - dp[k - 1][j - 1] * dp[i - k][j - 1]
					        + MOD) % MOD;
			}
			sum[i][j] = (sum[i][j-1] + dp[i][j])%MOD;
		}
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,n,h;
    solve();
    cin>>t;
    while(t--) {
    	cin>>n>>h;
    	cout<<dp[n][h];
    	if(t) cout<<endl;
    }

    return 0;
}