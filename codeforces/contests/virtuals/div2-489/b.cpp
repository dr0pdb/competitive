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
bitset<1000002> bs;
vi primes;

map<ll,ll> primeFactors(ll N) {
	map<ll,ll> factors;
	ll PF_idx = 0, PF = primes[PF_idx];
	while (PF * PF <= N) {
		int cnt = 0;
		while (N % PF == 0) { N /= PF; cnt++; }
		
		if(cnt) {
			factors[PF] = cnt;
		}

		PF = primes[++PF_idx];
		
	}
	if (N != 1) factors[N] = 1;

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

//return x^y
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

ll cnt = 0;
const int N = 1e6+1;
map<ll,ll> facts[2];
ll l,r,x,y;

bool isValid(ll value) {
	return value >= l && value <= r;
}

void solve(map<ll,ll>::iterator itr1, map<ll,ll>::iterator itr2, ll val1, ll val2) {
	if(itr1 == facts[0].end()) {
		if(val1 <= val2 && isValid(val1) && isValid(val2)) {
			// deb(val1); deb(val2);
			cnt++;
			if(val1 != val2) {
				cnt++;
			}
		}
		return;
	}

	ll tval1 = val1*(power(itr1 -> first, itr1->second));
	ll tval2 = val2*(power(itr2 -> first, itr2->second));
	map<ll,ll>::iterator titr1 = itr1, titr2 = itr2;
	titr1++; titr2++;
	solve(titr1, titr2, tval1, tval2);

	tval1 = val1*(power(itr2 -> first, itr2->second));
	tval2 = val2*(power(itr1 -> first, itr1->second));
	itr1++; itr2++;
	solve(itr1, itr2, tval1, tval2);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    sieve(N);
    cin>>l>>r>>x>>y;
    
    if(x > r || y < l) {
    	cout<<0;
    	return 0;
    }

    facts[0] = primeFactors(x);
    facts[1] = primeFactors(y);

    // auto itr1 = facts[0].begin();
    for(auto itr2: facts[1]) {
    	if(facts[0].find(itr2.first) == facts[0].end()) {
    		facts[0][itr2.first] = 0;
    	} else if(facts[0][itr2.first] > itr2.second) {
    		cout<<0;
    		return 0;
    	}
    }

    for(auto itr1: facts[0]) {
    	if(facts[1].find(itr1.first) == facts[1].end()) {
    		cout<<0;
    		return 0;
    	}
    }

    // assert(facts[0].size() == facts[1].size());
    solve(facts[0].begin(), facts[1].begin(), 1LL, 1LL);
    cout<<cnt;

    return 0;
}/*

*/
