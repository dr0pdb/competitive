#include<bits/stdc++.h>
#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
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
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

const int MAXN = 2e6+5;
ll _sieve_size;
bitset<1000010> bs;
vi primes;
ll factorial[MAXN], inverse[MAXN];

ll power(ll x,ll y, ll p)
{
    ll res = 1;     
    x = x % p; 
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}

ll modInverse(ll a, ll m){
    return power(a,m-2,m);
}

void pre() {
    factorial[0] = 1LL; inverse[0] = modInverse(factorial[0], MOD);
    for (int i = 1; i < MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
        inverse[i] = modInverse(factorial[i], MOD);
    }
}

ll binomial_coefficient(ll n, ll k) {
    return factorial[n] * inverse[k] % MOD * inverse[n - k] % MOD;
}

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
	if (N != 1) factors.push_back({N,1});

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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    sieve(1e6+5);
    pre();
    int q,x,y;
    ll ans;
    cin>>q;
    while(q--) {
    	cin>>x>>y;
    	vii facts = primeFactors(x);

    	ans = 1;
    	for(ii num : facts) {
    		ans *= binomial_coefficient(num.second + y - 1, num.second);
    		ans %= MOD;
    	}

    	ans *= power(2, y-1, MOD);
    	ans %= MOD;
    	cout<<ans<<endl;
    }

    return 0;
}