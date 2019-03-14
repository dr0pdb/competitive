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

const int N = 1e4+5;
int digs[N],n,d;
ll dp[N][105][2];

ll solve(int ind, int sofar, bool flag) {
	sofar %= d;

	if(ind == n) {
		if(sofar) return 0;
		return 1LL;
	}

	if(dp[ind][sofar][flag] != -1) {
		return dp[ind][sofar][flag];
	}

	ll ret = 0;

	F(i, 0, digs[ind]) {
		ret += solve(ind + 1, (sofar + i), false);
		ret %= MOD;
	}

	ret += solve(ind+1, (sofar + digs[ind]), flag);
	ret %= MOD;

	if(!flag) {
		F(i, digs[ind]+1, 10) {
			ret += solve(ind+1, (sofar + i), flag);
			ret %= MOD;
		}
	}

	return dp[ind][sofar][flag] = ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string k;
    cin>>k>>d;

    n = k.size();
    F(i, 0, n) {
    	digs[i] = k[i]-'0';
    }

    memset(dp, -1, sizeof(dp));
    ll ans = (solve(0, 0, true) - 1LL + MOD) % MOD;
    cout<<ans;

    return 0;
}/*

*/