#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 0x3f3f3f3f
#define SIEVELIM 10000000+10
#define EPS 1e-7
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
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
inline double nextdouble(){double temporary; scanf("%lf",&temporary); return temporary;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll leftChild(ll p ){return p<<1;}
ll rightChild(ll p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
const ll MOD = 1000000007;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define deb(x )     cerr << #x << " here "<< x; 
#define endl    "\n"
#define pb push_back
#define mp make_pair
#define all(cc) (cc).begin(),(cc).end()

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

template<typename T > void modulize(T & a, const T & b) { if (a >= b) { a %= b; } }
ll mulmod(ll a, ll b, ll m) { ll q = (ll)(((ld)a*(ld)b) / (ld)m); ll r = a*b - q*m; if (r>m)r %= m; if (r<0)r += m; return r; }
template <typename T, typename S>T expo(T e, S n) { T x = 1, p = e; while (n) { if (n & 1)x = x*p; p = p*p; n >>= 1; }return x; }
template <typename T>T power(T e, T n, T & m) { T x = 1, p = e; while (n) { if (n & 1)x = mod(x*p, m); p = mod(p*p, m); n >>= 1; }return x; }
template <typename T>T powerL(T e, T n, T & m) { T x = 1, p = e; while (n) { if (n & 1)x = mulmod(x, p, m); p = mulmod(p, p, m); n >>= 1; }return x; }
template <typename T> T InverseEuler(T a, T & m) { return (a == 1 ? 1 : power(a, m - 2, m)); }
/*----------------------------------------------------------------------*/

// ll _sieve_size;
// bitset<10000010> bs;
// vi primes;

// void sieve(ll upperbound) {

// 	_sieve_size = upperbound + 1;
	
// 	bs.set();
// 	bs[0] = bs[1] = 0;
	
// 	for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
	
// 		for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
// 		primes.push_back((int)i);
		
// 	} 
// }


// bool isPrime(ll N) {

// 	if (N <= _sieve_size) return bs[N];

// 	for (int i = 0; i < (int)primes.size(); i++)
// 		if (N % primes[i] == 0) return false;
// 	return true;

// }

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	ll n;
	cin>>n;

	if (n<3)
	{
		cout<<n;
		return 0;
	}
	if (n==3)
	{
		cout<<6;
		return 0;
	}

	ll ans = -INF;

	RF(i, n, max(n-50,0LL)){
		RF(j, i-1, max(n-50,0LL)){
			RF(k, j-1, max(n-50,0LL)){
				ll temp = i*j*k;
				ll t = gcd(i*j, gcd(j*k,k*i));
				ans = max(ans, temp/t);
			}
		}
	}
	cout<<ans;
	return 0;    	   
}