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
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) {

	_sieve_size = upperbound + 1;
	
	bs.set();
	bs[0] = bs[1] = 0;
	
	for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
	
		for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
		primes.push_back((int)i);
		
	} 
}


bool isPrime(ll N) {

	if (N <= _sieve_size) return bs[N];

	for (int i = 0; i < (int)primes.size(); i++)
		if (N % primes[i] == 0) return false;
	return true;

}

vector<pair<ll,ll> >  primeFactors(ll N) {
	vector<pair<ll,ll> > factors;
	ll PF_idx = 0, PF = primes[PF_idx];
	while (PF * PF <= N) {
		
		ll cnt = 0;
		while (N % PF == 0) { N /= PF; cnt++; }
		if(cnt) {
			factors.push_back({PF, cnt});
		}	

		PF = primes[++PF_idx];
		
	}
	if (N != 1) factors.push_back({N, 1});

	return factors;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    sieve(10000005);
    ll q;
    cin>>q;

    if(q == 1 || isPrime(q)) {
    	cout<<1<<endl<<0;
    	return 0;
    } else {
    	int cnt = 0;
    	ll step = 1;
    	std::vector<pair<ll,ll> > f = primeFactors(q);
    	F(i, 0, f.size()) {
    		cnt += f[i].second;
    	}

    	if(cnt == 2) {
    		cout<<2<<endl;
    	} else {
    		cout<<1<<endl;
    		ll tmp =  f[0].first;
    		if(f[0].second > 1) {
    			tmp *= f[0].first;
    		} else {
    			tmp *= f[1].first;
    		}
    		cout<<tmp;
    	}
    }

    return 0;
}/*

*/
