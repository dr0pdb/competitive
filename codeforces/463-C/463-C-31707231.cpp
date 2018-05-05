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
typedef pair<ll,ll> pll;
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
inline double nextdouble(){double temporary; scanf("%lf",&temporary); return temporary;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
int leftChild(int p ){return p<<1;}
int rightChild(int p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
/*----------------------------------------------------------------------*/

pll v[2];
ll s[2];
const ll N = 2010;
ll diag1[2*N]={0},diag2[2*N]={0};

void solve(const ll odd, ll x, ll y, ll sum){
	if (s[odd]<sum)
	{
		s[odd] = sum;
		v[odd].first = x;
		v[odd].second = y;
	}
}

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	int n;
	cin>>n;

	ll arr[n+1][n+1];
	F(i, 1, n+1){
		F(j, 1, n+1){
			cin>>arr[i][j];
			diag1[i+j] += arr[i][j];
			diag2[i-j+n] += arr[i][j];
		}
	}

	s[0]=-1,s[1]=-1;

	F(i, 1, n+1){
		F(j, 1, n+1){
			solve((i+j)&1,i,j,diag1[i+j]+diag2[i-j+n]-arr[i][j]);
		}
	}

	cout<<s[0]+s[1]<<endl;
	cout<<v[0].first<<" "<<v[0].second<<" "<<v[1].first<<" "<<v[1].second;
	return 0;
}