#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define SIEVELIM 10000000+10
#define EPS 1e-7
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
inline double nextdouble(){double temporary; scanf("%lf",&temporary); return temporary;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
int leftChild(int p ){return p<<1;}
int rightChild(int p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
const ll MOD = 1000000007;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define deb(x )		cerr << #x << " here "<< x; 
#define endline		"\n"
#define pb push_back
#define mp make_pair
/*----------------------------------------------------------------------*/

const int N = 1e5+10;
ll cost[N];
vi adjlist[N];
vi dfs_num,s,dfs_low;
bool visited[N];
ll dfsNumberCounter=0;
ll ans = 1,minCost=0;
vi sccmincount;

void scc(ll u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++; 
	
	s.push_back(u);

	visited[u] = 1;
	for (ll j = 0; j < (ll)adjlist[u].size(); j++) {
		ll v = adjlist[u][j];
		if (dfs_num[v] == -1){
			scc(v);	
		}
		
		if (visited[v]){
			dfs_low[u] = min(dfs_low[u], dfs_low[v]); 
		}
	}
		
	if (dfs_low[u] == dfs_num[u]) {
		int minm = INF,minCount = 0;
		while (1) {
			int v = s.back(); s.pop_back(); visited[v] = 0;
			if (cost[v]==minm)
			{
				minCount++;
			}else if(cost[v]<minm){
				minm = cost[v];
				minCount=1;
			}
			if (u == v) break; 	
		}

		minCost += minm;
		sccmincount.push_back(minCount);	
	} 
}

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

 	int n;
 	cin>>n;

 	F(i, 0, n){
 		cin>>cost[i];
 	}
 	
 	int m,u,v;
 	cin>>m;

 	F(i, 0, m){
 		cin>>u>>v;
 		u--;
 		v--;
 		adjlist[u].push_back(v);
 	}

 	dfs_num.assign(N, -1);
 	dfs_low.assign(N, 0);
 	memset(visited, false, sizeof(visited));

	F(i, 0, n){
 		if (dfs_num[i] == -1)
 		{
 			scc(i);
 		}
 	}

 	F(i, 0, sccmincount.size()){
 		ans *= sccmincount[i];
 		ans %= 1000000007;
 	}
 	cout<<minCost<<" "<<ans;

 	return 0;	
}