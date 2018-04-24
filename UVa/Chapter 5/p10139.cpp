#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define SIEVELIM 50000+10
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

bool solve(ll n,ll m){
	ll pf_index=0;
	ll pf = primes[pf_index];

	while(pf*pf<=m){
		if (m%pf==0)
		{
			int counter=0,cnt2=0;
			while(m%pf == 0){m/=pf;counter++;}
			ll temp = pf;
			while(temp<=n){
				cnt2+=n/temp;
				temp*=pf;
			}
			if (cnt2<counter)
			{
				return false;
			}
		}
		
		pf = primes[++pf_index];
	}
	if (m!=1)
	{
		if (n<m)
		{
			return false;
		}
	}
	return true;
}

int main(){
	// std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	sieve();

	int n,m;

	while(cin>>n>>m){

		if (!solve(n,m)) 
            printf("%d does not divide %d!\n", m, n);
        else
            printf("%d divides %d!\n", m, n);
		
	}	

	return 0;
}
