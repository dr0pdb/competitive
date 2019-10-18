#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);

#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define ull unsigned long long
#define deb(x )     cerr << #x << " = "<< x << endl;
#define endl    "\n"
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
/*----------------------------------------------------------------------*/

ll _sieve_size;
bitset<1000010> bs;
vll primes;

map<ll,int> primeFactors(ll N) {
	map<ll,int> factors;
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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll a, b; cin>>a>>b;
    sieve(1e6+1);
    map<ll,int> pa,pb;
    pa = primeFactors(a); pb = primeFactors(b);
    ll res = 1;

    for(auto itr : pa) {
    	if(pb.find(itr.ff) != pb.end()) {
    		res++;
    	}
    }
    cout<<res;

    return 0;
}