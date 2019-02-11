#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define SIEVELIM 10000000+10
#define EPS 1e-7
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
inline double nextdouble(){double temporary; scanf("%lf",&temporary); return temporary;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
int leftChild(int p ){return p<<1;}
int rightChild(int p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
const ll MOD = 1000000007;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define deb(x )		cerr << #x << " here "<< x; 
#define endline		"\n"
#define pb push_back
#define mp make_pair
/*----------------------------------------------------------------------*/

bool cmp(ii a, ii b){
	return (abs(a.first)+abs(a.second))<(abs(b.first)+abs(b.second));
}

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

 	int n;
 	cin>>n;

 	ll ans = 0;
 	vii pairs(n);
 	int x,y;
 	F(i, 0, n){
 		cin>>x>>y;
 		pairs[i] = ii(x,y);
 		if (x && y)
 		{
 			ans+=6;
 		}else if (x || y)
 		{
 			ans+=4;
 		}
 	}

 	sort(pairs.begin(),pairs.end(),cmp);
 	cout<<ans<<endline;

 	F(i, 0, pairs.size()){
 		ii curr = pairs[i];
 		
 		if (curr.first)
 		{
 			char dir = 'R'; if (curr.first<0)
			{
				dir = 'L';
			}
 			cout<<1<<" "<<abs(curr.first)<<" "<<dir<<endline;
 		}

 		if (curr.second)
 		{
 			char dir = 'U';if(curr.second<0) dir = 'D';
 			cout<<1<<" "<<abs(curr.second)<<" "<<dir<<endline;
 		}

 		cout<<2<<endline;
 		if (curr.first)
 		{
 			char dir = 'L'; if (curr.first<0)
			{
				dir = 'R';
			}
 			cout<<1<<" "<<abs(curr.first)<<" "<<dir<<endline;
 		}

 		if (curr.second)
 		{
 			char dir = 'D';if(curr.second<0) dir = 'U';
 			cout<<1<<" "<<abs(curr.second)<<" "<<dir<<endline;
 		}
 		cout<<3<<endline;
 	}

 	return 0;
}