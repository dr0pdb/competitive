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
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int N = 1e5+5;
vi g[N];
ll val[N], ans = 0;
 
lll dfs(int curr, int par = -1) {
	lll change = {0,0}; // +,- 
	for(ll nxt : g[curr]) {
		if(nxt != par) {
			lll det = dfs(nxt, curr);
			change.ff = max(change.ff, det.ff);
			change.ss = max(change.ss, abs(det.ss));
		}
	}
	val[curr] += change.ff - change.ss;
	if(val[curr] >= 0) {
		change.ss += val[curr];
	} else {
		change.ff += abs(val[curr]);
	}
	return change;
}
 
int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
 
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,u,v; cin>>n;
    FOR(i, 0, n-1) {
    	cin>>u>>v; u--; v--;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    FOR(i, 0, n) cin>>val[i];
    lll ans = dfs(0);
    cout<<ans.ff + ans.ss;
    return 0;
}