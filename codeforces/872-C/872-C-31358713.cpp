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
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
inline double nextdouble(){double temporary; scanf("%lf",&temporary); return temporary;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
int leftChild(int p ){return p<<1;}
int rightChild(int p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
/*----------------------------------------------------------------------*/

int base[12];
 	
int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

 	memset(base,-1,sizeof(base));

 	base[0]=0;
 	base[4]=1;
 	base[6]=1;
 	base[8]=2;
 	base[9]=1;
 	base[10]=2;

 	ll q,n;
 	cin>>q;

 	while(q--){
 		cin>>n;
 		if (n>11)
 		{
 			ll ans = 0;
 			if (n%4==0)
 			{	
 				int fact = n/4;
 				ans+=fact;
 			}else if(n%2==0){
 				ans+=1;
 				n-=6;
 				int fact = n/4;
 				ans+=fact;
 			}else{
 				ans+=1;
 				n-=9;
 				if (n%4==0)
	 			{	
	 				int fact = n/4;
	 				ans+=fact;
	 			}else if(n%2==0){
	 				ans+=1;
	 				n-=6;
	 				int fact = n/4;
	 				ans+=fact;
	 			}
 			}
 			cout<<ans<<"\n";
 			continue;
 		}
 		ll ans=base[n];
 		cout<<ans<<"\n";
 	}
	return 0;
}