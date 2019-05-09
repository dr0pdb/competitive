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

ll _sieve_size;
bitset<105> bs;
vi primes;

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
    std::ios::sync_with_stdio(false);cin.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    sieve(100);
    vi sqrs = {4, 9, 25, 49};
    int cnt = 0; string s;
    FOR(i, 0, sqrs.size()) {
    	cout<<sqrs[i]<<endl;
    	cin>>s;
    	if(s == "yes") {
    		cout<<"composite"<<endl;
    		return 0;
    	}
    }
    FOR(i, 0, primes.size()) {
    	if(primes[i] > 50) break;
    	cout<<primes[i]<<endl;
    	cin>>s;
    	if(s[0] == 'y') {
    		cnt++;
    	}
    	if(cnt > 1) break;
    }

    if(cnt > 1) {
    	cout<<"composite"<<endl;
    } else {
    	cout<<"prime"<<endl;
    }
    return 0;
}