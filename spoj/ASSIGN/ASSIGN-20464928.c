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

ll dp[22][1048580];
char matrix[22][22];
int t,n;

ll solve(int curr,ll mask){
	if (curr==n)
	{
		return 1;
	}

	if (dp[curr][mask] != -1)
	{
		return dp[curr][mask];
	}

	ll res = 0;
	F(i, 0, n){
		if (matrix[curr][i] == '1' && !(mask & (1<<i)))
		{
			int changed = mask | (1<<i);
			res += solve(curr+1,changed);
		}
	}
	return dp[curr][mask] = res;
}

int main(){
 	// std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

 	t = nextint();

 	while(t--){
 		n = nextint();

 		F(i, 0, n){
 			F(j, 0, n){
 				scanf(" %c",&matrix[i][j]);
 				// cin>>matrix[i][j];
 			}
 		}

 		memset(dp,-1,sizeof(dp));

 		ll ans = 0;
 		F(i, 0, n){
 			if (matrix[0][i]=='1')
 			{
 				ans += solve(1,1<<i);
 			}
 		}
 		cout<<ans<<"\n";
 	}

 	return 0;
}