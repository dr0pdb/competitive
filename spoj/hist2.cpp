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

const int N = 15;
int arr[N],n;
ii dp[(1 << N)+1][101];

ii solve(int sofar, int last) {
	ii &ret = dp[sofar][last];
	if (ret.ff >= 0) return ret;
	ret = {0, 0};
	if (sofar == (1 << n) - 1)
	{
		ret = {last, 1};
		return ret;
	}
	int maxp = 0, maxf = 0;
	FOR(i, 0, n) {
		if (!(sofar & (1 << i)))
		{
			int pp = (2 + abs(last - arr[i]));
			ii res = solve((sofar | (1 << i)), arr[i]);
			pp += res.ff;
			if (pp > maxp)
			{
				maxp = pp;
				maxf = res.ss;
			} else if (pp == maxp)
			{
				maxf += res.ss;
			}
		}
	}
	ret = {maxp, maxf};
	return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(cin >> n && n) {
    	FOR(i, 0, n) cin>>arr[i];
    	memset(dp, -1, sizeof(dp));
    	ii ans = solve(0, 0);
    	cout<<ans.ff<<" "<<ans.ss<<endl;
    }

    return 0;
}