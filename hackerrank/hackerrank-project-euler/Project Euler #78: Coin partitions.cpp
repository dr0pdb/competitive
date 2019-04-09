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

const int N = 6e4+5;
ll p[N];

ll solve(ll n) {
	if(n < 0) return 0;
	ll &ret = p[n];
	if(ret >= 0) return ret;
	ret = 0;

	FOR(i, 1, N) {
		ll gk = i*(3*i - 1)/2;
		ll mult = 1;
		if((i - 1)&1) mult = -1;
		if(n < gk) break;
		ret += mult*solve(n - gk);
		ret = (ret + MOD)%MOD;
		
		i *= -1;
		gk = i*(3*i - 1)/2;
		if(n < gk) break;
		ret += mult*solve(n - gk);
		ret = (ret + MOD)%MOD;
		i *= -1;
	}

	return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t,n;
    cin>>t;
    memset(p, -1, sizeof(p));
    p[0]=1,p[1]=1,p[2]=2,p[3]=3;

    while(t--) {
    	cin>>n;
    	cout<<solve(n)<<endl;
    }

    return 0;
}