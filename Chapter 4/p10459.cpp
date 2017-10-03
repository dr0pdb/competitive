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
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int leftChild(int p ){return p<<1;}
int rightChild(int p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
/*----------------------------------------------------------------------*/

vi adjlist[5000+10];
vi best,worst,dist;
int N,maxlen,maxsource;
vi endpoints(2);
bool visited[5000+10];

void dfs(int curr, int len){
	visited[curr]=true;
	dist[curr]=max(len,dist[curr]);

	if (len>maxlen)
	{
		maxsource=curr;
		maxlen = len;
	}

	F(i, 0, adjlist[curr].size()){
		int v = adjlist[curr][i];
		if (!visited[v])
		{
			dfs(v,len+1);
		}
	}
}

int main(){
 	// std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

 	while(cin>>N){
 		F(i, 0, N+1){
 			adjlist[i].clear();
 		}
 		best.clear();
 		worst.clear();
 		dist.assign(N+1, 0);

 		int u,v;
		F(i, 1, N+1){
			cin>>u;
			F(j, 0, u){
				v = nextint();
				adjlist[i].push_back(v);
				adjlist[v].push_back(i);
			}
		}

		maxlen = -INF,maxsource = -INF;
		memset(visited,false,sizeof(visited));

		dfs(1,0);

		endpoints[0]=maxsource;

		dist.assign(N+1, 0);
		maxlen = -INF,maxsource = -INF;
		memset(visited,false,sizeof(visited));

		// dist.assign(N+1, INF);
		dfs(endpoints[0],0);
		endpoints[1]=maxsource;

		// printf("%d -- %d\n",endpoints[0],endpoints[1]);
		// F(i, 1, N+1){
		// 	printf("Dist[%lld] - %d \n",i,dist[i]);
		// }

		memset(visited,false,sizeof(visited));
		dfs(endpoints[1],0);

		int maxm=-INF,minm=INF;
		F(i, 1, N+1){
			maxm = max(maxm,dist[i]);
			minm = min(minm,dist[i]);
		}

		F(i, 1, N+1){
			if (dist[i]==minm)
			{
				best.push_back(i);
			}
			if (dist[i]==maxm)
			{
				worst.push_back(i);
			}
		}

		printf("Best Roots  :");
		sort(best.begin(), best.end());
		F(i, 0, best.size()){
			printf(" %d",best[i]);
		}
		printf("\n");
		printf("Worst Roots :");
		sort(worst.begin(),worst.end());
		F(i, 0, worst.size()){
			printf(" %d",worst[i]);
		}
		printf("\n");
	}

	return 0;
}

