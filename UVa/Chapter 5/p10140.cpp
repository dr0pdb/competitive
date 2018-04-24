#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define MOD 1000000000+7
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

#define sz 1000000
bitset<sz> bs;
std::vector<ll> primes;

void sieve(ll n){
	bs.set();
	bs[0]=0;
	bs[1]=0;

	for(ll i=2;i<=n;i++){
		if (bs[i])
		{	
			primes.push_back(i);
			for (ll j = i*i; j <= n; j+=i)
			{
				bs[j]=0;

			}
		}
	}
}

bool isPrime(ll n){
	if (n<=sz)	
	{
		return bs[n];
	}
	ll range = sqrt(n);
	for(ll i=0;i<primes.size();i++){
		if (primes[i]>range)
		{
			return true;
		}
		if (n%primes[i]==0)
		{
			return false;
		}
	}
	return true;
}
int main(){
	//std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	sieve(sz);
	ll l,u;

	while(scanf("%lld %lld",&l,&u)==2){
		if (u-l<=1)
		{
			
		}
		ll minm=-1,maxm=-1;
		pair<ll,ll> minset=make_pair(-1,-1),maxset=make_pair(-1,-1);
		
		ll lastPrime=-1;
		for (ll i = l; i <=u; ++i)
		{
			if (isPrime(i))
			{
				if (lastPrime!=-1)
				{
					if ( minm==-1 ||minm> i-lastPrime)
					{
						minm = (i-lastPrime);
						minset = make_pair(lastPrime,i);
					}
					if (maxm==-1 || maxm<i-lastPrime)
					{
						maxm = i-lastPrime;
						maxset = make_pair(lastPrime, i);
					}

				}
				lastPrime=i;
			}
		}

		if (minm==-1)
		{
			cout<<"There are no adjacent primes.\n";
		}else{
			//cout<<minset.first<<","<<minset.second<<" are closest, "<<maxset.first<<","<<maxset.second<<" are most distant.\n";
			printf("%lld,%lld are closest, %lld,%lld are most distant.\n",
                minset.first, minset.second, maxset.first, maxset.second);
		}

	}

	return 0;
}