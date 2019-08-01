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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    pre();
    ll ans;
    ll t,n,zeroes,ones; cin>>t;
    while(t--) {
    	cin>>n;
    	zeroes = n/2; ones = n/2 + (n%2);
    	ll h = log2(n)+1;
    	ll alpha = power(2LL, h-1, MOD)-2; alpha /= 2;
    	ll p2h2 = power(2LL, h-2, MOD);
    	
    	// zero on top
    	ll ztop = binomial_coefficient(zeroes, alpha+1) * binomial_coefficient(ones, alpha); ztop %= MOD;
    	ztop *= factorial[alpha]; ztop %= MOD;
    	ztop *= factorial[alpha+1]; ztop %= MOD;
    	ztop *= binomial_coefficient(p2h2, zeroes-alpha-1); ztop %= MOD;
    	ztop *= factorial[zeroes-alpha-1]; ztop %= MOD;
    	ztop *= binomial_coefficient(p2h2, ones-alpha); ztop %= MOD;
    	ztop *= factorial[ones-alpha]; ztop %= MOD;

    	// one on top
    	ll otop = binomial_coefficient(zeroes, alpha) * binomial_coefficient(ones, alpha+1); otop %= MOD;
    	otop *= factorial[alpha]; otop %= MOD;
    	otop *= factorial[alpha+1]; otop %= MOD;
    	otop *= binomial_coefficient(p2h2, zeroes-alpha); otop %= MOD;
    	otop *= factorial[zeroes-alpha]; otop %= MOD;
    	otop *= binomial_coefficient(p2h2, ones-alpha-1); otop %= MOD;
    	otop *= factorial[ones-alpha-1]; otop %= MOD;

    	ans = ztop + otop; ans %= MOD;
    	cout<<ans<<endl;
    }

    return 0;
}