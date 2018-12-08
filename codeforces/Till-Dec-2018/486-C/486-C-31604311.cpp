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

 	int n,p;
 	cin>>n>>p;

 	ll ans = 0;
 	string s;
 	cin>>s;

 	if (p>s.length()/2)
 	{
 		reverse(s.begin(), s.end());
 		p = n-p+1;
 	}

 	int l=-1,r=-1;
 	F(i, 0, s.length()/2){
 		if (s[i] != s[n-1-i])
 		{
 			r = i+1;
 			if (l==-1)
 			{
 				l = i+1;
 			}

 			ans += min(abs(s[i]-s[n-i-1]),26-abs(s[i]-s[n-i-1]));
 		}
 	}
      
 	if (l!=-1)
 	{
 		int minm ,maxm;
	 	minm = min(abs(p-l),abs(p-r));
	 	maxm = max(abs(p-l),abs(p-r));
	 	ans+=maxm;
	 	if (l<p && p<r)
	 	{
	 		ans+=2*minm;
	 	}
 	}
 	
 	cout<<ans;
	return 0;
}