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
/*----------------------------------------------------------------------*/

ll _sieve_size;
bitset<10000010> bs;
vi primes;

vi primeFactors(ll N) {
	vi factors_freq;
	ll PF_idx = 0, PF = primes[PF_idx];
	while (PF * PF <= N) {
		int counter = 0;

		//we have to ignore 2 once.
		if (PF==2)
		{
			counter--;
		}
		while (N % PF == 0) { N /= PF;counter++; }
		if (counter>0)
		{
			factors_freq.push_back(counter);	
		}
		PF = primes[++PF_idx];
		
	}
	if (N != 1 && N != 2) factors_freq.push_back(1);

	return factors_freq;
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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
    sieve(1e7+5);

   	int t,n;
   	cin>>t;
   	
   	while(t--){
   		cin>>n;

   		ll curr = 3;
   		vi past,pres;
   		past = primeFactors(2);
   		while(true){

   			pres = primeFactors(curr);
   			ll value = 1;

   			F(i, 0, past.size()){
   				value *= (past[i]+1);
   			}

   			F(i, 0, pres.size()){
   				value *= (pres[i]+1);
   			}

   			if (value>n)
   			{
   				cout<<(curr*(curr-1))/2<<endl;
   				break;
   			}

   			curr++;
   			past = pres;
   		}

   	}

    return 0;       
}
