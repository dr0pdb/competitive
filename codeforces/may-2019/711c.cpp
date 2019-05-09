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
const ll INF = 1e15;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

const int N = 105;
ll dp[N][N][N], cost[N][N];
int color[N], n,m,k;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>m>>k;
    FOR(i, 0, n) {
    	cin>>color[i];
    	color[i]--;
    }
    FOR(i, 0, n) {
    	FOR(j, 0, m) {
    		cin>>cost[i][j];
    	}
    }
    FOR(i, 0, n) {
    	FOR(j, 0, m) {
    		FOR(l, 0, k+1) {
    			dp[i][j][l] = INF;
    		}
    	}
    }

    FOR(j, 0, m) {
    	if(color[0] >= 0) {
    		if(color[0] != j) {
    			dp[0][j][1] = INF;
    		} else {
    			dp[0][j][1] = 0;
    		}
    	} else {
			dp[0][j][1] = cost[0][j];
    	}
    }
    FOR(i, 1, n) {
    	FOR(j, 0, m) {
    		FOR(l, 1, k+1) {
    			if(color[i] >= 0) {
    				if(color[i] != j)
    					dp[i][j][l] = INF;
    				else {
    					ll minm = INF;
    					FOR(prevc, 0, m) {
    						if(prevc != j) {
    							minm = min(minm, dp[i-1][prevc][l-1]);
    						} else {
    							minm = min(minm, dp[i-1][prevc][l]);
    						}
    					}
    					dp[i][j][l] = minm;
    				}
    				continue;
    			}	else {
    				ll minm = INF;
    				FOR(prevc, 0, m) {
						if(prevc != j) {
							minm = min(minm, dp[i-1][prevc][l-1] + cost[i][j]);
						} else {
							minm = min(minm, dp[i-1][prevc][l] + cost[i][j]);
						}
					}
					dp[i][j][l] = minm;
    			}
    		}
    	}
    }
    ll ans = INF;
    FOR(i, 0, m) {
    	ans = min(ans, dp[n-1][i][k]);
    }
    if(ans >= INF) {
    	ans = -1;
    }
    cout<<ans;

    return 0;
}