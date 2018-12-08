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

int p[110],sizes[110];

//if it is the representative then return itself otherwise return parent of it's immediate parent
int findSet(int i){
	return (p[i]==i)? i : p[i]=findSet(p[i]);
}

bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);
}

void join(int i, int j){
	if (!isSameSet(i,j))
	{
		int x = findSet(i),y = findSet(j);
		if(sizes[x] < sizes[y]){
			p[x] = y;
			sizes[y]+=sizes[x];	
		}else{
			p[y] = x;
			sizes[x]+=sizes[y];
		}
	}
}


int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

 	int n,x,y;
 	cin>>n;

 	vii points(n);
 	F(i, 0, n){
 		cin>>x>>y;
 		points[i].first = x;
 		points[i].second = y;
 	}

 	F(i, 0, n){
 		p[i] = i;
 		sizes[i] = 0;
 	}

 	F(i, 0, n){
 		F(j, i+1, n){
 			if ((points[i].first == points[j].first) || (points[i].second == points[j].second))
 			{
 				join(i,j);
 			}
 		}
 	}

 	int cc = 0;
 	F(i, 0, n){
 		if (findSet(i)==i)
 		{
 			cc++;
 		}
 	}
 	cout<<cc-1;
 	return 0;
}