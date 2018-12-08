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

int n,m,k;
bool visited[510][510];
char graph[510][510];
int sofar,s=0;
int dir[2][4] = { {1,0,-1,0},{0,1,0,-1}};

bool check(int i,int j){
	return (i>=0 && i<n && j>=0 && j<m);
}

void dfs(int i, int j){
	visited[i][j] = true;

	if (sofar>(s-k))
	{
		graph[i][j] = 'X';
	}

	sofar++;

	F(it, 0, 4){
		int x = i + dir[0][it], y = j + dir[1][it];

		if (!check(x,y))
		{
			continue;
		}

		if (graph[x][y] == '#')
		{
			continue;
		}

		if (!visited[x][y])
		{
			dfs(x,y);
		}
	}
}

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

 	cin>>n>>m>>k;	

 	memset(visited,false,sizeof(visited));

 	int start[2];
 	F(i, 0, n){
 		F(j, 0, m){
 			cin>>graph[i][j];
			if (graph[i][j]=='.')
 			{
 				start[0] = i;
 				start[1] = j;
 				s++;
 			}
 		}
 	}
 	sofar = 1;
 	dfs(start[0],start[1]);

 	F(i, 0, n){
 		F(j, 0, m){
 			cout<<graph[i][j];
 		}
 		cout<<endline;
 	}

 	return 0;
}