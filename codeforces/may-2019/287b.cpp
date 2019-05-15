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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,k;
    cin>>n>>k;
    if(n == 1) {
    	cout<<0;
    	return 0;
    } else if (n - 1 > (k*(k-1)/2)) {
    	cout<<-1;
    	return 0;
    }

    ll lo = 1, hi = k-1, ans=-1;
    while(lo <= hi) {
    	ll mid = lo + (hi - lo)/2;
    	// deb(mid);
    	ll sz = k - mid;
    	// deb(sz);
    	ll sum = sz*(2*k- sz - 1)/2;
		// deb(sum);
		if(sum <= n - 1) {
			ans = max(ans, sz);
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
		// deb(ans);
    }
    ll sum = ans*(2*k - ans - 1)/2;
    if(sum != n - 1) ans++;
    cout<<ans;

    return 0;
}