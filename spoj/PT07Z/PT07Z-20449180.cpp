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

const int N = 10000+10;
vi adjlist[N];
int dist[N];
bool visited[N]={false};
int maxvertex,maxdist=-1;

void dfs(int curr){
	visited[curr]=true;

	F(i, 0, adjlist[curr].size()){
		int next = adjlist[curr][i];
		if (!visited[next])
		{
			dist[next] = dist[curr]+1;
			if (dist[next]>maxdist)
			{
				maxdist = dist[next];
				maxvertex = next;
			}

			dfs(next);
		}
	}
}

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

 	int n;
 	cin>>n;

 	int from,to;

 	F(i, 0, n-1){
 		cin>>from>>to;
 		from--;
 		to--;
 		adjlist[from].push_back(to);
 		adjlist[to].push_back(from);
 	}
 	dist[0]=0;
 	dfs(0);

 	memset(dist,0,sizeof(dist));
 	memset(visited, false, sizeof(visited));

 	maxdist =-1;
 	dfs(maxvertex);

 	cout<<maxdist;

	return 0;
}