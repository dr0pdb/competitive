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
const ll MOD = 11380;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

int l1,l2,l3,d;
int dp[11][11][11][31];

int solve(int l1, int l2, int l3, int dd) {
	int &ret = dp[l1][l2][l3][dd];
	if (ret >= 0) return ret;
	if (l1 + l2 + l3 == 0)
	{
		if (dd)
		{
			return ret = 0;
		}
		return ret = 1;
	}
	if (dd > l1 + l2 + l3)
	{
		return ret = 0;
	}
	if (!dd)
	{
		return ret = 0;
	}
	ret = 0;
	// no of {} in first half
	FOR(tp1, 0, l1+1) {
		FOR(tp2, 0, l2+1) {
			FOR(tp3, 0, l3+1) {
				FOR(depth1, 0, dd) { // depth of the first part.
					int lo, hi;
					if (depth1 == (dd - 1))
					{
						// the depth requirement satisfied by the first part only.
						// so the second part can be of any depth.
						lo = 0; hi = dd;
					} else {
						// if left part has depth < dd -1, then 
						// depth requirements needs to be satisfied by right part.
						lo = dd; hi = dd;
					}

					FOR(depth2, lo, hi+1) {
						if (tp1 < l1)
						{
							ret += solve(tp1, tp2, tp3, depth1) * solve(l1 - tp1 -1, l2 - tp2, l3 - tp3, depth2);
						}
						if (tp2 < l2 && (tp1 == 0))
						{
							ret += solve(tp1, tp2, tp3, depth1) * solve(l1 - tp1, l2 - tp2 - 1, l3 - tp3, depth2);
						}
						if (tp3 < l3 && (tp1 == 0 && tp2 == 0))
						{
							ret += solve(tp1, tp2, tp3, depth1) * solve(l1 - tp1, l2 - tp2, l3 - tp3 - 1, depth2);	
						}

						ret %= MOD;
					}
				}
			}
		}
	}
	return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    FOR(tn, 0, 10) {
    	cin>>l1>>l2>>l3>>d;
    	memset(dp, -1, sizeof(dp));
    	cout<<solve(l1, l2, l3, d)<<endl;
    }

    return 0;
}