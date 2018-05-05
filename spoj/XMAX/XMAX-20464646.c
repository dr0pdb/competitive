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
/*----------------------------------------------------------------------*/

int len(ull n){
	int ret = 0;

	while(n){
		ret ++;
		n >>= 1;
	}
	return ret;
}

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

 	int n;
 	cin>>n;

 	ull arr[n];
 	F(i, 0, n){
 		cin>>arr[i];
 	}

 	sort(arr,arr+n,greater<ull>());	

 	vector<ull> buckets[65];
 	ull modified[n],mod_index=0;

 	F(i, 0, n){
 		int leng = len(arr[i]);
 		buckets[leng].push_back(arr[i]);
 	}

 	RF(i, 64, 1){
 		if (buckets[i].size())	
 		{
 			modified[mod_index++] = buckets[i][0];

 			F(j, 1, buckets[i].size()){
 				buckets[i][j]^= buckets[i][0];
 				int leng = len(buckets[i][j]);
 				buckets[leng].push_back(buckets[i][j]);
 			}
 		}
 	}

 	ull res = 0;
 	F(i, 0, mod_index){
 		if ((res^modified[i]) > res)
 		{
 			res ^= modified[i];
 		}
 	}

 	cout<<res;

 	return 0;
}