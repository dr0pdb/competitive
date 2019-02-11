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

ll _sieve_size;
bitset<10000010> bs;
vll primes;

vector<lll> primeFactors(ll N) {
	vector<lll> factors;
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

	// sort(factors.begin(), factors.end());
	return factors;
}

void sieve(ll upperbound) {
	
	_sieve_size = upperbound + 1;
	
	bs.set();
	bs[0] = bs[1] = 0;
	
	for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
		
		for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
		primes.push_back(i);
	}
}

ll fact_pow (ll n, ll k) {
    ll res = 0;
    while (n) {
        n /= k;
        res += n;
    }
    return res;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,b;
    cin>>n>>b;

    sieve(10000001);
    vector<lll> facts = primeFactors(b);
    ll ans = LONG_LONG_MAX;
    for(lll curr : facts) {
    	ans = min(ans, fact_pow(n, curr.first)/curr.second);	
    }
    cout<<ans;

    return 0;
}/*

*/