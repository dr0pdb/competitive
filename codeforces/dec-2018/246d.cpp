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

const int N = 1e5+5;
int n,m,u,v;
int c[N];
vi g[N];
bool visited[N], present[N];
set<int> nb[N];

void dfs(int curr) {
	visited[curr] = true;

	F(i, 0, g[curr].size()) {
		int next = g[curr][i];
		if(c[next] != c[curr]) {
			nb[c[curr]].insert(c[next]);
		}

		if(!visited[next]) {
			dfs(next);
		}
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    cin>>n>>m;
    memset(present, false, sizeof(present));

    F(i, 0, n) {
    	cin>>c[i];
    	present[c[i]]=true;
    }

    F(i, 0, m) {
    	cin>>u>>v;
    	u--; v--;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }

    memset(visited, false, sizeof(visited));

    F(i, 0, n) {
    	if(!visited[i]) {
    		dfs(i);
    	}
    }

    int ans = 0,maxm = -1;
    F(i, 1, N) {
    	int sz = nb[i].size();
    	if(present[i] && sz > maxm) {
    		maxm = sz;
    		ans = i;
    	}
    }

    cout<<ans;

    return 0;
}/*

*/
