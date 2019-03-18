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

class RoadOrFlightHard
{
public:
	public:
		const static int MAXN = 4e5+1;
		int N, roadFirst, roadProd, roadAdd, roadMod, flightFirst, flightProd, flightAdd, flightMod, K;
		ll dp[MAXN][41];

		ll get_next_road_cost(ll road_cost) {
			return (((road_cost)*roadProd)%roadMod + roadAdd)%roadMod;
		}

		ll solve(int curr, int k, int current_road_cost) {
			if(curr == N) return 0;
			ll &res = dp[curr][k];
			if(res >= 0) return res;
			res = current_road_cost + solve(curr+1, k, get_next_road_cost(current_road_cost));

			if(k) {
				F(i, curr+1, N+1) {
					// res = min(res, flight_cost[i]-flight_cost[curr] + solve(i, k-1));
				}
			}

			return res;
		}

	    long long minTime(int N, int roadFirst, int roadProd, int roadAdd, int roadMod, int flightFirst, int flightProd, int flightAdd, int flightMod, int K) {
    	    memset(dp, -1, sizeof(dp));
    	    this->N = N;
    	    this->flightMod = flightMod;
    	    this->roadMod = roadMod;
    	    this->flightProd = flightProd;
    	    this->roadProd = roadProd;
    	    this->roadAdd = roadAdd;
    	    this->flightAdd = flightAdd;
    	    return solve(0, K, roadFirst%roadMod);
	    }
};