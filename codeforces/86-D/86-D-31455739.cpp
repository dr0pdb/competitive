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

#define A 1111111
#define N 200050
#define BOX_SIZE 450 

struct query
{
	ll l,r,index;
}queries[N];

ll counter[A],arr[N],ans[N],answer=0;

bool cmp(query a, query b){
	if (a.l/BOX_SIZE != b.l/BOX_SIZE)
	{
		return a.l/BOX_SIZE < b.l/BOX_SIZE;
	}

	return a.r<b.r;
}

void add(ll index){
	counter[arr[index]]++;
	answer+= arr[index]*(2*counter[arr[index]]-1);
}

void remove(ll index){
	answer-= arr[index]*(2*counter[arr[index]]-1);
	counter[arr[index]]--;
}

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

 	ll n,q;
 	cin>>n>>q;

 	memset(counter,0,sizeof(counter));

 	F(i, 0, n){
 		cin>>arr[i];
 	}

 	ll l,r;
 	F(i, 0, q){
 		cin>>l;cin>>r;
 		l--;
 		r--;
 		queries[i].l = l;
 		queries[i].r = r;
 		queries[i].index = i;
 	}

 	sort(queries,queries+q,cmp);

 	ll start = 0 ,end = 0;

 	F(i, 0, q){
 		int l = queries[i].l;
 		int r = queries[i].r;

 		while(start<l){
 			remove(start);
 			start++;
 		}

 		while(start>l){
 			add(start-1);
 			start--;
 		}

 		while(end>r+1){
 			remove(end-1);
 			end--;
 		}

 		while(end<=r){
 			add(end);
 			end++;
 		}
 		ans[queries[i].index]=answer;
 	}

 	F(i, 0, q){
 		cout<<ans[i]<<"\n";
 	}

	return 0;
}