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

pair<ll,ll> pts[2005];
map<iii,set<ll> > m;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    ll n;
    cin>>n;

    F(i, 0, n) {
    	cin>>pts[i].first>>pts[i].second;
    }

    F(i, 0, n) {
    	F(j, i+1, n) {
    		ll cx = pts[j].second - pts[i].second;
    		ll cy = pts[j].first - pts[i].first;
    		if(cx < 0) {
    			cx *= -1;
    			cy *= -1;
    		}
    		if(cx == 0 && cy < 0)
    			cy *= -1;

    		ll g = __gcd(cx, abs(cy));
    		ll cc = (pts[j].first*pts[i].second) - (pts[j].second*pts[i].first);
    		g = __gcd(g, abs(cc));
    		if(g) {
    			cx /= g; cy /= g; cc /= g;
    		}

    		m[{cc, {cx, cy}}].insert(i);
    		m[{cc, {cx, cy}}].insert(j);
    	}
    }

    ll ans = (n*(n-1)*(n-2))/6;
    for(auto itr: m) {
    	ll sz = itr.second.size();
    	ans -= (sz*(sz-1)*(sz-2))/6;
    }
    cout<<ans;

    return 0;
}/*

*/