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

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

 	int n,m;
 	cin>>n>>m;

 	int p[n],q[m];
 	int m1=INF,m2=INF,ans;
 	bool presp[10],presq[10];
 	memset(presp,false,sizeof(presp));
 	memset(presq,false,sizeof(presq));

 	F(i, 0, n){
 		cin>>p[i];
 		presp[p[i]]=true;
 		m1 = min(m1,p[i]);
 	}
 	F(i, 0, m){
 		cin>>q[i];
 		presq[q[i]]=true;
 		m2 = min(m2,q[i]);
 	}

 	int a = min(m1,m2);
 	int b = max(m1,m2);

 	if (a!=b)	
 	{
 		bool flag = false;
 		F(j, 1, 10){
 			if (presq[j] && presp[j])
 			{
 				flag = true;
 				ans = j;
 				break;
 			}
 		}

 		if (!flag)
 		{
 			ans = a*10+b;
 		}
 	}else{
 		ans = a;
 	}
 	
 	cout<<ans;
	return 0;
}