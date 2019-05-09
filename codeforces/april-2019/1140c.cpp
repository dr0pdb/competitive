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

const int N = 3e5+5;
int n,k;
lll music[N]; // beauty and length.

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>k;
    FOR(i, 0, n) {
    	cin>>music[i].ss>>music[i].ff;
    }
    sort(music, music+n);
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll cumsum = 0, ans = 0;
    if(k > 1) {
    	RFOR(i, n-1, 0) {
	    	ll cb = music[i].ff;
	    	ans = max(ans, cb*(cumsum+music[i].ss));
	    	if((int)pq.size() == k-1) {
	    		ll val = pq.top();
	    		if(val < music[i].ss) {
	    			cumsum -= val;
	    			pq.pop();
	    			pq.push(music[i].ss);
	    			cumsum += music[i].ss;
	    		}
	    	} else {
	    		pq.push(music[i].ss);
	    		cumsum += music[i].ss;
	    	}
	    }
    } else {
    	FOR(i, 0, n) {
    		ans = max(ans, music[i].ff * music[i].ss);
    	}
    }
    cout<<ans;

    return 0;
}