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
	int t;
	cin>>t;

	while(t--){
		
		int a,c;
		cin>>a>>c;
		vii afac = findFactors(a);
		vii cfac = findFactors(c);
		bool usedc[cfac.size()];
		bool useda[afac.size()];
		memset(useda,false,sizeof(useda));
		memset(usedc,false,sizeof(usedc));
		bool hasSol=true;
		ll b =1;
		
		F(i, 0, afac.size()){
			F(j, 0, cfac.size()){
				ii cura = afac[i];
				ii curc = cfac[j];
				if (cura.first == curc.first)
				{	usedc[j]=true;
					useda[i]=true;
					if (curc.second<cura.second)
					{
						hasSol=false;
						break;
					}else{
						if (curc.second>cura.second)
						{
							b*=(ll)pow(cura.first,curc.second);
						}
					}
				}
			}		
			if (!hasSol)
			{
				break;
			}
		}

		F(j, 0, cfac.size()){
			if (!hasSol)
			{
				break;
			}
			if (usedc[j]==false)
			{
				b*=(ll)pow(cfac[j].first,cfac[j].second);
			}
		}
		F(i, 0, afac.size()){
			if (!hasSol)
			{
				break;
			}
			if (!useda[i])
			{
				hasSol=false;
				break;
			}
		}
		if (!hasSol || b>c)
		{
			cout<<"NO SOLUTION\n";
			continue;
		}else{
			cout<<b<<"\n";
		}

	}
	
	return 0;
}