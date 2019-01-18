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

const int N = 150005;
int a[2][N];
ll _sieve_size;
bitset<10000010> bs;
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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    int n;
    cin>>n;
    sieve(100005);

    F(i, 0, n) {
    	cin>>a[0][i]>>a[1][i];
    }

    if(n == 1){
    	cout<<a[0][0];
    	return 0;
    }

    set<int> prim;
    F(i, 0, 2) {
    	F(j, 0, 2) {
    		vi facts = primeFactors(a[i][j]);
    		F(k, 0, facts.size()) {
    			prim.insert(facts[k]);
    		}
    	}
    }

    for(auto itr: prim) {
    	bool found = true;
    	F(i, 0, n) {
    		if(a[0][i] % itr != 0 && a[1][i] % itr != 0) {
    			found = false;
    			break;
    		}
    	}
    	if(found) {
    		cout<<itr;
    		return 0;
    	}
    }
    cout<<-1;

    return 0;
}/*

*/
