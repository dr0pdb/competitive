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
    int w,h,n,val; cin>>w>>h>>n; char c;
    multiset<int> xx,yy;
    set<int> xs,ys;
    xs.insert(0); xs.insert(w); ys.insert(0); ys.insert(h);
    xx.insert(w); yy.insert(h);
    FOR(i, 0, n) {
    	cin>>c>>val;
    	if(c == 'H') {
    		auto itr = ys.upper_bound(val); --itr; auto itr2 = itr; ++itr;
    		int ht = *itr - *itr2;
    		// deb(*itr); deb(*itr2);
    		yy.erase(yy.find(ht));
    		yy.insert(*itr - val); yy.insert(val - *itr2);
    		ys.insert(val);
    	} else {
    		auto itr = xs.upper_bound(val); --itr; auto itr2 = itr; ++itr;
    		int wt = *itr - *itr2;
    		// deb(*itr); deb(*itr2);
    		xx.erase(xx.find(wt));
    		xx.insert(*itr - val); xx.insert(val - *itr2);
    		xs.insert(val);
    	}
    	auto itr = xx.end(); --itr;
    	auto itr2 = yy.end(); --itr2;
    	cout<<1LL * (*itr) * (*itr2) << endl;
    }

    return 0;
}