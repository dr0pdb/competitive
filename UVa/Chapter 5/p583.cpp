#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define SIEVELIM 10000000
#define MOD 1000000000+7
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

vi primes;
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

vi primeFactors(ll N) {

	vi factors;
	ll PF_idx = 0, PF = primes[PF_idx];
	while (PF * PF <= N) {
		while (N % PF == 0) { N /= PF; factors.push_back(PF); }
		PF = primes[++PF_idx];
	}
	if (N != 1) factors.push_back(N);
	return factors;
}

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	sieve();
	ll n;
	while(cin>>n && n){
		bool neg = false;
		if (n<0)
		{
			n*=-1;
			neg = true;
		}
		if (neg)
		{
			cout<<"-";	
		}
		cout<<n<<" = ";
		if (neg)
		{
			cout<<"-1 x ";
		}
		if (n<SIEVELIM && bs[n]==1)
		{	
			cout<<n<<"\n";
		}else{
			vi fac = primeFactors(n);
			cout<<fac[0];
			F(i, 1, fac.size()){
				cout<<" x "<<fac[i];
			}
			cout<<"\n";
		}
	}
	
	return 0;
}