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
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
inline double nextdouble(){double temporary; scanf("%lf",&temporary); return temporary;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll leftChild(ll p ){return p<<1;}
ll rightChild(ll p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
const ll MOD = 1000000007;
const ll INF = 1e9+5;
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

inline int two(int n) { return 1 << n; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
/*----------------------------------------------------------------------*/

ll _sieve_size;
bitset<100010> bs;
vi primes;

vi primeFactors(ll N) {
	vi factors;
	ll PF_idx = 0, PF = primes[PF_idx];
	while (PF * PF <= N) {
		
		while (N % PF == 0) { N /= PF; factors.push_back(PF); }
			
		PF = primes[++PF_idx];
		
	}
	if (N != 1) factors.push_back(N);

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

int main() {
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    
    int n,m;
    cin>>n>>m;

    unordered_set<int> p[n+5];
    bool on[n+5];
    memset(on, false, sizeof(on));
    sieve(n+5);

    char c;
    int val;
    F(i, 0, m) {
    	cin>>c>>val;
    	if(c == '-') { 
    		if(on[val]) {
    			on[val] = false;
    			vi fact = primeFactors(val);
    			F(j, 0, fact.size()) {
 					int pr = fact[j];
 					// if(p[pr].find(val) == p[pr].end()) {
 					// 	cout<<"Anomaly\n";
 					// }
 					p[pr].erase(val);
 				}
    			cout<<"Success\n";
    		} else {
    			cout<<"Already off\n";
    		}
     	} else {
     		if(on[val]) {
     			cout<<"Already on\n";
     		} else {
     			vi fact = primeFactors(val);
     			int cval = -1;
     			F(j, 0, fact.size()) {
     				int pr = fact[j];
     				unordered_set<int> s = p[pr];
     				if(!s.empty()) {
     					cval = *s.begin();
     					break;
     				}
     			}

     			if(cval != -1) {
     				cout<<"Conflict with "<<cval<<endl;
     			} else {
					F(j, 0, fact.size()) {
     					int pr = fact[j];
     					p[pr].insert(val);
     				}
     				on[val] = true;
     				cout<<"Success\n";     				
     			}
     		}
     	}
    }

    return 0;          
}/*
    
*/