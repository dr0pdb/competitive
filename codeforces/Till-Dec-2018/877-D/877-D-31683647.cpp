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

int n,m,k;

bool check(int i,int j){
	return (i>=0 && j>=0 && i<n && j<m);
}

int dirx[4]={1,0,-1,0},diry[4]={0,1,0,-1};

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

 	cin>>n>>m>>k;

 	char graph[n][m];
 	int dist[n][m];
 	F(i, 0, n){
 		F(j, 0, m){
 			cin>>graph[i][j];
 			dist[i][j]= INF;
 		}
 	}

 	bool visited[n][m];
 	memset(visited,false,sizeof(visited));

 	int s[2],d[2];
 	cin>>s[0]>>s[1]>>d[0]>>d[1];

 	s[0]--,s[1]--;
 	d[0]--,d[1]--;

 	queue<ii> q;
 	dist[s[0]][s[1]]=0;
 	q.push(ii(s[0],s[1]));

 	while(!q.empty()){
 		ii curr = q.front();
 		q.pop();
 		visited[curr.first][curr.second] = true;

 		F(i, 0, 4){
 			int xdir = dirx[i],ydir = diry[i];

 			F(j, 1, k+1){
 				int newx = curr.first + (xdir*j);
 				int newy = curr.second + (ydir*j);

 				if (!check(newx,newy))
 				{
 					break;
 				}

 				if (graph[newx][newy] == '#' || dist[newx][newy] < dist[curr.first][curr.second]+1)
 				{
 					break;
 				}

 				if (!visited[newx][newy])
 				{
 					visited[newx][newy]=true;
 					dist[newx][newy]=dist[curr.first][curr.second]+1;
					q.push(ii(newx,newy));
 				}
 			}
 		}
 	}

 	if (dist[d[0]][d[1]] == INF)
 	{
 		cout<<-1;
 	}else{
 		cout<<dist[d[0]][d[1]];
 	}

	return 0;
}