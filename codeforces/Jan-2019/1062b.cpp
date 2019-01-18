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

ll _sieve_size;
bitset<1000010> bs;
vi primes;

vii primeFactors(ll N) {
	vii factors;
	ll PF_idx = 0, PF = primes[PF_idx];
	while (PF * PF <= N) {
		
		int cnt = 0;
		while (N % PF == 0) { N /= PF; cnt++; }
			
		if(cnt) {
			factors.push_back({PF, cnt});
		}
		PF = primes[++PF_idx];
		
	}
	if (N != 1) factors.push_back({N, 1});

	return factors;
}

void sieve(ll upperbound) {
	
	_sieve_size = upperbound + 1;
	
	bs.set();
	bs[0] = bs[1] = 0;
	
	for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
		
		for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
		primes.push_back((int)i);
		
	} 
}

ll power(ll x,ll y)
{
    ll res = 1;     
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x);
 
        y = y>>1; // y = y/2
        x = (x*x);  
    }
    return res;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    sieve(1000005);
    int n;
    cin>>n;

    vii facts = primeFactors(n);
    int steps=0,amax=0, sz = facts.size(); ll val=1;
    F(i, 0, sz) {
		val *= facts[i].first;
		int tmp = (int)log2(facts[i].second);
		while(power(2, tmp) < facts[i].second) {
			tmp++;
		}
		amax = max(amax, tmp);
	}

	steps = amax;
	F(i, 0, sz) {
		int tmp = (int)log2(facts[i].second);
		while(power(2, tmp) > facts[i].second) {
			tmp--;
		}

		if(amax != tmp) {
			steps++;
			break;
		}
	}

    cout<<val<<" "<<steps;
    return 0;
}/*

*/
