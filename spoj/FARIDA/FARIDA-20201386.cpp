#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
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
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	ll t,n;
	cin>>t;

	F(tn, 1, t+1){
		cin>>n;
		if (n==0)
		{
			cout<<"Case "<<tn<<": "<<0<<"\n";
			continue;
		}
		ll arr[n];
		F(i, 0, n){
			cin>>arr[i];
		}

		ll dp[n];
		memset(dp,-1,sizeof(dp));
		dp[0]=arr[0];
		if (n>1)
		{
			dp[1]=arr[1];	
		}	

		F(i, 2, n){
			dp[i]=dp[i-2]+arr[i];
			if (i>2)
			{
				dp[i] = max(dp[i],dp[i-3]+arr[i]);	
			}
		}
		ll ans = dp[n-1];
		if (n>1)
		{
			ans = max(ans,dp[n-2]);
		}
		cout<<"Case "<<tn<<": "<<ans<<"\n";
	}
	return 0;
}