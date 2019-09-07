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

ll t,x,y,r,x2,y2,r2;

double dist(ll x, ll y, ll xx, ll yy) {
	return sqrt(((x - xx) * (x - xx)) + ((y - yy) * (y - yy)));
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
   	cin>>t;
    while(t--) {
    	cin>>x>>y>>r>>x2>>y2>>r2; swap(x, x2); swap(y, y2); swap(r, r2);
    	long double distsq = sqrt(((x - x2) * (x - x2)) + ((y - y2) * (y - y2)));
    	if(distsq + r2 <= r) {
    		cout<<"NO\n";
    	} else {
    		cout<<"YES\n";
    		long double ax, ay;
    		long double dx = x2 - x; double dy = y2 - y;
    		long double dd = sqrt(dx * dx + dy * dy);
    		dx /= dd; dy /= dd;
    		dx *= r2; dy *= r2;
    		ax = x2 + dx; ay = y2 + dy;
    		coud(ax, 10); cout<<" ";
    		coud(ay, 10); cout<<endl;
    	}
    }

    return 0;
}