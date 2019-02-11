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
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
/*----------------------------------------------------------------------*/

ll getWhites(ii a, ii b) {
	ll nrows = b.first - a.first + 1;
	ll ncols = b.second - a.second + 1;

	ll ret = nrows*ncols/2;
	if(nrows%2 == 1 && ncols%2 == 1 && a.first%2 == 1) {
		ret++;
	}

	return ret;
}

ll getblacks(ii a, ii b) {
	ll nrows = b.first - a.first + 1;
	ll ncols = b.second - a.second + 1;

	ll ret = nrows*ncols/2;
	if(nrows%2 == 1 && ncols%2 == 1 && a.first%2 == 0) {
		ret++;
	}

	return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    int t,rows,cols;
    ii whites[2],blacks[2];
    int w,b;
    cin>>t;

    while(t--) {
    	cin>>rows>>cols;
    	w = getWhites({1, 1}, {rows, cols});
    	b = getblacks({1, 1}, {rows, cols});

    	cin>>whites[0].first>>whites[0].second>>whites[1].first>>whites[1].second;
    	ll ww = getWhites(whites[0], whites[1]);
    	ll wb = getblacks(whites[0], whites[1]);
    	w -= ww;
    	b -= wb;
    	
    	cin>>blacks[0].first>>blacks[0].second>>blacks[1].first>>blacks[1].second;
    	
    }

    return 0;
}/*

*/
