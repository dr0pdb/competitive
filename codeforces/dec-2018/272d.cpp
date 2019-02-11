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

ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
/*----------------------------------------------------------------------*/

ll fact(ll a) {
	if(a <= 1) {
		return 1;
	}

	ll ret = a;
	ret *= fact(a-1);
	ret %= MOD;
	return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    int n;
    cin>>n;

    map<int, int> freq;
    map<int, int> flag;

    int a[n],b[n];
    F(i, 0, n) {
    	cin>>a[i];
    	freq[a[i]]++;
    }
    F(i, 0, n) {
    	cin>>b[i];
    	if(b[i] == a[i]) flag[a[i]]++;
    	freq[b[i]]++;
    }

    cin>>MOD;
    ll ans = 1;
    for(auto itr: freq) {
    	F(cnt, 1, itr.second+1) {
    		ll tmp = cnt;
    		while(tmp%2==0 && flag[itr.first]>0) {
    			flag[itr.first]--;
    			tmp /= 2;
    		}

    		ans *= tmp;
    		ans %= MOD;
    	}
    }
    cout<<ans;

    return 0;
}/*

*/
