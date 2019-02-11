#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
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
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int left(int p ){return p<<1;}
int right(int p ){return (p<<1)+1;}
/*----------------------------------------------------------------------*/

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	ll n,k;
	cin>>n>>k;

	ll a[n],b[n];
	ll sum=0;
	F(i, 0, n){
		cin>>a[i];
		sum+=a[i];
	}
	F(i, 0, n){
		cin>>b[i];
	}
	ll counter=0;
	ll minm = INF;
	F(i, 0, n){
		minm = min(minm,b[i]/a[i]);
	}
	counter+=minm;
	F(i, 0, n){
		b[i] -= (minm*a[i]);
	}
	minm = 1;
	while(k>0){
		ll req = 0;
		
		F(i, 0, n){
			if (b[i]>a[i])
			{
				b[i] -= a[i];
			}else{
				req+=a[i]-b[i];
				b[i]=0;
			}
			
		}
		k-=req;
		if (k>=0)
		{
			counter+=1;
		}

	}
	cout<<counter;
	return 0;
}