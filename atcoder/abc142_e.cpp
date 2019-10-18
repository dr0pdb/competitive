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

const int M = 1e3+1;
int n,m,cost[M],sz,tmp;
int dp[M][(1<<12)+1];
vi openers[M];

int solve(int idx, int mask) {
	if(idx == m) {
		if(mask == (1 << n) - 1) return 0;
		return INF;
	}
	int &res = dp[idx][mask];
	if(res >= 0) return res;
	res = INF;

	res = solve(idx + 1, mask);
	for(int op : openers[idx]) {
		mask |= (1 << op);
	}
	res = min(res, cost[idx] + solve(idx + 1, mask));
	return res;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 	cin>>n>>m; memset(dp, -1, sizeof(dp));
 	FOR(i, 0, m) {
 		cin>>cost[i]>>sz;
 		FOR(j, 0, sz) {
 			cin>>tmp; tmp--;
 			openers[i].push_back(tmp);
 		}
 	}
 	int res = solve(0, 0);
 	if(res == INF) res = -1;
 	cout<<res;
    return 0;
}