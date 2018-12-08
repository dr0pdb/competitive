#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define SIEVELIM 10000000+10
#define MOD 1000000000+7
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
/*----------------------------------------------------------------------*/

const int N = 100000+10;
vll adjlist[N],scc_values;
vll dfs_num,s,dfs_low,visited;
ll dfsNumberCounter=0;

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
		scc_values.push_back(s.size());
		s.clear();	
	} 
}

ll sq(ll a){
	return a*a;
}

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

 	ll n,to;
 	cin>>n;

 	F(i, 0, n){
 		cin>>to;
 		to--;
 		adjlist[i].push_back(to);
 	}

 	dfs_num.assign(N, -1);
 	dfs_low.assign(N, 0);
 	visited.assign(N, 0);

 	F(i, 0, n){
 		if (dfs_num[i] == -1)
 		{
 			scc(i);
 		}
 	}

 	sort(scc_values.begin(),scc_values.end(),greater<ll>());
 	ll ans = 0;
 	if (scc_values.size()==1)
 	{
 		cout<<sq(scc_values[0]);
 		return 0;
 	}
 	ans = sq(scc_values[0]+scc_values[1]);
 	F(i, 2, scc_values.size()){
 		ans += sq(scc_values[i]);
 	}
 	cout<<ans;
 	return 0;
}