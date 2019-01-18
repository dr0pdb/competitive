#include<bits/stdc++.h>
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
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
/*----------------------------------------------------------------------*/

int n,m;
const int N = 1e5+5;
vi g[N];
bool visited[N];
int dp[N];

void dfs(int curr, vi &ts) {
	visited[curr] = true;
	for(auto next: g[curr]) {
		if(!visited[next]) dfs(next, ts);
	}

	ts.push_back(curr);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int u,v;
    cin>>n>>m;
    F(i, 0, m) {
    	cin>>u>>v; u--; v--;
    	g[u].push_back(v);
    }
    memset(visited, false, sizeof(visited));
    vi ts;
    memset(dp, 0, sizeof(dp));
    F(i, 0, n) {
    	if(!visited[i]) {
    		dfs(i, ts);
    	}
    }

    dp[ts[n-1]]=0;
    RF(i, n-1, 1) {
    	for(auto next: g[ts[i]]) {
            dp[next]=max(dp[next], dp[ts[i]]+1);
        }
    }
    cout<<*max_element(dp, dp+N);

    return 0;
}/*

*/
