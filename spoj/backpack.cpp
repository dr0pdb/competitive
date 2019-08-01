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

const int N = 61;
int dp[N][32001];
bool gotit[N][32001];
int t,v,c,u,n,vmax; 
vector<vii> goods, gg;

int solve(int idx, int vleft) {
	if (vleft < 0) return -INF;
	int &res = dp[idx][vleft];
	if (gotit[idx][vleft]) return res;
	if (!vleft) return 0;
	if (idx == n) return 0;
	res = 0; gotit[idx][vleft] = true;

	int v,c;
	tie(v,c) = gg[idx][0];
	res = max(solve(idx+1, vleft), v * c + solve(idx+1, vleft - v));
	if (gg[idx].size() > 1)
	{
		int v2, c2; tie(v2, c2) = gg[idx][1];
		res = max(res, v*c + v2*c2 + solve(idx+1, vleft - v - v2));
		if (gg[idx].size() > 2)
		{
			int v3, c3; tie(v3, c3) = gg[idx][2];	
			res = max(res, v*c + v3*c3 + solve(idx+1, vleft -v - v3));
			res = max(res, v*c + v3*c3 + v2*c2 + solve(idx+1, vleft - v - v2 - v3));
		}
	}
	return res;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	cin>>t;
	while(t--) {
		cin>>vmax>>n; int attach = 0;
		goods.clear(); goods.resize(n, vii(1, {0,0}));
		FOR(i, 0, n) {
			cin>>v>>c>>u;
			if (u)
			{
				attach++;
				u--;
				goods[u].push_back({v, c});
				goods[i][0] = {-1, -1};
			} else {
				goods[i][0] = {v, c};
			}
		}
		gg.clear(); n -= attach;
		gg.resize(n, vii(1, {0, 0}));
		int idx = 0;
		FOR(i, 0, goods.size()) {
			tie(v, c) = goods[i][0];
			if (v == -1)
			{
				continue;
			}
			gg[idx++] = goods[i];
		}
		// FOR(i, 0, gg.size()) {
		// 	cout<<gg[i].size()<<endl;
		// 	FOR(j, 0, gg[i].size()) {
		// 		cout<<gg[i][j].ff<<" "<<gg[i][j].ss<<endl;	
		// 	}
		// 	cout<<endl;
		// }
		memset(gotit, false, sizeof(gotit));
		cout<<solve(0, vmax)<<endl;
	}

    return 0;
}