#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);

#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define ull unsigned long long
#define deb(x )     cerr << #x << " = "<< x << endl;
#define endl    "\n"
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
/*----------------------------------------------------------------------*/

const int N = 1e5+5;
ll x[N];
vi g[N];
ll res = 0;

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	else return gcd(b, a%b);
}

void dfs(int curr, int p, map<ll,ll> gs) {
	map<ll, ll> gs2;
	ll gc;
	for(auto itr : gs) {
		gc = gcd(itr.ff, x[curr]);
		res = (res + (gc * itr.ss) % MOD) % MOD;
		gs2[gc] += itr.ss;
	}

	res = (res + x[curr]) % MOD;
	gs2[x[curr]] += 1LL;

	for(auto nxt : g[curr]) {
		if(nxt != p) {
			dfs(nxt, curr, gs2);		
		}
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int n,u,v; cin>>n;
	FOR(i, 0, n) cin>>x[i];
	FOR(i, 0, n-1) {
		cin>>u>>v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	map<ll,ll> gs;
	dfs(0, -1, gs);
	cout<<res;
    return 0;
}