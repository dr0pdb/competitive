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

#define LIM 1000000+10
#define MODULO 10000000
vll primes;
int maxFound=0;
bitset<SIEVELIM+10> bs;
ll dp[LIM];

void sieve(){
	bs.set();
	bs[0]=0;
	bs[1]=0;

	for (ll i = 2; i < SIEVELIM; i++){
		if (bs[i])
		{
			for (ll j = i*i; j < SIEVELIM; j+=i)
			{
				bs[j]=0;
			}
			primes.push_back((int)i);
		}
	}
}

vii findFactors(ll n){
	vii factors;
	ll pf_index=0;
	ll pf = primes[pf_index];

	while(pf*pf<=n){
		
		int counter=0;
		while(n%pf == 0){n/=pf;counter++;}
		if (counter)
		{
			factors.push_back(ii(pf,counter));
		}
		
		pf = primes[++pf_index];
	}
	if (n!=1)
	{
		factors.push_back(ii(n,1));
	}
	return factors;
}

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	sieve();
	fill(dp,dp+LIM,1);
	map<int, int> counter;
	ll n;
	
	while(cin>>n && n){
		if (n<=maxFound)
		{
			cout<<dp[n]%10<<"\n";
			continue;
		}

		F(i, maxFound+1, n+1){
			vii pfact = findFactors(i);
			F(j, 0, pfact.size()){
				ii curr = pfact[j];
				if (counter.find(curr.first) != counter.end())
				{
					if (curr.second>counter[curr.first])
					{
						dp[i]=dp[i-1]*(ll)pow(curr.first,curr.second-counter[curr.first]);
						counter[curr.first]=curr.second;
					}else{
						dp[i]=dp[i-1];
					}
				}else{
					counter[curr.first]=curr.second;
					dp[i]=dp[i-1]*(ll)pow(curr.first,curr.second);
				}
				while(dp[i]%10==0){
					dp[i]/=10;
				}
				dp[i]%=MODULO;
			}
		}
		cout<<dp[n]%10<<"\n";
		maxFound = n;
	}
	
	return 0;
}