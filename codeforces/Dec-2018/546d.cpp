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

const int N = 5e6+2;
ll _sieve_size;
ll primes[N];
ll sums[N], facts[N];

void sieve() {
	
    memset(primes, 0, sizeof(primes));
	primes[0]=primes[1]=0;
	
	for (ll i = 2; i < N; i++) { 
		if (primes[i])
			continue;

		for (ll j = i; j < N; j += i) {
			primes[j] = i;
		}
	}
}

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    sieve();
    memset(sums, 0, sizeof(sums));
    F(i, 2, N) {
    	sums[i] = sums[i-1];
    	facts[i] = facts[i/primes[i]] + 1;
    	sums[i] += facts[i];
    }

    int t,a,b;
    cin>>t;

    while(t--) {
    	scanf("%d %d",&a, &b);
    	printf("%lld\n", sums[a] - sums[b]);
    	// cout<<sums[a]-sums[b]<<endl;
    }

    return 0;
}/*

*/
