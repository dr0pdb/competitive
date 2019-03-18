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

class CreatureTraining
{
public:
	public:
		long long dp[52][102][102];
		int count[52], power[52], N;

		long long solve(int curr, int carry, int upgrades) {
			if(curr == N) return 0;
			ll &res = dp[curr][carry][upgrades];
			if(res >= 0) return res;
			res = 0;

			int max_possible = min(upgrades, count[curr] + carry);
			F(i, 0, max_possible+1) {
				ll this_power = power[curr] * (count[curr] + carry - i);
				ll future_ones = solve(curr+1, i, upgrades - i);
				res = max(res, this_power + future_ones); 
			}

			return res;
		}

	    long long maximumPower(vector <int> _count, vector <int> _power, int D) {
    	    N = _count.size();
    	    F(i, 0, _count.size()) {
    	    	count[i] = _count[i];
    	    	power[i] = _power[i];
    	    }

    	    memset(dp, -1, sizeof(dp));
    	    return solve(0,0,D);
	    }
};