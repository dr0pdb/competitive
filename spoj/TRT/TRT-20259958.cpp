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
inline ll mid(ll l, ll r){ return (l+r)/2;}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int leftChild(int p ){return p<<1;}
int rightChild(int p ){return (p<<1)+1;}
/*----------------------------------------------------------------------*/

int n;
ll values[2000+10],answer = -INF;
ll dp[2000+10][2000+10];

ll age(int left,int right){
	return left + n - right;
}


ll solve(int left, int right){
	// printf("left - %d right - %d profit - %lld\n", left,right,profit);
	
	if (left>right)
	{
		return 0;
	}

	if (dp[left][right] != -1)
	{
		return dp[left][right];
	}
	ll ages = age(left,right);
	return dp[left][right] = max(
		solve(left+1,right)+ages*values[left],
		solve(left,right-1)+ages*values[right]);
}

int main(){
 	// std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	n = nextint();
	memset(dp,-1,sizeof(dp));
	F(i, 0, n){
		values[i]= nextll();
	}

	cout<<solve(0,n-1)<<"\n";
	

	return 0;
}