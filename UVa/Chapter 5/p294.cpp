#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define SIEVELIM 100000+10
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

vll primes;
int maxFound=0;
bitset<SIEVELIM+10> bs;

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

ll findFactors(ll n){
	// vii factors;
	ll pf_index=0;
	ll ans=1;
	ll pf = primes[pf_index];

	while(pf*pf<=n){
		
		int counter=0;
		while(n%pf == 0){n/=pf;counter++;}
		if (counter)
		{
			ans*=(counter+1);
			// factors.push_back(ii(pf,counter));
		}
		
		pf = primes[++pf_index];
	}
	if (n!=1)
	{
		ans*=2;
		// factors.push_back(ii(n,1));
	}
	return ans;
}

int main(){
 	// std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	sieve();
	int t;
	cin>>t;

	while(t--){
		ll l,h;
		cin>>l>>h;
		ll maxdiv = -1,ans;
		for (ll	i = l; i <= h; ++i)
		{
			ll temp =findFactors(i);
			if (maxdiv<temp)
			{
				maxdiv = temp;
				ans= i;
			}
		}
		printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",l,h,ans,maxdiv);
	}
	
	return 0;
}