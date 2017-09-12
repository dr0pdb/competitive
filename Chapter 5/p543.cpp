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

ll _sieve_size;
bitset<1000005> bs;
vi primes;

void sieve(ll upperbound){
	_sieve_size =upperbound+1;
	bs.set();
	bs[0]=bs[1]=0;
	for (ll i = 2; i <= _sieve_size; ++i)
	{
		for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
		primes.push_back((int)i);
	}
}

bool isPrime(ll n){
	if (n<=_sieve_size)	
	{
		return bs[n];
	}
	F(i, 0, primes.size()){
		if (n%primes[i]==0)
		{
			return false;
		}
	}
	return true;
}

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
		
	sieve(1000004);
	int n;
	while(cin>>n && n){
		bool ans=false;
		
		F(i, 2, n){
			if (isPrime(i) && isPrime(n-i))
			{
				cout<<n<<" = ";
				cout<<i<<" + "<<(n-i)<<"\n";
				ans=true;
				break;
			}
		}
		if (!ans)
		{
			cout<<"‘Goldbach's conjecture is wrong.\n";
		}
	}

	return 0;
}