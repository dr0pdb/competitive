#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define SIEVELIM 1000000+10
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

ll minCoins(ll coins[], ll n){

	ll dp[n+1];

	dp[0]=0;

	F(i, 1, n+1){
		dp[i]=INF;
	}

	F(i, 1, n+1){

		F(j, 1, 110){
			if (coins[j]<=i)
			{
				dp[i] = min(dp[i],1 + dp[i-coins[j]]);
			}
		}

	}
	return dp[n];
}

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	ll t,n;
	ll coins[110];
	F(i, 1, 110){
		coins[i]=(ll)i*i;
	}

	cin>>t;

	F(tn, 1, t+1){
		cin>>n;
		ll ans = minCoins(coins,n);
		cout<<"Case #"<<tn<<": "<<ans<<"\n";
	}

	return 0;
}