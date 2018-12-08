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
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
inline double nextdouble(){double temporary; scanf("%lf",&temporary); return temporary;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
int leftChild(int p ){return p<<1;}
int rightChild(int p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
/*----------------------------------------------------------------------*/

const int N = 200000+10;
int n,ans=-1;
vi adjlist[N];
bool visited[N];
int color[N];

void dfs(int u,int parent){
	visited[u]=true;

	int n1 = color[u];
	int n2 = n1;
	if (parent!=-1)
	{
		n2 = color[parent];
	}
	int col = 0;

	F(i, 0, adjlist[u].size()){
		
		int curr = adjlist[u][i];

		if (!visited[curr])		
		{
			col++;
			while(col==n1 || col==n2){
				col++;
			}
			ans = max(ans,col);
			color[curr]= col;
			dfs(curr,u);
		}		
		
	}
}

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	memset(visited,false,sizeof(visited));
	memset(color, -1, sizeof(color));

	int u,v;
	F(i, 0, n-1){
		cin>>u>>v;
		u--;v--;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}

	color[0]=1;
	dfs(0,-1);

	cout<<ans<<"\n";
	F(i, 0, n){
		if (i)
		{
			cout<<" ";
		}
		cout<<color[i];
	}
 	return 0;
}