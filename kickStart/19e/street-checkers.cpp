/**
    __author__ : srv_twry
**/

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
bitset<10000010> bs;
vll primes, p4;

void sieve(ll upperbound) {
	
	_sieve_size = upperbound + 1;
	
	bs.set();
	bs[0] = bs[1] = 0;
	primes.push_back(1);
	
	for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
		
		for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
		primes.push_back((ll)i);
		
	} 
}

ll countodds(ll L, ll R){  
  
    ll N = (R - L) / 2; 
  
    // if either R or L is odd  
    if (R % 2 != 0 || L % 2 != 0)  
        N += 1; 
  
    return N; 
} 


ll ff(ll cnt) {
	auto itr = upper_bound(primes.begin(), primes.end(), cnt);
	return distance(primes.begin(), itr);
}

// ll findOddPrimes(ll left, ll right) {
// 	ll cnt = ff(right) - ff(left - 1);

// 	if(left <= 2) {
// 		cnt--;
// 	}
// 	return cnt;
// }

ll countinrange(ll left, ll right) {
	auto itr = upper_bound(p4.begin(), p4.end(), right);
	auto itr2 = upper_bound(all(p4), left - 1);

	return distance(itr2, itr);
}

vll getDivisors(ll n) 
{ 
	vll facts;
    for (ll i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i) 
            	facts.push_back(i);     
  
            else {
            	facts.push_back(i);
            	facts.push_back(n/i);
            } 
               
        } 
    } 
    return facts;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 	ll t,l,r; cin>>t;
 	ll ans = 0;
 	sieve(1e5+1);
 	sort(primes.begin(), primes.end());
 	for(ll num : primes) {
 		p4.push_back(4*num);
 	}
 	FOR(tn, 1, t+1) {
 		// cout<<"Case #"<<tn<<": ";
 		cin>>l>>r;
 		ans = 0;
 		if(l == r) {
 			vll divs = getDivisors(l);
 			ll cnt1 = 0, cnt2 = 0;
 			for(ll d : divs) {
 				if(d % 2 == 0) cnt1++;
 				else cnt2++;
 			}
 			if(abs(cnt1 - cnt2) <= 2) ans = 1;
 		} else {
 			// power of 2 = 2 multiplied by another prime. also covers 2^3.
			ans += countinrange(l, r);
			// deb(ans);

	 		// power of 2 = 1. count odds in [L/2, R/2].
	 		ans += countodds((l + 1)/2, r/2);
	 		// deb(ans);

	 		// power of 2 = 0. cnt all odd primes in [L, R]
	 		ans += ff(r) - ff(l-1);
	 		if(l <= 2 && r>=2) ans--;
	 		// deb(ans);
 		}

 		ans = min(ans, r - l + 1);
 		cout<<l<<" "<<r<<" "<<ans<<endl;
 		// cout<<ans<<endl;
 	}

    return 0;
}