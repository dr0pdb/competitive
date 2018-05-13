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

vi adjlist[200+10];
int N;
bool visited[200+10];
int indeg[200+10];

void dfs(int curr){
	visited[curr]=true;
	
	F(i, 0, adjlist[curr].size()){
		int v = adjlist[curr][i];
		if (!visited[v])
		{
			dfs(v);
		}
	}
}

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	int r;
	while(cin>>N>>r){
		F(i, 0, N){
			adjlist[i].clear();
			indeg[i]=0;
			visited[i]=true;
		}
		// memset(visited,false,sizeof(visited));

		int u,v;
		F(i, 0, r){
			cin>>u>>v;
			
			adjlist[u].push_back(v);
			adjlist[v].push_back(u);
			visited[u]=false;
			visited[v]=false;
			indeg[u]++;
			indeg[v]++;
		}

		//The idea is if all the indeg are even and the graph is connected then its possible.
		bool poss = true;
		F(i, 0, N){
			if (indeg[i]%2 == 1)
			{
				poss = false;
				break;
			}
		}

		//Weird check of r==0 :(
		if (!poss || r==0)
		{
			cout<<"Not Possible\n";
			continue;
		}

		int cc = 0;
		F(i, 0, N){
			if (!visited[i])
			{
				dfs(i);
				cc++;
				if (cc>1)
				{
					poss = false;
					break;
				}
			}
		}

		if (poss)
		{
			cout<<"Possible\n";
		}else{
			cout<<"Not Possible\n";
		}
	}
	

	return 0;
}

