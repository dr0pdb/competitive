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

const int N = 1e4+5;
int n,m,v,u;
vii g[N];
int color[N], dp[N], dp2[N]; // count bad and good back edges.
bool onstack[N];

bool dfs(int curr) {
	bool good = true;
	for(auto itr : g[curr]) {
		int nxt = itr.ff;
		if (color[nxt] < 0)
		{
			color[nxt] = 1 - color[curr];
			good &= dfs(nxt);
		} else if (color[nxt] == color[curr])
		{
			good = false;
		}
	}
	return good;
}

vi badbackedges,ans;

void dfs2(int curr, int par = -1) {
    onstack[curr] = true;
	for(auto itr : g[curr]) {
		int nxt = itr.ff, idx = itr.ss;
		if (nxt == par) continue;
		if (color[nxt] < 0)
		{
			// span edge.
			color[nxt] = 1 - color[curr];
			dfs2(nxt, curr);
        } else {
            if(!onstack[nxt]) continue;
			// back edge.
			if (color[nxt] != color[curr])
			{
				dp2[curr]++;	
			} else {
				// bad back edges.
				dp[curr]++;
				badbackedges.push_back(idx);
			}
		}
        dp[curr] += dp[nxt];
        dp2[curr] += dp2[nxt];
	}
    onstack[curr] = false;
}

void dfs3(int curr) {
	for(auto itr : g[curr]) {
		int nxt = itr.ff, idx = itr.ss;
		if (color[nxt] < 0)
		{
			color[nxt] = 1 - color[curr];
			dfs3(nxt);

			if (dp[nxt] == badbackedges.size() && dp2[nxt] == 0)
			{
				ans.push_back(idx);
			}
		}
	}	
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    FOR(i, 0, m) {
    	cin>>v>>u;
    	g[u].push_back({v, i + 1});
    	g[v].push_back({u, i + 1});
    }
    memset(onstack, false ,sizeof(onstack));
    int cnt = 0; 
    memset(color, -1, sizeof(color));
    vi starters;
    FOR(i, 0, n) {
    	if (color[i] < 0)
    	{
    		color[i] = 0;
    		bool good = dfs(i);
    		if (!good)
    		{
    			cnt++;
    			starters.push_back(i);
    		}
    	}
    }
    // deb(cnt);
    if (cnt == 0)
    {
    	cout<<m<<endl;
    	FOR(i, 0, m) {
    		cout<<i+1<<" ";
    	}
    } else if(cnt > 1) {
    	cout<<0<<endl;
    } else {
    	memset(dp, 0, sizeof(dp)); memset(dp2, 0, sizeof(dp2));
    	
    	memset(color, -1, sizeof(color));
    	color[starters[0]] = 0;
    	dfs2(starters[0]);

    	memset(color, -1, sizeof(color));
    	color[starters[0]] = 0;
    	dfs3(starters[0]);
    		
		if (badbackedges.size() == 1)
    	{
    		ans.push_back(badbackedges[0]);
    	}
        sort(ans.begin(), ans.end());
    	cout<<ans.size()<<endl;
    	for(int ret : ans) {
    		cout<<ret<<" ";
    	}
    }
    return 0;
}
/**
    __author__ : srv_twry
**/

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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    

    return 0;
}
