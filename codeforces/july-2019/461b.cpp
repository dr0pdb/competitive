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

const int N = 1e5+5;
vi g[N];
bool black[N];
ll f[N], f2[N];

ll power(ll x,ll y, ll p)
{
    ll res = 1;     
    x = x % p; 
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}

ll modInverse(ll a, ll m){
	return power(a,m-2,m);
}

void dfs(int curr, int par) {
	bool leaf = true;
	ll allp = 1;
	for(auto nxt : g[curr]) {
		if(nxt == par) continue;
		leaf = false;
		dfs(nxt, curr);
		allp *= (f[nxt] + f2[nxt]) % MOD; allp %= MOD;
	}

	if (leaf)
	{
		if(black[curr]) {
			f[curr] = 1;
			f2[curr] = 0;
		} else {
			f[curr] = 0;
			f2[curr] = 1;
		}
	} else {
		if(black[curr]) {
			f2[curr] = 0;
			f[curr] = allp;
		} else {
			f2[curr] = allp;
			f[curr] = 0;
			for(auto nxt : g[curr]) {
				f[curr] += ((f[nxt] * allp) % MOD * modInverse(f[nxt]+f2[nxt], MOD)) % MOD;
				f[curr] %= MOD;
			}
		}
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,u; cin>>n; memset(black, false, sizeof(black));
    FOR(i, 0, n-1) {
    	cin>>u;
    	g[i+1].push_back(u); g[u].push_back(i+1);
    }
    FOR(i, 0, n) {
    	cin>>u;
    	black[i] = u;
    }
    memset(f, 0, sizeof(f)); memset(f2, 0,sizeof(f2));
    dfs(0, -1);
    cout<<f[0];

    return 0;
}