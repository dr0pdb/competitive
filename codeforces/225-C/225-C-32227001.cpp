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
int leftChild(int p ){return p<<1;}
int rightChild(int p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
const ll MOD = 1000000007;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define deb(x )     cerr << #x << " here "<< x; 
#define endl    "\n"
#define pb push_back
#define mp make_pair
/*----------------------------------------------------------------------*/

int n,m,x,y;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m>>x>>y;

    vi sumw(m+1,0),sumb(m+1,0);
    char mat[n][m];

    F(i, 0, n){
        F(j, 0, m){
            cin>>mat[i][j];
        }
    }

    F(j, 1, m+1){
    	int b=0,w=0;
    	F(i, 0, n){
    		if (mat[i][j-1]=='.')
    		{
    			w++;
    		}else{
    			b++;
    		}
    	}
    	sumw[j] = sumw[j-1]+w;
    	sumb[j] = sumb[j-1]+b;
    }

    int dp[2][m+1];
    memset(dp,INF,sizeof(dp));

    dp[0][0] = dp[1][0] = 0;
    F(i, x, m+1){
    	F(j, x, min((ll)y,i)+1){
    		dp[0][i] = min(dp[0][i], dp[1][i-j]+sumw[i]-sumw[i-j]) ;
    		dp[1][i] = min(dp[1][i], dp[0][i-j]+sumb[i]-sumb[i-j]) ;
    	}
    }
    cout<<min(dp[0][m],dp[1][m]);
    return 0;       
}