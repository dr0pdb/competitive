#include<bits/stdc++.h>
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
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
inline void debug_vi(vi a) {F(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {F(i, 0, a.size()) cout<<a[i]<<" ";}
/*----------------------------------------------------------------------*/

const int N = 1e5+5;
int n,u,v;
vi g[N];
ll dp[N][2];

ll solve(int curr, int par, int color) {
	if(dp[curr][color] != -1) return dp[curr][color];

	ll ret = 1;

	for(auto next : g[curr]) {
		if(next != par) {
			if (color == 0)
			{
				ret *= (solve(next, curr, 0) + solve(next, curr, 1))%MOD;
				ret %= MOD;
			} else {
				ret *= solve(next, curr, 0);
				ret %= MOD;
			}
		}
	}

	return dp[curr][color] = ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n;

    memset(dp, -1, sizeof(dp));
    F(i, 0, n-1) {
    	cin>>u>>v;
    	u--; v--;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }

    cout<<(solve(0, -1, 0) + solve(0, -1, 1))%MOD;

    return 0;
}/*

*/