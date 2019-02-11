#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define SIEVELIM 10000000+10
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"
#define printCase() "Case #" << caseNum << ": "

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
/*----------------------------------------------------------------------*/

const int N = 1005;
ii v[N];
bool g[N][N];
ll cst[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    int n,m,x,y;
    cin>>n>>m;
   	memset(cst, 0, sizeof(cst));

    F(i, 0, n) {
    	cin>>v[i].first;
    	v[i].second = i;
    }

    memset(g, false, sizeof(g));
   	
    F(i, 0, m) {
    	cin>>x>>y; x--; y--;
    	g[x][y]=true; g[y][x]=true;
    	cst[x]+=v[y].first;
    	cst[y]+=v[x].first;
    }

    ll ans = 0;
    sort(v, v+n, greater<ii>());
    F(i, 0, n) {
    	ans += cst[v[i].second];
    	// deb(ans);
    	x = v[i].second;

    	F(j, 0, n) {
    		if(g[j][x]) {
    			g[x][j] = false;
    			g[j][x] = false;
    			cst[j] -= v[i].first;
    		}
    	}
    }

    cout<<ans;

    return 0;
}/*

*/
