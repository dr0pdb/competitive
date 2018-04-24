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

int n,k;
bool ansFound;
int matrix[80][80];
bool visited[80][80];
ll dp[80][80][8];

bool valid(ii a){
	return a.first>=1 && a.first<=n && a.second>=1 && a.second<=n; 
}

ll solve(ii curr, int negleft){
	if (!valid(curr))
	{
		return -INF;
	}
	// printf("curr.first == %d curr.second == %d negleft == %d\n", curr.first,curr.second,negleft);
	if (dp[curr.first][curr.second][negleft] != -1)
	{
		return dp[curr.first][curr.second][negleft];
	}

	if (curr==ii(n,n))
	{
		ansFound = true;
		return matrix[n][n];
	}
	visited[curr.first][curr.second] = true;
	ll ans = 0;
	ii left = ii(curr.first,curr.second-1);
	// printf("In the left recursion of (%d,%d)\n",curr.first,curr.second);
	if (valid(left) && !visited[left.first][left.second])
	{
		if (negleft && matrix[left.first][left.second]<0)
		{
			ans = solve(left,negleft-1);
		}else if(matrix[left.first][left.second]>=0){
			ans = solve(left,negleft);
		}
				
	}
	// printf("OUT the left recursion of (%d,%d)\n",curr.first,curr.second);
	ii right = ii(curr.first,curr.second+1);
	// printf("In the right recursion of (%d,%d)\n",curr.first,curr.second);
	if (valid(right) && !visited[right.first][right.second])
	{
		if (negleft && matrix[right.first][right.second]<0)
		{
			ans = max(ans,solve(right,negleft-1));
		}else if(matrix[right.first][right.second]>=0){
			ans = max(ans,solve(right,negleft));
		}
				
	}	
	// printf("out the right recursion of (%d,%d)\n",curr.first,curr.second);
	ii top = ii(curr.first+1,curr.second);
	// printf("In the top recursion of (%d,%d)\n",curr.first,curr.second);
	if (valid(top) && !visited[top.first][top.second])
	{
		if (negleft && matrix[top.first][top.second]<0)
		{
			ans = max(ans,solve(top,negleft-1));
		}else if(matrix[top.first][top.second]>=0){
			ans = max(ans,solve(top,negleft));
		}				
	}
// printf("out of the top recursion of (%d,%d)\n",curr.first,curr.second);
	ans+=matrix[curr.first][curr.second];
	visited[curr.first][curr.second]=false;
	// printf("the total value to reach %d %d with %d negleft is %d\n", curr.first,curr.second,negleft,ans);
	return dp[curr.first][curr.second][negleft] = ans;
}

int main(){
 	// std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

 	int tn = 1;
 	while(cin>>n>>k && (n+k)){
 		ansFound = false;
 		memset(dp,-1,sizeof(dp));
 		memset(visited,false,sizeof(visited));

 		F(i, 1, n+1){
 			F(j, 1, n+1){
 				cin>>matrix[i][j];
 			}
 		}
 		cout<<"Case "<<tn++<<": ";
 		ll ans = (matrix[1][1]<0)? solve(ii(1,1),k-1) : solve(ii(1,1),k);
 		if (!ansFound)
 		{
 			cout<<"impossible";
 		}else{
 			cout<<ans;
 		}
 		cout<<"\n";
 	}

	return 0;
}

