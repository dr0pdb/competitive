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

const int N = 10;
int n,m,a,b;
vii g;
int val[N],ans;
map<ii,bool> taken;

int getans() {
	taken.clear();
	int curr = 0;
	for(ii e : g) {
		tie(a, b) = e;
		int lo = min(val[a], val[b]);
		int hi = max(val[a], val[b]);
		if(!taken[{lo, hi}]) {
			curr++;
			taken[{lo, hi}] = true;
		}
	}
	return curr;
}

void solve(int curr) {
	if(curr == n) {
		ans = max(ans, getans());
		return;
	}
	FOR(i, 1, 7) {
		val[curr] = i;
		solve(curr + 1);
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    FOR(i, 0, m) {
    	cin>>a>>b; a--; b--;
    	g.push_back({a, b});
    }
   	ans = 0;
    solve(0);
    cout<<ans;
    return 0;
}