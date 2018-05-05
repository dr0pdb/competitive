#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

double dp[600][2000];

double solve(int n,int k){

	if (n>545 || k>1908)
	{
		return 0.0;
	}
	
	if (k<n || k> 6*n)
	{
		return 0.0;
	}

	if (n==1)
	{
		return dp[n][k]=1.0/6; 
	}
    
	if (dp[n][k]>=0.0)
	{	
		return dp[n][k];
	}

	return dp[n][k] = (solve(n-1,k-1)+ solve(n-1,k-2)+solve(n-1,k-3)+solve(n-1,k-4)+ solve(n-1,k-5) + solve(n-1,k-6))/6;
}

int main(){
	//std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	memset(dp,-1.0,sizeof(dp));
	int t,n,k;

	cin>>t;

	while(t--){
		cin>>n>>k;
		double ans = solve(n,k);
		ans*=100;
		printf("%d\n",(int)ans);
	}
	return 0;
}