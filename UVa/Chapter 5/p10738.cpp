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

ll numDiffPf[SIEVELIM];
ll mu[SIEVELIM];
bitset<SIEVELIM> bs;
ll dp[SIEVELIM];

void sieve(){
	memset(numDiffPf,0,sizeof(numDiffPf));
	bs.set();
	F(i, 2, SIEVELIM){
		if (numDiffPf[i]==0)
		{
			for (int j = i; j < SIEVELIM; j+=i)
			{
				numDiffPf[j]++;
				if (j>=(i*i) && j%(i*i)==0)
				{
					bs[j]=0;
				}
			}
		}

	}
}

int main(){
 	// std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	sieve();
	mu[1]=1;
	dp[1]=1;
	F(i, 2, SIEVELIM){
		if (bs[i]==0)
		{
			mu[i]=0;
		}else if (numDiffPf[i]%2==0)
		{
			mu[i]=1;
		}else{
			mu[i]=-1;
		}
		dp[i]=dp[i-1]+mu[i];
	}

	// F(i, 1, 21){
	// 	cout<<i<<"  "<<mu[i]<<"  "<<dp[i]<<endl;
	// }

	ll n;
	while(cin>>n && n){
		printf("%8lld%8lld%8lld\n",n,mu[n],dp[n]);
	}

	return 0;
}