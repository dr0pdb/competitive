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

int n;
int arr[3][6];
bool used[1000]={false};	

void solve2(int a,int b){
	F(i, 0, 6){
		int num = 10*arr[a][i];
		F(j, 0, 6){
			num += arr[b][j];
			used[num] = true;
			num -= arr[b][j];
		}	
	}
}

void solve3(int a,int b,int c){
	
	F(i, 0, 6){
		int num = 100*arr[a][i];
		F(j, 0, 6){
			num += 10*arr[b][j];
			F(k, 0, 6){
				num += arr[c][k];
				used[num] = true;
				num -= arr[c][k];
			}
			num -= 10*arr[b][j];
		}	
	}
}

void solve1(int a){
	F(i, 0, 6){
		int num = arr[a][i];
		used[num] = true;
	}
}

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	cin>>n;

 	F(i, 0, n){
 		F(j, 0, 6){
 			cin>>arr[i][j];
 		}
 	}

 	memset(used,false,sizeof(used));

	if (n==1)
	{
		solve1(0);
	}else if (n==2)
	{
		solve1(0);
		solve1(1);
		solve2(0,1);
		solve2(1,0);
	}else{
		solve1(0);
		solve1(1);
		solve1(2);
		solve2(0,1);
		solve2(1,0);
		solve2(1,2);
		solve2(2,1);
		solve2(0,2);
		solve2(2,0);
		solve3(0,1,2);
		solve3(0,2,1);
		solve3(1,0,2);
		solve3(1,2,0);
		solve3(2,0,1);
		solve3(2,1,0);
	}

	F(i, 1, 1000){
		if (!used[i])
		{
			cout<<i-1;
			return 0;
		}
	}

 	return 0;	
}