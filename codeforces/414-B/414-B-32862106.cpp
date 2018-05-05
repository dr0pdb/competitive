#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 0x3f3f3f3f
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
ll leftChild(ll p ){return p<<1;}
ll rightChild(ll p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
const ll MOD = 1000000007;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define deb(x )     cerr << #x << " here "<< x; 
#define endl    "\n"
#define pb push_back
#define mp make_pair
#define all(cc) (cc).begin(),(cc).end()

template<typename T > void modulize(T & a, const T & b) { if (a >= b) { a %= b; } }
/*----------------------------------------------------------------------*/

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

 	int n,k;
 	cin>>n>>k;

 	const int N = 2010;

 	//dp[i][j] no of sequences of len i which ends with j
 	int dp[N][N];

 	//for length = 1, number = 1
 	F(i, 0, N){
 		dp[1][i] = 1;
 	}

 	F(i, 1, k){
 		F(j, 1, n+1){
 			for (int k = j; k <=n; k+=j)
 			{
 				dp[i+1][j] += dp[i][k];
 				modulize(dp[i+1][j],(int)MOD);
 			}
 		}
 	}

 	int ans = 0;
 	F(i, 1, n+1){
 		ans += dp[k][i];
 		modulize(ans, (int)MOD);
 	}
 	cout<<ans;
    return 0;       
}