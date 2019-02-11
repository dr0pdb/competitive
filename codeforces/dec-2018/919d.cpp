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

const int N = 3e5+5;
vi g[N];
int indeg[N], dp[N][26];
int n,m,u,v,ans=0;
string vals;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    cin>>n>>m;
    cin>>vals;
    F(i, 0, m) {
    	cin>>u>>v;
    	u--; v--;
    	g[u].push_back(v);
    	indeg[v]++;
    }

    memset(dp, 0, sizeof(dp));
    F(i, 0, vals.size()) {
    	dp[i][vals[i]-'a']++;
    }
    int cnt = 0;
    queue<int> q;
    F(i, 0, n) {
    	if(indeg[i] == 0) {
    		q.push(i);
    	}
    }

    while(!q.empty()) {
    	int curr = q.front(); q.pop();
    	for(auto next: g[curr]) {
    		if(indeg[next] > 0) {
    			F(i, 0, 26) {
    				if(i != vals[next]-'a') {
    					dp[next][i] = max(dp[next][i], dp[curr][i]);
    				} else {
    					dp[next][i] = max(dp[next][i], dp[curr][i] + 1);
    				}
    			}
    			indeg[next]--;
    			if(indeg[next] == 0) {
    				q.push(next);
    			}
    		}
    	}
    	cnt++;
    }

    if(cnt == n) {
    	int ans = 0;
    	F(i, 0, n) {
    		F(j, 0, 26) {
    			ans = max(ans, dp[i][j]);
    		}
    	}
    	cout<<ans;
    } else {
    	cout<<-1;
    }
    
    return 0;
}/*

*/
