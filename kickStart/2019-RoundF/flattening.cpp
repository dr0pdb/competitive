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

const int N = 101;
int dp[N][1001][N];
int n,k,h[N];

int solve(int idx, int prev, int kk) {
	if(kk > k) return INF;
	if(idx == n) {
		if(kk <= k) return 0;
		return INF;
	}
	int &res = dp[idx][prev][kk];
	if(res >= 0) return res;
	res = INF;
	if (idx == 0)
	{
		FOR(j, 1, 1001) {
			if(j == h[0]) {
				res = min(res, solve(idx + 1, h[0], kk));
			} else {
				res = min(res, 1 + solve(idx + 1, j, kk));
			}
		}	
	} else {
		FOR(j, 1, 1001) {
			if(j == prev) {
				if(j == h[idx]) {
					res = min(res, solve(idx + 1, j, kk));
				} else {
					res = min(res, 1 + solve(idx + 1, j, kk));
				}
			} else {
				if(j == h[idx]) {
					res = min(res, solve(idx + 1, j, kk + 1));
				} else {
					res = min(res, 1 + solve(idx + 1, j, kk + 1));
				}
			}
		}
	}
	return res;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 	int t; cin>>t;
 	FOR(tn, 1, t+1) {
 		cin>>n>>k;
 		FOR(i, 0, n) cin>>h[i];
 		memset(dp, -1, sizeof(dp));
 		int res = solve(0, 0, 0);
 		cout<<"Case #"<<tn<<": "<<res<<endl;
 	}   

    return 0;
}