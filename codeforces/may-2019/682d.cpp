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

const int N = 1001;
int n,m,k;
string s,t;
int dp[N][N][11];

int solve(int i1, int i2, int ks) {
	if(i1 == n || i2 == m || ks < 0) {
		if(ks) return -INF;
		return 0;
	}
	int &ret = dp[i1][i2][ks];
	if(ret >= 0) return ret;
	ret = 0;
	int sm = (s[i1] == t[i2]), psm = (i1 > 0 && i2 > 0 && s[i1-1] == t[i2-1]);
	if(sm) {
		if(ks > 0)
			ret = max(ret, 1 + solve(i1+1, i2+1, ks-1));
		if(psm) ret = max(ret, 1 + solve(i1+1, i2+1, ks));
	}
	ret = max(ret, solve(i1+1, i2+1, ks));
	ret = max(ret, solve(i1 + 1, i2, ks));
	ret = max(ret, solve(i1, i2+1, ks));
	return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m>>k>>s>>t;
    memset(dp, -1, sizeof(dp));
    int ans = solve(0, 0, k);
    cout<<ans;
    return 0;
}