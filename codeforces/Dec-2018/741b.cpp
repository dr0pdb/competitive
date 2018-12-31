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
const ll INF = 1e15+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
/*----------------------------------------------------------------------*/

const int N = 1005;
int n,m,w,wt[N],b[N],u,v;
vi g[N];
vector<ll> ccost,cbeauty;
bool visited[N];
vector<vi> comps;
vector<vector<vi> >  dp(1005, vector<vi>());

void dfs(int curr) {
	visited[curr] = true;
	int sz = comps.size();
	comps[sz-1].push_back(curr);
	ccost[sz-1] += wt[curr];
	cbeauty[sz-1] += b[curr];

	for(auto next: g[curr]) {
		if(!visited[next]) {
			dfs(next);
		}
	}
}

ll solve(int component, int index, int left) {
	if(left < 0) {
		return -INF;
	}

	if(component == comps.size() || left == 0) {
		return 0;
	}

	if(dp[left][component][index] != -1) {
		return dp[left][component][index];
	}

	ll ret = 0;
	if (index > comps[component].size()) {
		ret += cbeauty[component];
		cout<<"Adding total cost of the component "<<component<<" to the result "<<cbeauty[component]<<endl;
		if(left < ccost[component]) {
			return -INF;
		}
		left -= ccost[component];
	} else if(index) {
		int vertex = comps[component][index-1];
		cout<<"vertex "<<vertex<<" is at the index: "<<index<<" of the component "<<component<<endl; 
		ret += b[vertex];
		if(left < wt[vertex]) {
			return -INF;
		}
		left -= wt[vertex];
	}

	if(component+1 < comps.size()) {
		int sz = (int)comps[component+1].size() + 2;
		ll tmp = -INF;
		F(i, 0, sz) {
			cout<<"Going from index: "<<index<<" of component "<<component<<" next-index: "<<i<<endl;
			tmp = max(tmp, solve(component+1, i, left));
		}
		ret += tmp;
	}

	return dp[left][component][index] = ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    cin>>n>>m>>w;
    F(i, 1, n+1) {
    	cin>>wt[i];
    }
    F(i, 1, n+1) {
    	cin>>b[i];
    }

    F(i, 0, m) {
    	cin>>u>>v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }

    memset(visited, false, sizeof(visited));
    F(i, 1, n+1) {
    	if(!visited[i]) {
    		comps.push_back(vi());
    		ccost.push_back(0LL);
    		cbeauty.push_back(0LL);
    		dfs(i);
    		int sz = (int)comps.back().size() + 2;

    		F(j, 0, 1005) {
    			dp[j].push_back(vi(sz, -1));
    		}
    	}
    }

    // deb(comps.size());
    // F(i, 0, comps.size()) {
    // 	F(j, 0, comps[i].size()) {
    // 		cout<<comps[i][j]<<" ";
    // 	}
    // 	cout<<endl;z
    // }

    ll ans = 0;
    F(i, 0, comps[0].size() + 2) {
    	ans = max(ans, solve(0, i, w));
    	cout<<endl<<endl;
    	// deb(ans);
    }
    cout<<ans;

    return 0;
}/*

*/
