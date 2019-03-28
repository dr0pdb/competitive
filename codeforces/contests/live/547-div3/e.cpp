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

const int N = 2e5+5;
int d[N];
ll h,rcost=0,ans=0;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>h>>n;
    ll sm = 0, minm_dec=LONG_LONG_MAX;
    bool infinite = true;
    int ind = 0;

    FOR(i, 0, n) {
    	cin>>d[i];
    	sm += d[i];
    	minm_dec = min(minm_dec, sm);
    	if(h + sm <= 0 && infinite) {
    		ind = i;
    		infinite = false;
    	}
    }

    if(!infinite) {
    	ind++;
    	cout<<ind;
    	return 0;
    }
    if(sm < 0) {
    	infinite = false;
    }
    if(infinite) {
    	cout<<-1;
    	return 0;
    }

    // minm_dec surely will be negative.
    h -= abs(minm_dec);
    // deb(h); deb(sm);
    ans += (h / abs(sm))*n;
    // deb(ans);
    h %= abs(sm);
    h += abs(minm_dec);
    // deb(h);
    int curr = 0,cnt=0;
    while(h > 0) {
    	h += d[curr];
    	cnt++;
    	curr = (curr + 1) % n;
    }
    ans += cnt;
    cout<<ans;

    return 0;
}