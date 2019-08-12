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

const int N = 1e6+5;
ll p[N];

void pre() {
	p[0] = 1LL;
	FOR(i, 1, N) {
		p[i] = p[i-1] * 10LL;
		p[i] %= MOD;
	}
}

ll ff(ll i) {
	string ss = to_string(i);
	ll ret = 0; int sz = ss.size();
	FOR(i, 0, ss.size()) {
		if (!i || ss[i] != ss[i-1])
		{
			ll dig = ss[i] - '0';
			ll pp = sz - i - 1;
			ret += dig * p[pp];
			ret %= MOD;
		}
	}
	return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll csum = 0; pre();
    FOR(i, 1, 1e5) {
    	ll f = ff(i);
    	csum += f;
    	// cout<< i << " " << f << " " << csum << endl;
    	cout<<csum<<endl;
    }

    return 0;
}