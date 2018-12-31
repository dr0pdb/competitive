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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    int n,b;
    cin>>n>>b;

    int arr[n];
    int o[n],e[n];
    memset(o, 0, sizeof(o));
    memset(e, 0, sizeof(e));
    vii poss;
    F(i, 0, n) {
    	cin>>arr[i];
    	if(i) {
    		o[i] = o[i-1];
    		e[i] = e[i-1];
    	}

    	if(arr[i] % 2 == 1) {
    		o[i]++;
    	} else {
    		e[i]++;
    	}
    }

    F(i, 0, n-1) {
    	if(o[i] == e[i]) {
    		// deb(i);
    		poss.push_back({abs(arr[i] - arr[i+1]), i});
    	}
    }
    int cnt = 0;
    sort(poss.begin(), poss.end());

    F(i, 0, poss.size()) {
    	if(poss[i].first <= b) {
    		cnt++;
    		b -= poss[i].first;
    	}
    }
    cout<<cnt;

    return 0;
}/*

*/
