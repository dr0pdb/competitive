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
bitset<1000010> bs;
vi primes;

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
	if (N != 1) factors.push_back({N, 1});

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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll l,r,x,y,val,ans=0;
    cin>>l>>r>>x>>y;
    sieve(100001);
    if(y % x) {
    	cout<<0;
    	return 0;
    }
    val = y/x;
    vii facts = primeFactors(val);
    int sz = facts.size();
    // F(i, 0, sz) {
    // 	cout<<facts[i].first<<" "<<facts[i].second<<endl;
    // }

    F(i, 0, (1<<sz)) {
    	ll a[2]={1,1};
    	F(j, 0, sz) {
    		if(i & (1<<j)) {
    			a[1] *= power(facts[j].first, facts[j].second);
    		} else {
    			a[0] *= power(facts[j].first, facts[j].second);
    		}
    	}
    	a[0] *= x; a[1]*=x;
    	// deb(a[0]);
    	if(a[0]>=l && a[0]<=r && a[1]>=l && a[1]<=r) ans++;
    }
    cout<<ans;

    return 0;
}/*

*/