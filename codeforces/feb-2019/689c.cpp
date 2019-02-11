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

ll m;

ll check(ll mid) {
	ll cnt = 0;

	ll i = 2LL;
	while(i*i*i <= mid) {
		cnt += mid / (i*i*i);
		i++;
	}

 	return cnt;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll ans=LONG_LONG_MAX;
    cin>>m;

    ll lo = 1, hi = 1e18;

	while (lo <= hi) {
	    ll mid = (lo + hi) / 2;
	    ll cnt = check(mid);
	    if (cnt >= m) {
	    	if(cnt == m)
	        	ans = min(ans, mid);
	        hi = mid - 1;
	    }
	    else lo = mid + 1;
	}

	if(ans == LONG_LONG_MAX) {
		cout<<-1;
	} else {
		cout<<ans;
	}

    return 0;
}/*

*/