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
const ll MOD = 1000000009;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

const int p = 31;
const int N = 1e6+5;
ll p_pow[N];
ll h[N],tmph[N];
vii edges;

void generate_p_pow() {
	p_pow[0]=1;
	FOR(i, 1, N) {
		p_pow[i] = p_pow[i-1]*p;
		// p_pow[i] %= MOD;
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    generate_p_pow();
    int n,m,u,v;
    cin>>n>>m;

    memset(h, 0, sizeof(h));
    FOR(i, 0, m) {
    	cin>>u>>v;
    	edges.push_back({u, v});
    	h[u] += p_pow[v];
    	h[v] += p_pow[u];
    }

    FOR(i, 1, n+1) {
    	tmph[i] = h[i];
    }

    ll ans = 0;
    sort(tmph+1, tmph + n + 1);
    ll cnt = 0, prev = -1;
    FOR(i, 1, n+1) {
    	if(prev == tmph[i]) cnt++;
    	else {
    		ans += (cnt * (cnt-1))/2;
    		cnt = 1;
    		prev = tmph[i];
    	}
    }
    ans += (cnt * (cnt - 1))/2;

    FOR(i, 0, edges.size()) {
    	// u = edges[i].ff, v = edges[i].ss;
    	tie(u,v) = edges[i];
    	h[u] -= p_pow[v];
    	h[v] -= p_pow[u];
    	if(h[u] == h[v]) ans++;
    	h[u] += p_pow[v];
    	h[v] += p_pow[u];
    }

    cout<<ans;

    return 0;
}